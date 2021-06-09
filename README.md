# KNX-Communication-Analyser

> By KNX Workers Inc (this is a student project)

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
![APM](https://img.shields.io/apm/l/vim-mode)

## About

**KNX-Communication-Analyser is a Wireshark-like network frame analyser for KNX objects**, such as blinds, lighting, heating, air conditioning, and even devices connected to door communication using the KNX network. The program is written in C++.

## Features

* View in real time the raw KNX frames in transition in the network.
* Log mode: export to a .txt file the frames transmitted during the execution of the program.

## Startup

To run this program, you will need a PCB (link to ours is below) on which you will place a cable from your KNX bus, and connect it to your computer.  
  
After downloading and installing the package available in the project's Git Releases (<https://github.com/rzdhop/KNX-Communication-Analyser> "KNX-Communication-Analyser download"), and running the KNX-Communication-Analyser, it will recognise whether you need to install one (or more) drivers on your PC.
The software will detect KNX frames and start reading after pressing the ▶️ button.

## How to use the graphical version of the KNX Telegram Analyser?

|▶️|Start packet capture|
|➕|Restore current capture (delete all current data)|
|🔚|Save and exit|.

More information on how the two programs work can be found in this documentation

## Compatibility

The current version is alpha 0.0.1.
This program has been designed to be used on Windows 10. Qt and Visual Studio tools may be required, but will be installed automatically if necessary.

## Feedback

If you find a bug, feel free to create a new [issue] (<https://github.com/rzdhop/KNX-Communication-Analyser/issues> "issue's section"). Thank you!

## Contributors

This awesome program was written by [IchInose_0x3b](https://github.com/rzdhop "IchInose_0x3b GitHub profile"), [VictorFS78](https://github.com/VictorFS78 "VictorFS78 GitHub profile") and [Soajoh](https://github.com/Soajoh "Soajoh GitHub profile").

## License

MIT license.

# Using the software

## With the graphical software

The first method is to use the graphical software, the easiest to use, of which an executable version is available on GitHub, in the Releases section.

Start the software. It is likely that you will have to open it with administrator rights in order to be able to detect the different COM ports.
![KNX-CA Windows Logo](https://raw.githubusercontent.com/rzdhop/KNX-Communication-Analyser/gh-pages/assets/KNXCA_desktop.jpg)

After starting the software, press ▶️ to start reading the frames.

![KNX-CA Windows Logo](https://raw.githubusercontent.com/rzdhop/KNX-Communication-Analyser/gh-pages/assets/Inkedscreen_qt_withoutdetails_LI.jpg)

As the frames are displayed, you can see the details of the frame by clicking on the ➕ icon.

![KNX-CA Windows Logo](https://raw.githubusercontent.com/rzdhop/KNX-Communication-Analyser/gh-pages/assets/Inkedscreen_qt_LI.jpg)

## With the command line software

The command line version is more complicated to use, but more complete.

Executed without any arguments, it will not return anything. Here is the list of the different arguments available.

|-h|-help|Displays the quick help and a link to the online documentation.
|-Automatically detects the COM port and listens for KNX frames.
|-Asks the user to specify the COM port he wants to use for the frame analyser.
|-This allows the user to have the information of a hexadecimal frame already in the user's possession.

One of the most interesting features is the decoping of an existing frame, as seen before. Run it according to this scheme: ```.\<program name> -f```

A GIF shows you the execution of this option below.

![Utilisation avec une trame déjà existante](https://raw.githubusercontent.com/rzdhop/KNX-Communication-Analyser/gh-pages/assets/knx-manualframe.gif)

## Log file

After each run of the software, a log file is generated in the folder containing the software.
Please note. This file is not purged at each execution to avoid the loss of important data. You must therefore delete it or delete its contents if you wish to have a new file.