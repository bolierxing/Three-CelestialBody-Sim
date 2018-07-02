#!/bin/bash
cd ../../
chmod -R 777 assignment2
cp assignment2/program/*.dat  assignment2/Bonus_part/
cd assignment2/Bonus_part
python Dynamic_image.py
