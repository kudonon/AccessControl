import serial
import os
import time

run = False;
try:
    ser = serial.Serial('/dev/ttyACM0', 9600)
    run = True;
except:
    try:
        ser = serial.Serial('/dev/ttyACM1', 9600)
        run = True;
    except:
        try:
            ser = serial.Serial('/dev/cu.usbmodem14201', 9600)
            run = True;
        except:
            try:
                ser = serial.Serial('/dev/cu.usbmodem14202',9600)
                run = True;
            except:
                print("<?AController>: Error loading Serial Port")	

def switch(c):
    with open("data.acc", "r") as file:
        for i in file.readlines():
            if c == i[0] and i[0:2] != "//":
                print("<?AController>: Calling Function: " + i[2:])
                print("<?AController>: Logs:\n")
                os.system(i[2:])
                print("\n<?AController>: Process Completed\n")
                print("---NEW INSTANCE AController---");

def callFunction():
    print("<?AController>: Scanning Input...\n")
    choice = ser.read().decode('utf-8')
    print("<?AController>: Input is Code #" + str(ord(choice)) + "\n\n<?AController>: Validating Code...\n")
    switch(choice)

while (run):
    callFunction()
    time.sleep(3)
