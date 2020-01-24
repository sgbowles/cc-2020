#include "player.h"

Player::Player(std::string &f_name, std::string &l_name) :
    first_name_(f_name),
    last_name_(l_name)
{

}

Player::~Player()
{

}

const std::string Player::GetFirstName() const
{
    return first_name_;
}

const std::string Player::GetLastName() const
{
    return last_name_;
}
