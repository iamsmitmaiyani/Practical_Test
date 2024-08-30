#include <iostream>
#include <string>

class Movie {
private:
    std::string title;
    std::string genre;
    int releasedYear;

public:
    // Constructor
    Movie(const std::string& t, const std::string& g, int r) 
        : title(t), genre(g), releasedYear(r) {}

    // Getter for title
    std::string getTitle() const {
        return title;
    }

    // Getter for genre
    std::string getGenre() const {
        return genre;
    }

    // Getter for released year
    int getReleasedYear() const {
        return releasedYear;
    }

    // Method to display movie information
    void displayInfo() const {
        std::cout << "Title: " << title 
                  << ", Genre: " << genre 
                  << ", Released Year: " << releasedYear 
                  << std::endl;
    }
};

int main() {
    // Create an array of Movie objects
    const int movieCount = 3;
    Movie movies[movieCount] = {
        Movie("Inception", "Sci-Fi", 2010),
        Movie("The Shawshank Redemption", "Drama", 1994),
        Movie("The Matrix", "Action", 1999)
    };

    // Access and display information of each movie
    for (int i = 0; i < movieCount; ++i) {
        movies[i].displayInfo();
    }

    return 0;
}
