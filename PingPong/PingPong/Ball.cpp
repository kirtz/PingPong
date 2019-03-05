#include "Ball.h"
#include "Window.h"
#include <SFML/Graphics.hpp>

/*!
\file Ball.cpp
*/
/*
\brief contains inforamtion rregardinf the ball. things such as the size and its position on the window
what direction the ball will go and its movement. 
*/

//the ball. includes all the varbiables the ball has for exmple its size, colour, position and direction
Ball::Ball()
{
	ball.setRadius(5);
	ball.setFillColor(sf::Color::White);
	position = { width / 2, height / 2 };
	direction = {1,1};
}

//drawing the ball onto the window for user to see
void Ball::drawto(sf::RenderWindow &window)
{
	ball.setPosition(position);
	window.draw(ball);
}

//movement of the ball on the top and bottom axis. this is to make sure ther ball doesnt no leave the window size.
void Ball::move()
{
	position.x += direction.x;
	position.y += direction.y;
	if (position.y < 30) direction.y *= -1;
	if (position.y > 450) direction.y *= -1;
}

