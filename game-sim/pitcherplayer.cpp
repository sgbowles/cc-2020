#include "pitcherplayer.h"
#include "iostream"

PitcherPlayer::PitcherPlayer(std::string &f_name, std::string &l_name):
    Player(f_name, l_name),
    ability_rating_(nullptr)
{
    ability_rating_ = new Ability();
    ability_rating_->SetToPitcherDefaults();
}

PitcherPlayer::~PitcherPlayer()
{
    delete ability_rating_;
    ability_rating_ = nullptr;
}

void PitcherPlayer::SetPitcherRating(SkillType type, const unsigned int &rate)
{
    if (!ability_rating_)
        return;

    switch(type)
    {
    case VELOCITY:
        ability_rating_->SetVelocityRating(rate);
        break;
    case CONTROL:
        ability_rating_->SetControlRating(rate);
        break;
    case BREAK:
        ability_rating_->SetBreakRating(rate);
        break;
    case STAMINA:
        ability_rating_->SetStaminaRating(rate);
        break;
    default:
        std::cout << "Not a valid pitcher skill";
    }
}

const unsigned int &PitcherPlayer::GetPitcherRating(const SkillType &type) const
{
    if (!ability_rating_)
        return ABILITY_ERROR_VALUE_;

    switch(type)
    {
    case VELOCITY:
        return ability_rating_->GetVelocityRating();
    case CONTROL:
        return ability_rating_->GetControlRating();
    case BREAK:
        return ability_rating_->GetBreakRating();
    case STAMINA:
        return ability_rating_->GetStaminaRating();
    default:
        std::cout << "Not a valid pitcher skill";
        return ABILITY_ERROR_VALUE_;
    }
}
