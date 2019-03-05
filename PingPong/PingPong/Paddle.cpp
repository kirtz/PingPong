#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Window.h"

/*!
*\file Paddle.cpp
*\brief holds inforamtion on the player controlled paddles on both sides
*this includes the paddle size, colour, where its origin is at. also includes a hidden wall to insure
*the paddle does not leave the window size
*/

//paddle the player controls.
Paddle::Paddle(bool left)
{
	paddle.setSize({ 10, 80 });
	paddle.setFillColor(sf::Color::Red);
	paddle.setOrigin(5, 40);
	if (left)
	{
		position = { 10, height / 2 };
	}
	else
	{
		position = { width - 20, height / 2 };
	}
}

//drawing the paddle to the screen
void Paddle::drawTo(sf::RenderWindow &window)
{
	paddle.setPosition(position);
	window.draw(paddle);
}

// move emnt of the paddle and linking it to the key presses on the keybaord
void Paddle::move(bool left)
{
	if (left)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			position.y--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			position.y++;
	}
	else 
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
			position.y--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
			position.y++;
	}
	//making sure the paddles do not leave the render window
	if (position.y <= 50) position.y++;
	if (position.y >= 400) position.y--;
}

