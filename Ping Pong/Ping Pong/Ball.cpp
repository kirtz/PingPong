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

//!the ball. includes all the varbiables the ball has for exmple its size, colour, position and direction
Ball::Ball()
{
	
	ball.setRadius(5); //! radius of the ball
	ball.setFillColor(sf::Color::White); //!colour of the ball
	position = { width / 2, height / 2 }; //!the position of where the ball will spawn
	direction = { 1,1 }; //the direction of the ball
}

//!drawing the ball onto the window for user to see
void Ball::drawto(sf::RenderWindow &window)
{
	ball.setPosition(position); //! drwaing the ball to the middle of the rendering window
	window.draw(ball);
}

//!movement of the ball on the top and bottom axis. this is to make sure the ball doesnt no leave the window size.
void Ball::move()
{
	position.x += direction.x;
	position.y += direction.y;
	//! to ensure thr ball does not leave the render window space

	if (position.y < 30) direction.y *= -1;
	if (position.y > 450) direction.y *= -1;
}

