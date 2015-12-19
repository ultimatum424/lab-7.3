#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

struct StructImages
{
	Image image;
	String file;
	Texture texture;
	Sprite sprite;
	Vector2i centre;
};
struct StructMechanism
{
	Sprite big;
	Sprite small;
};
struct StructPendulum
{
	ConvexShape turn;
	ConvexShape weight;
	float speed;
	float rotation;
};
const int WINDOW_X = 700;
const int WINDOW_Y = 700;
const float ACCELERATION = 0.3;
const static Vector2f PENDULUM_POS = { 445,195 };
const static Vector2f SMALL_MECHANISM_POS = { 160,335 };
const static Vector2f BIG_MECHANISM_POS = { 302,352 };

const int ANGLE = 6;
const static int TIME_FRAME = 20;

StructImages gear1;
StructImages gear2;
StructPendulum pendulum;
StructMechanism mechanism;
Vector2i centre = { WINDOW_X / 2, WINDOW_Y / 2 };
