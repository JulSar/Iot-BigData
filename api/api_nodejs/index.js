const http = require('http');
const express = require('express');
const cors = require('cors');
const Sequelize = require('sequelize');

const sequelize = new Sequelize('gps_wifi', 'gps_admin', 'pass', {
  host: 'mysql.server',
  dialect: 'mysql'
});

const Data = sequelize.define('data', {
  id: { type: Sequelize.INTEGER, primaryKey: true },
  LATITUDE: Sequelize.FLOAT(25),
  LONGITUDE: Sequelize.FLOAT(25),
  signal_intensity: Sequelize.INTEGER
}, {
  timestamps: false
});

sequelize.sync();

const app = express();

app.use(cors());

app.use('/', async (req, res, next) => {
  const data = await Data.findAll();
  return res.json({data});
});

const server = http.createServer(app);
server.listen(process.env.PORT || 5000);

