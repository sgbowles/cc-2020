#include "positionplayer.h"
#include "iostream"

PositionPlayer::PositionPlayer(std::string &f_name, std::string &l_name) :
    Player(f_name, l_name),
    ability_rating_(nullptr)
{
    ability_rating_ = new Ability();
    ability_rating_->SetToBatterDefaults();
}

PositionPlayer::~PositionPlayer()
{
    delete ability_rating_;
    ability_rating_ = nullptr;
}

void PositionPlayer::SetBatterRating(SkillType type, const unsigned int &rate)
{
    if (!ability_rating_)
        return;

    switch(type)
    {
    case CONTACT:
        ability_rating_->SetContactRating(rate);
        break;
    case POWER:
        ability_rating_->SetPowerRating(rate);
        break;
    case SPEED:
        ability_rating_->SetSpeedRating(rate);
        break;
    case STAMINA:
        ability_rating_->SetStaminaRating(rate);
        break;
    default:
        std::cout << "Not a valid batter skill";
    }
}

const unsigned int &PositionPlayer::GetBatterRating(const SkillType &type) const
{
    if (!ability_rating_)
        return ABILITY_ERROR_VALUE_;

    switch(type)
    {
    case CONTACT:
        return ability_rating_->GetContactRating();
    case POWER:
        return ability_rating_->GetPowerRating();
    case SPEED:
        return ability_rating_->GetSpeedRating();
    case STAMINA:
        return ability_rating_->GetStaminaRating();
    default:
        std::cout << "Not a valid batter skill";
        return ABILITY_ERROR_VALUE_;
    }
}
