#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
public:
    Player(std::string &f_name, std::string &l_name);
    ~Player();

    const std::string GetFirstName() const;
    const std::string GetLastName() const;

private:
    std::string first_name_;
    std::string last_name_;
};

#endif // PLAYER_H
