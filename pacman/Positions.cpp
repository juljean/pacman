#include "Positions.h"

StringConverter::StringCode StringConverter::hashit(sf::String inString) {
    if (inString == "UP") return eUp;
    if (inString == "DOWN") return eDown;
    if (inString == "LEFT") return eLeft;
    if (inString == "RIGHT") return eRight;
    else return eNone;
}

