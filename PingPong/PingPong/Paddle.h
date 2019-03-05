#pragma once
#include <SFML/Graphics.hpp>

/*!
*\file Paddle.h
\brief sets the varbiables needed to make a player paddle
*/

//paddle class the players control.
class Paddle
{
public:
	Paddle(bool left);

	sf::Vector2f position;
	sf::RectangleShape paddle;
	void drawTo(sf::RenderWindow &window);
	void move(bool left);
	bool left;
};