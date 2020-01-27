#include <iostream>

#include "positionplayer.h"
#include "team.h"

int main()
{
    std::string first = "First";
    std::string last = "Base";
    PositionPlayer *first_base = new PositionPlayer(first, last);

    first_base->SetBatterRating(SkillType::CONTACT, 76);
    first_base->SetBatterRating(SkillType::POWER, 85);
    first_base->SetBatterRating(SkillType::SPEED, 45);

    first = "Second";
    PositionPlayer *second_base = new PositionPlayer(first, last);

    second_base->SetBatterRating(SkillType::CONTACT, 80);
    second_base->SetBatterRating(SkillType::POWER, 45);
    second_base->SetBatterRating(SkillType::SPEED, 65);

    std::string home_team_name = "Home Team";
    Team *home_team = new Team(home_team_name);

    home_team->AddPlayerToRoster(FIRST_BASEMAN, first_base);
    home_team->AddPlayerToRoster(SECOND_BASEMAN, second_base);

    home_team->PrintTeamRoster();

    delete first_base;
    delete second_base;
    delete home_team;

    return 0;
}
