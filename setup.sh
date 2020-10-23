#!/bin/bash

apt update

apt install -y g++
apt install -y nodejs
apt install -y npm

g++ main.cpp
npm install express