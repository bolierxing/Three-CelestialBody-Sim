#!/bin/bash
cd ../
chmod -R 777 assignment2
cd assignment2/program/
make
#Run simulation and drawing program using a file to avoid typing them manually
./Sim < Eight.txt
#Display the picture
display Locus.gif
