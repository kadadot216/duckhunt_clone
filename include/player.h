#ifndef __PLAYER_H__
#define __PLAYER_H__

#define LIVES (3)
#define OOR (-1)

#include <SFML/Graphics.h>

typedef struct mousescope_s {
	int	x;
	int	y;
} mousescope_t;

typedef struct player_s {
	int		lives;
	int		score;
	sfSprite	*life_sprite;
	sfTexture	*life_text;
	mousescope_t	scope;
} player_t;

mousescope_t	player_shoot(int x, int y);
player_t	setup_player(void);
void	score_points(int *score);

#endif
