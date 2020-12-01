# Auto-Web-Server
An automatic web server creator that takes HTML, CSS, images, and other files and generates a server.js file to be ran and get your web server up sooner! The program takes the current directory and creates a file, dirIndex.ls with a list fo the files in it. With this it can make a server.js file, this can be run to start your web server!

# Add to Your Project!
Make sure you have Node.js and NPM installed. On Debian based systems you can simply `apt` them.
```
apt install nodejs
apt install npm
```
On Windows you can either get these online, or install them with WinGet.
```
winget install nodejs
```
Once you have Node.js and NPM installed, you will need to install the NPM package "Express" to the folder that you have AutoWebServer in.
```
cd /path/to/autowebserver
npm install express
```

# Usage
Chances are you will want to use the iterative format, to do this one Linux run this command.
```
./AutoWebServer --iterative /path/to/folder
```
If your on Windows run this command.
```
.\AutoWebServer.exe /iterative C:\path\to\folder
```
Running these commands, since it was not otherwise specified, will host the server on port 80, to host on a different port, simply put the port bumber after the path to your folder.
```
./AutoWebServer --iterative /path/to/folder 3000
```
