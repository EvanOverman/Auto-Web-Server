# setup.sh
# Evan Overman
# Created Oct 22, 2020
# Last update: Oct 22, 2020

#!/bin/bash

sudo apt update

sudo apt install -y g++
sudo apt install -y nodejs
sudo apt install -y npm

g++ main.cpp
sudo npm install express
