#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string makeGet(string file) {

    string get = "app.get('" + file + "', (req,res) => {\n\tres.send(path.join(__dirname + '" + file + "'));\n\tconsole.log('server got request for " + file + " ... ');\n});";
    return get;

}

int main(void) {

    fstream outfile;
    outfile.open("server.js");

    while(true) {

        string input;
        cout << ">";
        cin >> input;

        outfile << makeGet(input) << endl;

    }

    return 0;
    
}

