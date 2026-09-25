#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
const filmUrl = 'https://swapi-api.hbtn.io/api/films/' + movieId;

request(filmUrl, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  const film = JSON.parse(body);
  const characters = film.characters;
  const names = [];
  let count = 0;

  characters.forEach((url, i) => {
    request(url, (err, res, charBody) => {
      if (err) {
        console.error(err);
        return;
      }
      names[i] = JSON.parse(charBody).name;
      count++;
      if (count === characters.length) {
        names.forEach((name) => console.log(name));
      }
    });
  });
});
