const express = require('express');
const app = express();
const bodyParser = require('body-parser');
const path = require('path');


app.use(bodyParser.json());
app.use(express.static(path.join(__dirname, '/')));

let x = 0;

app.post('/data', function(req, res) {
  x = req.body.x;
  console.log(x);
  res.sendStatus(200);
});

app.get('/data', function(req, res) {
  res.json({ x: x });
  res.sendStatus(200);
});

app.get('/', function(req, res) {
  res.sendFile(__dirname + './public/index.html');
});

app.listen(3000,'192.168.24.33', function() {
  console.log('Server listening on port 3000');
});
