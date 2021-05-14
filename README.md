# PS-2-Arduino-Interface
A program that allows you to type on a ps/2 keyboard and have what you type show up on a connected LCD screen.


Link to wiring diagram and pictures of physical setup: https://photos.app.goo.gl/dm3bircnTBo2W33g6

Link to YouTube video of program operating: https://youtu.be/odwvCafYA-0

"Description"
This ps/2 keyboard to Arduino interface program allows you to print what you type on the ps/2 keyboard onto an LCD screen conected to the Arduino. The program uses interrupts to read each bit from the keyboard and create a binary code that it then checks against known values to determine the key pressed. It then adds the key character value to a string and prints the string to the LCD. If the code is unknown the program currently ignores that input, and if the code is incomplete or corrupted, the program will print out an error. The integrity of the key code is checked by affirming that the start bit is a 0, as it always should be according to the ps/2 standard, and the last bit is a 1, as it also always should be.

The differences both implemented and intended between this program and others like it, including a library purpose made for ps/2 intefacing, is readability and intended function. The programs found as referential for this project were written in a very low level C way, difficult to read for all but a very experienced programmer. My intention when writing this interface program was for it to be relatively easy to read and follow to understand how the program works and how it's recieving input from the keyboard. This interface program also includes built in output for an LCD so the user doesn't need to use the serial monitor to see their input. In the program there are commented out commands to print out to the serial monitor should the user need or want to use the monitor instead of or in conjunction with an LCD. The intended future functions include enabling the shift key to be able to write capital characters and symbols, as well as the delete key to clear the sentence string.

"Coding Diary"
Creating this program was easier than initially thought as a misconception lead me to believe that the Arduino would need to be setup to clock when the keyboard sent an interrupt. This was actually incorrect as the keyboard once triggered will create its own clock pulse. The Arduino can then just shift in a new bit each time the interrupt is triggered until the receiving array(readArray in this case) is filled, at which point the integrity of the array can be checked and the key data can be stripped from the receiving array. When programming the inital bit receiving code, I did run into a road block with the first few received characters being correct, then the rest being jumbled/throwing errors. What I eventually figured out was that I had to clear the receiving array completely after each transmission, otherwise the check for packet integrity would get tripped early due to leftover bits and I would end up with false/useless data. Another issue that I hope to resolve in further development is the shift and delete keys. I tried to use shift as a toggle to enable capital letters symbols from the number row, but for some reason the shift toggle would not activate. Similarly, I attempted to use the delete key as a string clear button but when attempting to use string = "" and string.remove(), neither would actually clear the string variable. Currently the method to clear the existing string variable is to press the Arduino reset button.

"References"
http://www.lucadavidian.com/2017/11/15/interfacing-ps2-keyboard-to-a-microcontroller/
http://www.technoblogy.com/show?1GYR
http://www.burtonsys.com/ps2_chapweske.htm
