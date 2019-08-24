This Project is an attempt to create a faster an efficient input mechanism
to make repetitive functions/commands easier to execute on any computer
that is able to run python and has a serial port

First, we need to build an basic keyboard as shown in the Build Folder
Then, we upload the 'button.ino' to the arduino and activate it

Then, if we have the 'data.acc' file prepared before hand and 
run the 'button.py' program on the host computer, we can easily execute
commands directly from the input source.

Commands are stored in the 'data.acc' file

To execute a command:
1. Run 'button.py' on the host computer
2. Wait for the screen to say "Access Ready"
3. Tap the LeftMost Button
4. Enter a Combination of the Three Rightmost buttons, one at a time
5. Tap the 2nd leftmost button for backspace
6. Tap the LeftMost Button to execute a command
7. Wait for the command to execute.
