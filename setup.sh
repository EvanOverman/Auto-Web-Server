# setup.sh
# Evan Overman
# Created Oct 22, 2020
# Last update: Oct 25, 2020

#!/bin/bash

mkdir organized
mkdir simple
mkdir iterative

mkdir organized/css
mkdir organized/downloads
mkdir organized/js
mkdir organized/pages
mkdir organized/pictures

ls > tempDirIndex.ls
ls organized > dirIndex.ls
ls simple > simpleDirIndex.ls
ls iterative > iterativeDirIndex.ls

ls organized/css > cssDirIndex.ls
ls organized/downloads > downloadsDirIndex.ls
ls organized/js > jsDirIndex.ls
ls organized/pages > pagesDirIndex.ls
ls organized/pictures > picturesDirIndex.ls

echo "No content yet, run program to populate this file." > server.js
echo "No content yet, run program to populate this file." > iterativeDirIndexing.sh

sudo apt update

sudo apt install -y g++
sudo apt install -y nodejs
sudo apt install -y npm

sudo npm install express

g++ main.cpp
mv a.out autoWebServer.out

echo "Do you want to start the program? [Y/n]: "
read yn

if [ "$yn" == "y" ] || [ "$yn" == "Y" ];
then
	echo "Starting ..."
	./autoWebServer.out
fi
