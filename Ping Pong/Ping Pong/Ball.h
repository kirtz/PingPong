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

	sf::Vector2f position; //!< position of the ball
	sf::CircleShape ball; //!<  what shape the ball is
	sf::Vector2f direction; //!<  what direction the ball will move			
	void drawto(sf::RenderWindow &window); //!<  drawing the ball to the window
	void move(); //!< moving the ball of the screen
};