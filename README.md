# UVSimGUI
Software Engineering Project for UVU (GUI)

## Collaborators:
Nathan Hanzel, Connor Creer, David Riggs, and Tad Huntsman

## Starting the Program
Open up the project in Visual Studio 2017, and click on the "Local Windows Debugger" button to start the program.

You will see the terminal pop up first, but don't worry, the GUI will shortly follow it.

## Inputting the script
When you are inputting your script, you are required to put in 4 letter words with a plus prepended to the word (+4000)

(Make sure that there isn't a newline character at the end of the input or else the compiler won't run)

#### Word Format
Because this has 1000 memory locations, you should have the first instruction be the opcode, and the second one is the location

The instructions will always come in pairs

Ex: "4030" becomes "4000" and "0030"

## Inputting test data
If your program requires you to give input, there is a textbox right above the main memory window.

Once you put in the input, you must press SUBMIT, then RUN again. If you only press submit, the program will wait for you to start the program up again.

## File I/O
There are three options for File I/O: New, Load, and Save.

For New, put in the name of the file that you want to make. The InputTB will go blank, but you will still have to load with that same file name (it won't automatically save)

For Load, put in the name of the file that you want to load the input from (make sure it is in the working directory of the project).

For Save, put in the name of the file that you want to save the input to (make sure it is in the working directory of the project).

#### When inputting the filename, ONLY put the name of the file, not the file type (i.e. "newFile", not "newFile.txt")

