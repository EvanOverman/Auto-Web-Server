# Auto-Web-Server
An automatic web server creator that takes HTML, CSS, images, and other files and generates a server.js file to be ran and get your web server up sooner! The program takes the current directory and creates a file, dirIndex.ls with a list fo the files in it. With this it can make a server.js file, this can be run to start your web server!

# Add to Your Project!
Make sure you have Node.js and NPM installed. On Debian based systems you can simply `apt` them.
```
apt install nodejs
apt install npm
```
On Windows you can either get these online, or install them with WinGet, you may need to install NPM seperately.
```
winget install nodejs
```
Once you have Node.js and NPM installed, you will need to install the NPM package "Express" to the folder that you have AutoWebServer in.
```
cd /path/to/autowebserver
npm install express
```

# Usage
Chances are you will want to use the recursive format, to do this one Linux run this command.
```
./AutoWebServer --recursive
```
If your on Windows run this command.
```
.\AutoWebServer.exe /recursive
```
This will use your current directory, and since we are using the recursive format, it will also go through any and all sub-directories, finding all of the files in them, and adding them to the server.js file, you may need to run as administator on windows and as root on linux to use port 80. To add downloads you need to make a folder named `DOWNLOADS` within your chosen directory and add the downloads argument, `--downloads` for Linux and `/downloads` on Windows. If you would like to use a directory other than the one Auto-Web-server is in, is the directory argument, `--directory` on Linux, and `/directory` on Windows, folow this argument with the path to your desired directory. For more arguments you can open the man page like so:
```
./AutoWebServer --help
.\AutoWebServer.exe /help
```
