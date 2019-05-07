package com.example.koshizukalab_arduino

import android.app.PendingIntent
import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.content.IntentFilter
import android.hardware.usb.*
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.os.Handler
import android.util.Log
import android.view.View
import android.widget.*
import kotlinx.android.synthetic.main.activity_main.*
import kotlin.concurrent.thread
import android.os.Looper.getMainLooper
import android.os.Looper.getMainLooper





class MainActivity : AppCompatActivity(), View.OnClickListener {

    private var textView: TextView? = null
    private var logTextView: TextView? = null
    private var reloadButton: Button? = null
    private var connectButton: Button? = null
    private var sendButton: Button? = null
    private var typeSpinner: Spinner? = null
    private var conditionSpinner: Spinner? = null
    private var roomNumberET: EditText? = null

    private var usbManager: UsbManager? = null
    private var arduinoDevice: UsbDevice? = null
    private var connection: UsbDeviceConnection? = null
    private var permissionIntent: PendingIntent? = null

    private var endpointIN: UsbEndpoint? = null
    private var endpointOUT: UsbEndpoint? = null

    private val ARDUINO_USB_PERMISSION = "com.example.koshizukalab_arduino.ARDUINO_USB_PERMISSION"

    private val usbReceiver = object: BroadcastReceiver() {

        override fun onReceive(context: Context, intent: Intent) {
            if (ARDUINO_USB_PERMISSION == intent.action) {
                synchronized(this) {
                    val device: UsbDevice? = intent.getParcelableExtra(UsbManager.EXTRA_DEVICE)

                    if (intent.getBooleanExtra(UsbManager.EXTRA_PERMISSION_GRANTED, false)) {
                        device?.apply {
                            //call method to set up device communication
                            addLog("connection completed")

                            connection = usbManager!!.openDevice(arduinoDevice)

                            if(!connection!!.claimInterface(arduinoDevice?.getInterface(0),true)) {
                                connection!!.close()
                                return
                            }
                            if(!connection!!.claimInterface(arduinoDevice?.getInterface(1),true)) {
                                connection!!.close()
                                return
                            }

                            connection!!.controlTransfer(0x21, 34, 0, 0, null, 0, 0)
                            connection!!.controlTransfer(
                                0x21,
                                32,
                                0,
                                0,
                                byteArrayOf(0x80.toByte(), 0x25.toByte(), 0x00.toByte(), 0x00.toByte(), 0x00.toByte(), 0x00.toByte(), 0x08.toByte()),
                                7,
                                0
                            )

                            //var controlInterface = arduinoDevice.getInterface(0)
                            var dataInterface = arduinoDevice!!.getInterface(1)

                            for(tmp in 0..dataInterface.endpointCount - 1) {
                                val tmpEndpoint = dataInterface.getEndpoint(tmp)
                                if(tmpEndpoint.type == UsbConstants.USB_ENDPOINT_XFER_BULK) {
                                    if(tmpEndpoint.direction == UsbConstants.USB_DIR_IN) {
                                        endpointIN = tmpEndpoint
                                    } else{
                                        endpointOUT = tmpEndpoint
                                    }
                                }
                            }

                        }
                    } else {
                        addLog("connection failed")
                    }
                }
            }
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        usbManager = getSystemService(Context.USB_SERVICE) as UsbManager
        textView = findViewById(R.id.textView) as TextView
        logTextView = findViewById(R.id.logTextView) as TextView
        reloadButton = findViewById(R.id.reloadButton) as Button
        connectButton = findViewById(R.id.connectButton) as Button
        sendButton = findViewById(R.id.sendButton) as Button

        typeSpinner = findViewById(R.id.typeSpinner) as Spinner
        conditionSpinner = findViewById(R.id.conditionSpinner) as Spinner
        roomNumberET = findViewById(R.id.roomNumberET) as EditText


        reloadButton?.setOnClickListener(this)
        connectButton?.setOnClickListener(this)
        sendButton?.setOnClickListener(this)

        logTextView?.setText("")

        typeSpinner?.adapter = ArrayAdapter(applicationContext, android.R.layout.simple_spinner_item, Constants.types)
        conditionSpinner?.adapter = ArrayAdapter(applicationContext, android.R.layout.simple_spinner_item, Constants.conditions)


        permissionIntent = PendingIntent.getBroadcast(this,0,Intent(ARDUINO_USB_PERMISSION),0)
        var filter = IntentFilter(ARDUINO_USB_PERMISSION)
        registerReceiver(usbReceiver, filter)

        showDeviceList()
    }

    private fun addLog(s: String) {
        logTextView?.append("\n"+s)
        Log.d("TAGGGG",s)
        println(s)
    }

    private fun showDeviceList() {
        var deviceList = usbManager?.deviceList
        if(deviceList == null || deviceList.isEmpty()) {
            textView?.setText("no device")
            return
        }
        var str = ""
        for(name in deviceList.keys) {
            str += name + " " + deviceList[name]!!.vendorId
        }
        textView?.setText(str)
    }

    private fun connectDevice() {
        var deviceList = usbManager?.deviceList
        if(deviceList == null || deviceList.isEmpty()) {
            textView?.setText("no device")
            return
        }

        arduinoDevice = deviceList[deviceList.keys.first()]
        usbManager?.requestPermission(arduinoDevice, permissionIntent)
    }

    private fun sendData() {
        val type = typeSpinner?.selectedItem as String
        val condition = conditionSpinner?.selectedItem as String
        val roomNumber = Integer.parseInt(roomNumberET?.text.toString())

        var command = ""

        if(type == Constants.types[0]) {
            command += "0"
        } else {
            command += "1"
        }
        if(condition == Constants.conditions[0]) {
            command += "1"
        } else {
            command += "0"
        }

        command += roomNumber
        //command += ";"

        addLog(type + "  " + condition + "  " + roomNumber)
        addLog(command)

        thread {
            connection!!.bulkTransfer(endpointOUT, "01".toByteArray(), "01".toByteArray().size, 0);
        }
    }

    override fun onClick(v: View?){
        when(v?.id) {
            R.id.reloadButton -> {
                this.showDeviceList()
            }
            R.id.connectButton -> {
                this.connectDevice()
            }
            R.id.sendButton -> {
                this.sendData()
            }
        }
    }

}

