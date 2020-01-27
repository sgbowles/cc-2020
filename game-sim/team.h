#ifndef TEAM_H
#define TEAM_H

#include <map>
#include <string>

class Player;

enum Position
{
    RELIEF_PITCHER = 0,
    STARTING_PITCHER,
    CATCHER,
    FIRST_BASEMAN,
    SECOND_BASEMAN,
    THIRD_BASEMAN,
    SHORTSTOP,
    LEFT_FIELDER,
    CENTER_FIELDER,
    RIGHT_FIELDER
};

typedef std::map<Position, Player*> Roster_Map;

class Team
{
public:
    Team(std::string &team_name);
    ~Team();

    const std::string GetTeamName() const;

    void AddPlayerToRoster(Position position, Player *player);

    void PrintTeamRoster();

private:
    std::string team_name_;

    Roster_Map team_roster_;
};

#endif // TEAM_H