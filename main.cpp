#include <iostream>

#include "positionplayer.h"

int main()
{
    std::string first = "First";
    std::string last = "Base";
    PositionPlayer *first_base = new PositionPlayer(first, last);

    first_base->SetBatterRating(SkillType::CONTACT, 86);

    std::cout << "First baseman's contact skill is: " << first_base->GetBatterRating(SkillType::CONTACT) << std::endl;

    return 0;
}
