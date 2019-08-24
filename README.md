This Project is an attempt to create a faster an efficient input mechanism
to make repetitive functions/commands easier to execute on any computer
that is able to run python and has a serial port.
Built with no direct use of low level lagnuages.

First, you need to build an basic keyboard using an Arduino as shown in 
the 'Build/' folder. Then, upload the 'button.ino' to the arduino and 
activate it

Commands are stored in the 'data.acc' file. They are stored with the following format
->      ASCII: unixcommand...
the ASCII character corresponds to the ternary number that the keyboard will input
from the mechanism. To customize, just change the command to the full unix command
of whatever you want.

Then, if we have the 'data.acc' file prepared before hand and run the 'button.py' 
program on the host computer, we can easily execute commands directly from the 
Arduino input source.

To execute a command:
1. Run 'button.py' on the host computer
2. Wait for the lcd display screen to say "Access Ready"
3. Tap the LeftMost Button
4. Enter a Combination of the Three Rightmost buttons, one at a time
5. Tap the 2nd leftmost button for backspace
6. Tap the LeftMost Button to execute a command
7. Wait for the command to execute.

In this example, typing the code 1021 should open Google Chrome 
and 1022 should open Google Chrome incognito.

This project is meant to provide a controller for computer, but can be extended
to other IoT devices and their respective function. It can also become a wireless
controller using the Arduino WiFi shield.
