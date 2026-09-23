// Demonstrates the use of static constants in a class

#include <iostream>

class Player {
private:
    int health;

public:
    inline static constexpr int maxHealth{100};
    inline static constexpr int maxLevel{50};

    Player(int health)
        : health{health}
    {
    }

    int getHealth() const {
        return health;
    }
};

int main() {
    Player player{80};

    std::cout << "Player health: "
              << player.getHealth() << '\n';

    std::cout << "Maximum health: "
              << Player::maxHealth << '\n';

    std::cout << "Maximum level: "
              << Player::maxLevel << '\n';

    return 0;
}