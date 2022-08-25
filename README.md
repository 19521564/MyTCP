# MyTCP
* Window

* Visual Studio

* C++
# RUN PROGRAMS
You need 2 command line and cd go to folder ```Release```

## Step 1:

* In command line 1, run: ```SendData <destination_address>```

Example: ```SendData 127.0.0.1```

* In command line 2, run: ```ReceiveData --out=<location_store_file>```

Example: ```ReceiveData --out=./```

## Step 2:

* If you want to send text, in command line 1, run: ```SendText <text>```

Example: ```SendText hello world!```

* If you want to send file, in command line 1, run: ```SendFile <path> <size>```

Example: ```SendFile C:/Users/DELL/Music/MyTCPSever/demo.txt 512```
