# KNX-Communication-Analyser

## About

**KNX-Communication-Analyser is a Wireshark-like KNX network frame analyzer for KNX objects**, like blinds, lighting, heating, air conditioning, and even door communication connected devices using the KNX network. The program is written in C++.

## Features

* See in real-time brut KNX frames transitioning in the network.
* See the translation of the action. For example "Box n°1 transmits the order to turn on the light n°04"
* Log mode: export in one .md or .txt file the frames and their translation transmitted during the execution of the program.
* Minimized logs mode: the program runs in the background and writes on a file the frames transmitted during the execution of the program.

## Necessary Equipment and installation

To run this program, you will need one PCB card (the link of ours is below) on you will put one cable from your KNX bus into it, and connect it to your computer.
After downloading and installing the package [here on fosshub](https://www.fosshub.com/ "KNX-Communication-Analyser download"), and the KNX-Communication-Analyser launched, it will recognize if you will need to install one (or more) drivers on your Windows PC.
The software will detect the KNX frames and will begin to read after clicking on the :arrow_forward: button, and record after clicking the :record_button: button. If you want to run the minimized logs mode, click on the :o: button.
To save and exit, press Ctrl+S or push the :end: button. You also can pause the reading by pushing the :pause_button: button.

## Compatibility

This program is still in development. The current version is alpha 0.0.1
This program was designed to be used in Windows.

## Feedbacks

If you find any bug, do not hesitate to file an issue. Thanks!

## Contributors

This awesome program is created by [IchInose_0x3b](https://github.com/rzdhop "IchInose_0x3b GitHub profile"), [VictorFS78](https://github.com/VictorFS78 "IchInose_0x3b GitHub profile") and Johanne.

## Licence

This program is under the MIT license.

### PCB Plate

[We used this PCB plate](https://github.com/ "no link")

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
![APM](https://img.shields.io/apm/l/vim-mode)
