// https://github.com/EvanOverman/Auto-Web-Server

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void clearServerJS(void) {

    fstream serverJS;
    serverJS.open("server.js", ios::out);

}

void startServerJS(void) {

    fstream serverJS;
    serverJS.open("server.js", ios::app);

    serverJS << "// https://github.com/EvanOverman/Auto-Web-Server" << endl;
    serverJS << "// This file was generated by Auto-Web-Server" << endl;
    serverJS << "express = require('express');" << endl;
    serverJS << "path = require('path');" << endl;
    serverJS << "app = express();" << endl;

}

void endServerJS(int port) {

    fstream serverJS;
    serverJS.open("server.js", ios::app);

    serverJS << "app.listen(" << port << ", console.log('server listening on port " << port << " ... '));" << endl;

    serverJS.close();

}

string makeGet(string file) {

    string get = "app.get('" + file + "', (req,res) => {\n\tres.send(path.join(__dirname + '" + file + "'));\n\tconsole.log('server got request for " + file + " ... ');\n});";
    return get;

}

int main(void) {

    clearServerJS();
    startServerJS();
    endServerJS(3000);

    return 0;

}

