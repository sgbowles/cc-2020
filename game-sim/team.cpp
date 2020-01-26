#include "team.h"

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