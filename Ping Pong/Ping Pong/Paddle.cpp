#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Window.h"

/*!
*\file Paddle.cpp
*\brief holds inforamtion on the player controlled paddles on both sides
*this includes the paddle size, colour, where its origin is at. also includes a hidden wall to insure
*the paddle does not leave the window size
*/

//!paddle the player controls. 
Paddle::Paddle(bool left)
{
	//! setting the size of the paddles
	paddle.setSize({ 10, 80 });
	//! colour of paddles
	paddle.setFillColor(sf::Color::Red);
	//! origin of the paddle, first left then right.
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

//!drawing the paddle to the screen
void Paddle::drawTo(sf::RenderWindow &window)
{
	paddle.setPosition(position);
	window.draw(paddle);
}

//!movement of the paddle and linking it to the key presses on the keybaord

void Paddle::move(bool left)
{
	//!setting keys for left side player
	if (left)
	{
		//!left player keybindings
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			position.y--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			position.y++;
	}

	//! setting keys for right side player
	else
	{
		//!right side player key bindings
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) 
			position.y--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
			position.y++;
	}

	//!making sure the paddles do not leave the render window
	if (position.y <= 50) position.y++;
	if (position.y >= 400) position.y--;
}

