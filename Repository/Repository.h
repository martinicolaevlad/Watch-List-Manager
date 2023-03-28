#pragma once
#include "../Domain/Movie.h"
#include "DynamicVector.h"
#include <vector>

class Repository {
private:
    //DynamicVector<Movie> movies;
    std::vector<Movie> movies;
    std::string filename;

public:
    Repository() = default;
//    ~Repository() = default;

    // Check if the movie already exists, otherwise insert in the container
    // Input: movie - Movie entity
    // Output: 0 - error, 1 - otherwise
    void addMovie(const Movie& movie);

    // Check if the movie exists and remove it from the container
    // Input: position - position to delete in DynamicVector
    // Output: 1
    void deleteMovie(int position);

    // Check if the movie exists and update with the new Movie entity
    // Input: position - position to update
    //        movie - new Movie entity
    // Output: 0 - error, 1 - otherwise
    int updateMovie(int position, const Movie& movie);

    // Find a movie by title genre and year
    // Input: title - movie title
    //		  genre - movie genre
    //		  year - movie year
    // Output: true - find, false otherwise
    //bool binarySearchMovie(const std::string& title, const std::string& genre, int year);

    // Compares two movies
    // Input:   index - index for this->movies[..]
    //          title - movie title
    //		    genre - movie genre
    //		    year - movie year
    // Output: true - movie == movie, false - otherwise
   // static bool compareIfSameMovie(const Movie& movie, const std::string& title, const std::string& genre, int year);

    // finds the position of a movie and returns its index
    int findPositionOfMovie(const Movie& movie);

    // Return movie collection
    std::vector<Movie> getMovies() const { return this->movies; }
    int getSize(){ return this->movies.size(); }
    Movie operator[](int index);

    void readFromFile();
    void writeToFile();

    Repository(std::string filename);
};
