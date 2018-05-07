#include "player.h"
#include "duck.h"
#include "my.h"

int	within_range_of_duck(int x, int y, sfVector2f pos)
{
	if ((x >= pos.x) && (x <= pos.x + DUCK_WIDTH) &&
		(y >= pos.y && y <= pos.y + DUCK_HEIGHT))
		return (1);
	else
		return (0);
}

player_t	setup_player(void)
{
	player_t	player;

	player.lives = 5;
	player.score = 0;
	player.scope.x = OOR;
	player.scope.y = OOR;
	player.life_sprite = sfSprite_create();
	player.life_text = sfTexture_createFromFile("./assets/life.png", NULL);
	sfSprite_setTexture(player.life_sprite, player.life_text, sfFalse);
	return (player);
}

mousescope_t	player_shoot(int x, int y)
{
	mousescope_t	pos = {x, y};

	return (pos);
}

void	score_points(int *score)
{
	*score += 100;
}

