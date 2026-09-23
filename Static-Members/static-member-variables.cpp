//Demonstration of static member variables in C++, using a shared player counter and automatic ID generation.

#include <iostream>

class Player {

private:

    int id;
    static int nextID;
    static int playerCount;

public:

    // Constructor
    Player()
        : id{nextID++}
    {
        ++playerCount;
    }

    // Getter for ID
    int getID() const {
        return id;
    }

    // Getter for total players
    static int getPlayerCount() {
        return playerCount;
    }
};

// Static member definitions
int Player::nextID{1};
int Player::playerCount{0};

int main() {

    Player p1;
    Player p2;
    Player p3;

    std::cout << "Player 1 ID: " << p1.getID() << std::endl;
    std::cout << "Player 2 ID: " << p2.getID() << std::endl;
    std::cout << "Player 3 ID: " << p3.getID() << std::endl;

    std::cout << "Total players: "
              << Player::getPlayerCount()
              << std::endl;

    return 0;
}