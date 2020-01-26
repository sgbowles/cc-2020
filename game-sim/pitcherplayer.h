#ifndef PITCHERPLAYER_H
#define PITCHERPLAYER_H

#include "player.h"
#include "ability.h"

class PitcherPlayer : public Player
{
public:
    PitcherPlayer(std::string &f_name, std::string &l_name);
    ~PitcherPlayer();

    void SetPitcherRating(SkillType type, const unsigned int &rate);
    const unsigned int &GetPitcherRating(SkillType &type) const;

private:
    Ability* ability_rating_;
};

#endif // PITCHERPLAYER_H
