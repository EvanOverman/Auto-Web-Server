#!/bin/bash
# This script currently only installs the dependencies for the generated server.js file, but will eventually install the program.

apt update
apt install node
apt install npm

npm install express
