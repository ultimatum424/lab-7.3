#include "const.h"
#include <iostream>

using namespace sf;

void loadImage(struct StructImages& s, String F)
{
	s.image.loadFromFile(F);
	s.texture.loadFromImage(s.image);
	s.sprite.setTexture(s.texture);
	s.centre.x = s.image.getSize().x / 2;
	s.centre.y = s.image.getSize().y / 2;
}
void Draw(RenderWindow& window, StructMechanism mechanism, StructPendulum pendulum)
{
	window.draw(pendulum.turn);
	window.draw(pendulum.weight);
	window.draw(mechanism.big);
	window.draw(mechanism.small);	
}
void InitializeGear(StructMechanism& mechanism, StructImages& gear1, StructImages& gear2)
{
	mechanism.big.setTexture(gear1.texture);
	mechanism.small.setTexture(gear2.texture);
	mechanism.big.setOrigin(gear1.centre.x, gear1.centre.y);
	mechanism.small.setOrigin(gear2.centre.x, gear2.centre.y);
	mechanism.big.setPosition(BIG_MECHANISM_POS);
	mechanism.small.setPosition(SMALL_MECHANISM_POS);
}
void InitializePendulum(StructPendulum& pendulum)
{
	pendulum.turn.setPointCount(4);
	pendulum.turn.setPoint(0, sf::Vector2f(0, 200));
	pendulum.turn.setPoint(1, sf::Vector2f(100, 100));
	pendulum.turn.setPoint(2, sf::Vector2f(200, 200));
	pendulum.turn.setPoint(3, sf::Vector2f(100, 100));
	pendulum.turn.setFillColor(Color::Black);
	pendulum.turn.setOrigin(100, 100);
	pendulum.turn.setPosition(PENDULUM_POS);
	pendulum.weight.setPointCount(5);
	pendulum.weight.setPoint(0, sf::Vector2f(100, 100));
	pendulum.weight.setPoint(1, sf::Vector2f(120, 400));
	pendulum.weight.setPoint(2, sf::Vector2f(160, 440));
	pendulum.weight.setPoint(3, sf::Vector2f(40, 440));
	pendulum.weight.setPoint(4, sf::Vector2f(80, 400));
	pendulum.weight.setFillColor(Color::Black);
	pendulum.weight.setOrigin(100, 100);
	pendulum.weight.setPosition(PENDULUM_POS);
	pendulum.speed = 2;
	pendulum.rotation = 30;
}
void UpdateConstruction(StructPendulum& pendulum, StructMechanism& mechanism)
{
	pendulum.weight.setRotation(pendulum.rotation);
	pendulum.turn.setRotation(pendulum.rotation);
	mechanism.big.setRotation(-pendulum.rotation);
	mechanism.small.setRotation(ANGLE + pendulum.rotation);
};
void SetPhysics(StructPendulum& pendulum)
{
	if (pendulum.rotation > 0)
	{
		pendulum.speed -= ACCELERATION;
	}
	else pendulum.speed += ACCELERATION;
	pendulum.rotation += pendulum.speed;
};
void RunProgram(RenderWindow& window)
{
	loadImage(gear1, "../img/gearbig.png");
	loadImage(gear2, "../img/gearbig.png");
	InitializePendulum(pendulum);
	InitializeGear(mechanism, gear1, gear2);
	Clock clock;
	int time;
	while (window.isOpen())
	{
		window.clear(Color::White);
		time = clock.getElapsedTime().asMilliseconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (time >= TIME_FRAME)
		{
			clock.restart();
			SetPhysics(pendulum);
			UpdateConstruction(pendulum, mechanism);
		}
		Draw(window, mechanism, pendulum);
		window.display();
	}
}
int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "CLOCK", sf::Style::Default, settings);
	RunProgram(window);

}