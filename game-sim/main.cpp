#include <iostream>

#include "positionplayer.h"
#include "pitcherplayer.h"
#include "team.h"

#include <random>

static constexpr unsigned int CONTROL_MAX = 80;

std::pair<int, int> calculatePitchLocation(unsigned int control)
{
    //Calculate the range of error based off the control attr
    unsigned int control_range;

    //sanity check (all attr are in a range of 20-80)
    if (control <= 20)
        control_range = 36;
    else if (control > 75)
        control_range = 3;
    else
        control_range = ((CONTROL_MAX - control)/4) * 3;

    std::cout << "Control: " << control << "\nControl Range: " << control_range << std::endl; 

    std::random_device rd;
    std::mt19937 prng(rd());

    std::uniform_int_distribution<> dis(32,47);

    unsigned int target_x = dis(prng);
    unsigned int target_y = dis(prng);

    std::cout << "Target location is " << target_x << ":" << target_y << std::endl;

    std::normal_distribution<float> nd_dis_x(target_x, control_range), nd_dis_y(target_y, control_range);

    return std::make_pair(static_cast<int>(nd_dis_x(prng)), static_cast<int>(nd_dis_y(prng)));
}

int main()
{
    std::string first = "First";
    std::string last = "Base";
    PositionPlayer *first_base = new PositionPlayer(first, last);

    first_base->SetBatterRating(SkillType::CONTACT, 76);
    first_base->SetBatterRating(SkillType::POWER, 85);
    first_base->SetBatterRating(SkillType::SPEED, 45);

    first = "Second";
    PitcherPlayer *starting_pitcher = new PitcherPlayer(first, last);

    starting_pitcher->SetPitcherRating(SkillType::VELOCITY, 80);
    starting_pitcher->SetPitcherRating(SkillType::BREAK, 45);
    starting_pitcher->SetPitcherRating(SkillType::CONTROL, 55);

    std::string home_team_name = "Home Team";
    Team *home_team = new Team(home_team_name);

    home_team->AddPlayerToRoster(FIRST_BASEMAN, first_base);
    
    std::string away_team_name = "Home Team";
    Team *away_team = new Team(away_team_name);

    away_team->AddPlayerToRoster(STARTING_PITCHER, starting_pitcher);

    home_team->PrintTeamRoster();
    away_team->PrintTeamRoster();

    std::pair<int, int> pitch_loc = calculatePitchLocation(starting_pitcher->GetPitcherRating(SkillType::CONTROL));

    std::cout << "Actual location is " << pitch_loc.first << ":" << pitch_loc.second << std::endl;

    delete first_base;
    delete starting_pitcher;
    delete home_team;
    delete away_team;

    return 0;
}
