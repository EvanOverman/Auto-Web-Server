const path = require('path');
const express = require('express');
app = express();

app.get('/express.hpp', (req, res) => {
	res.sendFile(path.join(__dirname + '/express.hpp'));
	console.log('Got request for /express.hpp ... ');
});


app.get('/files.hpp', (req, res) => {
	res.sendFile(path.join(__dirname + '/files.hpp'));
	console.log('Got request for /files.hpp ... ');
});


app.get('/main.cpp', (req, res) => {
	res.sendFile(path.join(__dirname + '/main.cpp'));
	console.log('Got request for /main.cpp ... ');
});


app.get('/main.exe', (req, res) => {
	res.sendFile(path.join(__dirname + '/main.exe'));
	console.log('Got request for /main.exe ... ');
});


app.get('/main.obj', (req, res) => {
	res.sendFile(path.join(__dirname + '/main.obj'));
	console.log('Got request for /main.obj ... ');
});


app.get('/node.hpp', (req, res) => {
	res.sendFile(path.join(__dirname + '/node.hpp'));
	console.log('Got request for /node.hpp ... ');
});


app.get('/server.js', (req, res) => {
	res.sendFile(path.join(__dirname + '/server.js'));
	console.log('Got request for /server.js ... ');
});


app.get('/usage.hpp', (req, res) => {
	res.sendFile(path.join(__dirname + '/usage.hpp'));
	console.log('Got request for /usage.hpp ... ');
});


app.listen(9931180, console.log('Server listening on port 9931180'));const path = require('path');
const express = require('express');
app = express();

app.get('/express.hpp', (req, res) => {
	res.sendFile(path.join(__dirname + '/express.hpp'));
	console.log('Got request for /express.hpp ... ');
});


app.get('/files.hpp', (req, res) => {
	res.sendFile(path.join(__dirname + '/files.hpp'));
	console.log('Got request for /files.hpp ... ');
});


app.get('/main.cpp', (req, res) => {
	res.sendFile(path.join(__dirname + '/main.cpp'));
	console.log('Got request for /main.cpp ... ');
});


app.get('/main.exe', (req, res) => {
	res.sendFile(path.join(__dirname + '/main.exe'));
	console.log('Got request for /main.exe ... ');
});


app.get('/main.obj', (req, res) => {
	res.sendFile(path.join(__dirname + '/main.obj'));
	console.log('Got request for /main.obj ... ');
});


app.get('/node.hpp', (req, res) => {
	res.sendFile(path.join(__dirname + '/node.hpp'));
	console.log('Got request for /node.hpp ... ');
});


app.get('/server.js', (req, res) => {
	res.sendFile(path.join(__dirname + '/server.js'));
	console.log('Got request for /server.js ... ');
});


app.get('/usage.hpp', (req, res) => {
	res.sendFile(path.join(__dirname + '/usage.hpp'));
	console.log('Got request for /usage.hpp ... ');
});


app.listen(16615852, console.log('Server listening on port 16615852'));