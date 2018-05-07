#include "window.h"
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>

float	spawn_rand(int limit)
{
	return ((float) (rand() % limit));
}

float	rand_y(float min, float max)
{
	float	scale = rand() / (float) RAND_MAX;

	return	(min + scale * (max - min));
}

int	spawn_choice(int choice1, int choice2)
{
	float	choice = (rand() % ((choice2 - choice1) + 1) + choice1);

	return (choice);
}

float	speed_variation(void)
{
	float	value = ((float) rand() / (float) (RAND_MAX / 2.0f) / 20.0);
	return (value - (value / 2));
}
