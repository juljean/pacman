#pragma once
#include <SFML/Graphics.hpp>

class StringConverter {
public:

    enum StringCode {
        eUp,
        eDown,
        eLeft,
        eRight,
        eNone
    };

	StringCode hashit(sf::String inString);
};