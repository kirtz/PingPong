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

	sf::Vector2f position; //!<  position of the paddles
	sf::RectangleShape paddle; //!< what shape the paddle will be
	void drawTo(sf::RenderWindow &window); //!< drawing the paddle onto the window
	void move(bool left); //!< making the paddles move
	bool left; //!< if bool is true left paddle will move, if false right paddle will move.
};