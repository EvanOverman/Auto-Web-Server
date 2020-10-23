express = require('express');
path = require('path');
app = express();

app.get('/a.out', (req, res) => {
res.sendFile(path.join(__dirname + 'a.out'));
console.log('Got request for /a.out ... ');
});

app.get('/directoryIndexing.h', (req, res) => {
res.sendFile(path.join(__dirname + 'directoryIndexing.h'));
console.log('Got request for /directoryIndexing.h ... ');
});

app.get('/dirIndex.ls', (req, res) => {
res.sendFile(path.join(__dirname + 'dirIndex.ls'));
console.log('Got request for /dirIndex.ls ... ');
});

app.get('/Legacy Code', (req, res) => {
res.sendFile(path.join(__dirname + 'Legacy Code'));
console.log('Got request for /Legacy Code ... ');
});

app.get('/main.cpp', (req, res) => {
res.sendFile(path.join(__dirname + 'main.cpp'));
console.log('Got request for /main.cpp ... ');
});

app.get('/node_modules', (req, res) => {
res.sendFile(path.join(__dirname + 'node_modules'));
console.log('Got request for /node_modules ... ');
});

app.get('/serverJS.h', (req, res) => {
res.sendFile(path.join(__dirname + 'serverJS.h'));
console.log('Got request for /serverJS.h ... ');
});

app.listen(3000, console.log('Server listening on port3000'));