# Auto-Web-Server
An automatic web server creator that takes HTML, CSS, images, and other files and generates a server.js file to be ran and get your web server up sooner! The program takes the current directory and creates a file, dirIndex.ls with a list fo the files in it. With this it can make a server.js file, this can be run to start your web server!

# Add to Your Project!
Auto-Web-Server is meant to be integrated into other projects, because of this it does not work like an application, instead clone the repo, and put all of its files (except LICENSE and README.md) into your project, then run the setup script using bash.
```
$ ./setup.sh
```
You will be prompted for your password, and if it is not your first time running the script, you may see a few errors in the begining because some directories will have been made the first time you made the script. Assuming these errors are for these reasons they can be ignored. At the time of writing you can use the script to start your server even after setup, however it is recommended that you only run the script when setting up for the first time, and when updating. Instead run the binary file like so.
```
$ ./autoWebServer
```
Thats it! You've added Auto-Web-Server to your project!

# Updating
To update Auto-Web-Server, in the event that you want to, clone the repo again, and replace all old files with the new ones, run the setup scrip again as detailed in the "Add to you Project!" section. Leave the directory structure the same, but remove all directory index files, these, in the event that the way they work is updated, could cause problems if not deleted.
