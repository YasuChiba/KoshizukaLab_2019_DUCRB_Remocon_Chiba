package com.example.koshizukalab_arduino

import android.content.Context
import android.hardware.usb.UsbDevice
import android.hardware.usb.UsbManager
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.TextView

class MainActivity : AppCompatActivity(), View.OnClickListener {

    private var textView: TextView? = null
    private var reloadButton: Button? =null
    private var usbManager: UsbManager? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        usbManager = getSystemService(Context.USB_SERVICE) as UsbManager
        textView = findViewById(R.id.textView) as TextView
        reloadButton = findViewById(R.id.reloadButton) as Button
        reloadButton?.setOnClickListener(this)

        showDeviceList()
    }


    private fun showDeviceList() {
        var deviceList = usbManager?.deviceList
        if(deviceList == null || deviceList.isEmpty()) {
            textView?.setText("no device")
            return
        }
        var str = ""
        for(name in deviceList!!.keys) {
            str += name + " " + deviceList[name]!!.vendorId
        }
        textView?.setText(str)
    }

    override fun onClick(v: View?) {
        this.showDeviceList()
    }

}

