#!/bin/sh
sudo iwlist wlan0 scan | grep -e ESSID -e Quality