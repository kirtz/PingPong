#pragma once
#include <SFML/Graphics.hpp>

/*!
\file Ball.h
\brief setting the Variables that the ball class would need to function
*/

//the ball class with all its variables. 
class Ball
{
public:
	Ball();
	
	sf::Vector2f position;
	sf::CircleShape ball;
	sf::Vector2f direction;
	void drawto(sf::RenderWindow &window);
	void move();
};