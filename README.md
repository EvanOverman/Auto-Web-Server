# Auto-Web-Server
An automatic web server creator that takes HTML, CSS, images, and other files and generates a server.js file to be ran and get your web server up sooner! The program takes the current directory and creates a file, dirIndex.ls with a list fo the files in it. With this it can make a server.js file, this can be run to start your web server!

# Add to Your Project!
To add Auto-Web-Server to your project youcan either get the latest release, which I recommend, or, if you feel like using some work-in-progress features, you can clone and compile the program yourself. If you do compile the program yourself do it with G++ like this, and G++ has been my compiler of choice for the project.
```
g++ main.cpp -o AutoWebServer
```
This makes sure that the outfile is named "AutoWebServer", this is important if you intend to follo these instructions, but it doesnt take much knowledge to differ from them, so feel free to do so. To run the program use this command.
```
./AutoWebServer
```
This will run the program, if it is your first time doing so, or if you are updating, run the first time setup, if you are running this you may see some errors about directories a;ready existing, this just means that the setup has been run before, or done manually, either way, you can ignore these errors.

Thats it! You've added Auto-Web-Server to your project!

# Updating
To update Auto-Web-Server, in the event that you want to, clone the repo again, and replace all old files with the new ones, run the setup scrip again as detailed in the "Add to you Project!" section. Leave the directory structure the same, but remove all directory index files, these, in the event that the way they work is updated, could cause problems if not deleted.
