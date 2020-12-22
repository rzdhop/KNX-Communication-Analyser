<img src="assets/knxworkers-logo.png" width="300">

# KNX-Communication-Analyser

> *By KNXWorkers Inc.*

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
![APM](https://img.shields.io/apm/l/vim-mode)

## About

**KNX-Communication-Analyser is a Wireshark-like network frame analyzer for KNX objects**, like blinds, lighting, heating, air conditioning, and even door communication connected devices using the KNX network. The program is written in C++.

## Features

* See in real-time raw KNX frames transitioning in the network.
* See the translation of the action. For example "Box n°1 transmits the order to turn on the light n°04"
* Log mode: export in one .md or .txt file the frames and their translation transmitted during the execution of the program.
* Minimized logs mode: the program runs in the background and writes on a file the frames transmitted during the execution of the program.
* (in project) Print selected KNX frames directly from the app.

## Get started

To run this program, you will need one PCB card (the link of ours is below) on you will put one cable from your KNX bus into it, and connect it to your computer.  
  
After downloading and installing the package [here on fosshub](https://www.fosshub.com/ "KNX-Communication-Analyser download"), and the KNX-Communication-Analyser launched, it will recognize if you will need to install one (or more) drivers on your PC.
The software will detect the KNX frames and will begin to read after pushing the ▶️ button or press Ctrl+B.

## How to use KNX-Communication-Analyser ?

|Keyboard shortcuts|Information|
|-----|----|
|▶️ or Ctrl+B|Start capturing packets|
|⏺️ or Ctrl+R|Record the packets into one .md or one .txt file with their description|
|↘️ or Ctrl+M|Minimize the program (still running in the background)|
|⏸️ or Ctrl+Pause|Pause the capture|
|⏏️ or Ctrl+Del|Restart current capture (erase all current data)|
|🔚 or Ctrl+S|Save and exit|

[//]: <> (Screenshot nedded. Please remove this line ONLY when the screenshot will be added.)

## Compatibility

This program is still in development. The current version is alpha 0.0.1
This program was designed to be used in Windows.

## Feedbacks

If you find any bug, do not hesitate to create an new [issue](https://github.com/rzdhop/KNX-Communication-Analyser/issues "issue's section"). Thanks!

## Contributors

This awesome program is written by [IchInose_0x3b](https://github.com/rzdhop "IchInose_0x3b GitHub profile"), [VictorFS78](https://github.com/VictorFS78 "VictorFS78 GitHub profile") and [Soajoh](https://github.com/Soajoh "Soajoh GitHub profile").

## License

MIT license.
