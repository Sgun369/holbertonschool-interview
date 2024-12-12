#!/usr/bin/node

const request = require('request');

// Get the Movie ID from the first command line argument
const movieId = process.argv[2]; // This line is fine
if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

const apiUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

// Make a request to the Star Wars API for the film information
request(apiUrl, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error(`Error: Received status code ${response.statusCode}`);
    return;
  }

  // Parse the response body to JSON
  let filmData;
  try {
    filmData = JSON.parse(body);
  } catch (parseError) {
    console.error('Error parsing response body:', parseError);
    return;
  }

  const characters = filmData.characters;
  if (!characters || characters.length === 0) {
    console.log('No characters found for this movie.');
    return;
  }

  // For each character URL, make a request to get the character's name
  characters.forEach((characterUrl) => {
    request(characterUrl, (error, response, body) => {
      if (error) {
        console.error(error);
        return;
      }

      if (response.statusCode !== 200) {
        console.error(`Error: Received status code ${response.statusCode}`);
        return;
      }

      let characterData;
      try {
        characterData = JSON.parse(body);
      } catch (parseError) {
        console.error('Error parsing character response body:', parseError);
        return;
      }

      console.log(characterData.name);
    });
  });
});
