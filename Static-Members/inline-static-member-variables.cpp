//Demonstration of inline static member variables in C++

#include <iostream>

class Player {

private:

    int id;
    inline static int nextID{1};
    inline static int playerCount{};

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