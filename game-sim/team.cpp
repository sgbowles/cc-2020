#include "team.h"
#include "player.h"

#include "iostream"

std::string PostionToString(const Position &p)
{
    switch(p)
    {
    case RELIEF_PITCHER:
        return "Relief Pitcher";
    case STARTING_PITCHER:
        return "Starting Pitcher";
    case CATCHER:
        return "Catcher";
    case FIRST_BASEMAN:
        return "First Baseman";
    case SECOND_BASEMAN:
        return "Second Baseman";
    case THIRD_BASEMAN:
        return "Third Baseman";
    case SHORTSTOP:
        return "Shortstop";
    case LEFT_FIELDER:
        return "Left Fielder";
    case CENTER_FIELDER:
        return "Center Fielder";
    case RIGHT_FIELDER:
        return "Right Fielder";
    }
}


Team::Team(std::string &team_name):
    team_name_(team_name)
{
    
}

Team::~Team()
{

}

const std::string Team::GetTeamName() const
{
    return team_name_;
}

void Team::AddPlayerToRoster(Position position, Player *player)
{
    team_roster_.insert(std::pair<Position, Player*>(position, player));
}

void Team::PrintTeamRoster()
{
    Roster_Map::iterator it = team_roster_.begin();
    while (it != team_roster_.end())
    {
        std::cout << PostionToString(it->first) << ": " << it->second->GetFirstName() << " " << it->second->GetLastName() << std::endl;
        ++it;
    }
}