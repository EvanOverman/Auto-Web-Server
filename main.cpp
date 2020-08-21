// https://github.com/EvanOverman/Auto-Web-Server

#include <iostream>
#include <experimental/filesystem>
#include <fstream>
#include <string>

#include "serverJS.h"
#include "directoryIndexing.h"

using namespace std;

vector <string> splitString(string text, char split) {

    vector <string> splitText;

    size_t position = text.find(split);
    size_t initialPosition = 0;

    splitText.clear();

    while(position != string::npos) {

        splitText.push_back(text.substr(initialPosition, position - initialPosition));
        initialPosition = position + 1;

        position = text.find(split, initialPosition);

    }

    splitText.push_back(text.substr(initialPosition, min(position, text.size()) - initialPosition + 1));

    return splitText;

}

int main(void) {

    cout << "https://github.com/EvanOverman/Auto-Web-Server" << endl << endl;

    ifstream startMessageTXT;
    startMessageTXT.open("startMessage.txt");

    string startMessage;
    getline(startMessageTXT, startMessage);

    cout << startMessage << endl;
    cout << "Would you like to continue? [Y/n]: ";

    char yn = 'y';
    cin >> yn;

    if (yn == 'y' || yn == 'Y' || isblank(yn)) {

        while (true) {

            cout << "What storage format will be used for the web server?" << endl;
            cout << "\t[1] Simple." << endl << "\t[2] Standard." << endl << "\t[3] Organized" << endl << "\t[4] GS Compatable" << endl;
            cout << "Storage format? [1/2/3/4]: ";

            char format = '1';
            cin >> format;

            if (format == '1') { // Selected format one.

                system("cd Simple");

                vector <string> directoryIndex;

                ifstream fileExists;
                fileExists.open("directoryIndex.ls");

                if (fileExists){ // If the directory index exists then allow the user to update it.

                    cout << "If you have made changes since you created or updated the directory index you should update it for changes to take effect." << endl;
                    cout << "Would you like to update the directory index? [Y/n]: ";

                    yn = 'y';
                    cin >> yn;

                    if (yn == 'y' || yn == 'Y') {

                        updateDirectoryIndex(); // Update the directory index.

                    }

                    directoryIndex = readDirectoryIndex(); // Read the directory index.

                    cout << "The server will be hosted on a certain port, often this port is 3000 but can be anyport, or if you have multiple server instances, it needs multiple ports. Whatever port you set should be port forwarded if you want your server to accessable from the internet." << endl;
                    cout << "What port would you like to host the server on [i.e. 3000]: ";

                    string port;
                    cin >> port;

                    makeServerJS(directoryIndex, stoi(port));

                } else { // If no directory inedx exists then allow the user to create one.

                    cout << "An index of the current directory must exist for the program to properly generate a Node.js file to run your web server." << endl;
                    cout << "Would you like to index the directory now? [Y/n]: ";

                    yn = 'y';

                    if (yn == 'y' || yn == 'Y') {

                        creatDirectoryIndex(); // Create a directory index.

                    } else { // If the user decides not to create a directory index, simply continue as though it exists.

                        cout << "If you have made changes since you created or updated the directory index you should update it for changes to take effect." << endl;
                        cout << "Would you like to update the directory index? [Y/n]: ";

                        yn = 'y';
                        cin >> yn;

                        if (yn == 'y' || yn == 'Y') {

                            updateDirectoryIndex(); // Update the directory index.

                        }

                        directoryIndex = readDirectoryIndex(); // Read directory index.

                        cout << "The server will be hosted on a certain port, often this port is 3000 but can be anyport, or if you have multiple server instances, it needs multiple ports. Whatever port you set should be port forwarded if you want your server to accessable from the internet." << endl;
                        cout << "What port would you like to host the server on [i.e. 3000]: ";

                        string port;
                        cin >> port;

                        makeServerJS(directoryIndex, stoi(port));

                    }

                }

            } else if (format == '2') {


                
            } else if (format == '3') {


                
            } else if (format == '4') {


                
            } else {

                cout << "Please enter 1, 2, 3, or 4." << endl;

            }

        }

        return 1;

    } else {

        return 1; // Quit the program.

    }

}

