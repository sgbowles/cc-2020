#ifndef POSITIONPLAYER_H
#define POSITIONPLAYER_H

#include "player.h"
#include "ability.h"

class PositionPlayer : public Player
{
public:
    PositionPlayer(std::string &f_name, std::string &l_name);
    ~PositionPlayer();

    void SetBatterRating(SkillType type, const unsigned int &rate);
    const unsigned int &GetBatterRating(const SkillType &type) const;

private:
    Ability* ability_rating_;

};

#endif // POSITIONPLAYER_H
