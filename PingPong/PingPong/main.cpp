
/*! \file main.cpp
*
*
* Contains the entry point of the application and the functions which combine
* to provide a Ping Pong game.
*/

/* mainpage assignemnt 1 - Ping Pong Game.
*\this file contains the main code that is run to play the Ping Pong game. 
*the program is ready to be comepiled, make sure you download all the files togethere, 
*including the arial font file to make sure the score card works.
*/



#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Paddle.h"
#include "Ball.h"


Paddle left(1);
Paddle right(0);
Ball ball; //the ball
int scoreRight1 = 0; // right player score
int scoreLeft1 = 0; // left player score
int score = 0;

//collision dection on paddles
void Collision()
{
	if ((ball.position.y < left.position.y + 40) && (ball.position.y > left.position.y - 40) && (ball.position.x < 10))
		ball.direction.x *= -1;
	if ((ball.position.y < right.position.y + 40) && (ball.position.y > right.position.y - 40) && (ball.position.x > 770))
		ball.direction.x *= -1;

	//collision dection to check if player right scored
	if (ball.position.x < 5){
	ball.position = { width / 2, height / 2 };
	scoreRight1++;
	}

	//collision dection to check if player right scored
	if (ball.position.x > 790){
	ball.position = { width / 2, height / 2 };
	scoreLeft1++;
	}
}

//finding out whothe winner is. first to 10 points.
void Winner()
{
	for (int i = 0; i <= 10; i++) {
		bool winner = true;
	}
}

//main game running code where everything is called.
void main()
{
	// calling forward the rendering window, what the windiw will be called
	//text for the scores and details about the fontsize, colour and type of font.
	sf::RenderWindow window(sf::VideoMode(width, height), "PONG");

	//adding the background (center line in the middle)
	sf::Texture background;
	background.loadFromFile("Background.png");
	sf::Sprite sprite;
	sf::Vector2u size = background.getSize();
	sprite.setTexture(background);
	sprite.move(sf::Vector2f(5,0));
	
	//setting score card texts
	sf::Text scoreLeft;
	sf::Text scoreRight;
	sf::Font arial;
	arial.loadFromFile("ARIALI.ttf");

	//left side score card
	scoreLeft.setCharacterSize(20);
	scoreLeft.setFillColor(sf::Color::White);
	scoreLeft.setFont(arial);
	scoreLeft.setPosition(width / 2 - 20, 0);

	//right side score card
	scoreRight.setCharacterSize(20);
	scoreRight.setFillColor(sf::Color::White);
	scoreRight.setFont(arial);
	scoreRight.setPosition(width / 2 + 20, 0);

	//window framerate to control the speed of the game.
	window.setFramerateLimit(300);

	while (window.isOpen())
	{
		window.clear();
		window.draw(sprite);
		left.move(1);
		left.drawTo(window);
		right.move(0);
		right.drawTo(window);
		ball.move();
		Collision();
		ball.drawto(window);
		scoreLeft.setString(std::to_string(scoreLeft1));
		window.draw(scoreLeft);
		scoreRight.setString(std::to_string(scoreRight1));
		window.draw(scoreRight);
		window.display();
	}
}