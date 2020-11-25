# Auto-Web-Server
An automatic web server creator that takes HTML, CSS, images, and other files and generates a server.js file to be ran and get your web server up sooner! The program takes the current directory and creates a file, dirIndex.ls with a list fo the files in it. With this it can make a server.js file, this can be run to start your web server!

# Add to Your Project!
To add Auto-Web-Server to your project download the latest release binary, and run it with this command:
```
./AutoWebServer --setup
```
The "-s" tell the program to run setup. You can run it without "-s" and perform the first time setup that way, this method will also allow you do do everything else, though with all of its prompts it is often slower. 

# Usage
Chances are you will want to use the organized format, to do this run this command.
```
./AutoWebServer --organized
```
Make sure that all of your HTML, CSS, Java Script, etc. files are in their respective folder with proper links to one another. An index.html file can be placed in none of the subdirectories and instead the root of the organized directory. Placing it here will make it so that "http://youserver/" will redirect to "http://yourserver/index.html". To make sure your HTML files link to your images, CSS, and Java Script correctly, make sure they link like so: 
```
href = "/css/stylesheet.css"
```
You have to link like this (/js/javascript.js, /images/pic.png, etc.) because Auto-Web-Server hosts the file along with their enclosing folder. If you are using the simple format you should run the program like this:
```
./AutoWebServer --simple
```
This will run the program with the simple format, this format does not support downloads without manually editing the server.js file. To link properly simply link like this:
```
href = "/stylesheet.css"
```
Every single file in the simple directory is hosted at the root of your server and can therefore be linked simply by putting a forward slash in front of the exact file name.

To run multiple instances you may want to run the server on a different port, to do this just put the port number after the argument declaring either the simple or organized format like so:
```
./AutoWebServer --organized 3000
```
This will host the server using the organized format on port 3000, all of this can be done, guided by prompts, by running the program without any arguments.

# Updating
Download the latest release binary and run the setup again, you may not need to, but it is recommended that you delete all of the old directory indexies.
