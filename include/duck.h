#ifndef __DUCK_H__
#define __DUCK_H__

#include <SFML/Graphics.h>
#include "my.h"
#include "player.h"
#include "timer.h"
#include "window.h"

#define	DUCK_HEIGHT (100)
#define	DUCK_WIDTH (135)
#define	DUCK_FRAMES (10)
#define SPRITE_LENGTH (DUCK_WIDTH * DUCK_FRAMES)
#define	FRAME_DURATION (0.015)

#define PICPATH "assets/rareparrot.png"

struct duck_s {
	enum status_e {
		VISIBLE,
		HIDDEN
	} status;
	enum direction_e {
		LEFT = 1,
		RIGHT = -1
	} direction;
	double		anim_speed;
	sfSprite	*sprite;
	sfTexture	*texture;	
	sfIntRect	hitbox;
	sfVector2f	position;
	sfVector2f	speed;
	gametimer_t	timer;
	gametimer_t	spawntimer;
};

typedef struct duck_s	duck_t;

int		remove_duck(duck_t *duck);
void		move_rect(duck_t *duck, int offset, int max_value);
void		anim_duck(duck_t *duck, sfRenderWindow *window);
sfVector2f	get_sp_position(sfSprite *sprite);
void		move_duck(duck_t *duck, window_t *window);
duck_t		setup_duck(void);
void	enable_duck(duck_t *duck, player_t *player);
void	disable_duck(duck_t *duck);
int	is_within(int x, int after, int before);
int	is_within_duck(mousescope_t *scope, sfVector2f *duckpos);

#endif
