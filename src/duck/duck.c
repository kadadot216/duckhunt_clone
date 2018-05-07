#include "my.h"
#include "gameobjects.h"
#include "random.h"

duck_t	setup_duck(void)
{
	duck_t	duck;

	duck.hitbox.top = 0;
	duck.hitbox.left = 0;
	duck.hitbox.width = DUCK_WIDTH;
	duck.hitbox.height = DUCK_HEIGHT;
	duck.status = HIDDEN;
	duck.direction = RIGHT;
	duck.texture = sfTexture_createFromFile(PICPATH, NULL);
	duck.sprite = sfSprite_create();
	duck.timer = init_timer();
	duck.spawntimer = init_timer();
	duck.speed.x = 0.0;
	duck.speed.y = 0.0;
	sfSprite_setTexture(duck.sprite, duck.texture, sfFalse);
	return (duck);
}

void	enable_duck(duck_t *duck, player_t *player)
{
	if (duck->status == HIDDEN)
		duck->status = VISIBLE;
	duck->position.x = spawn_rand(800 - DUCK_HEIGHT);
	duck->position.y = spawn_choice(0, 600 - DUCK_WIDTH);
	duck->anim_speed = (FRAME_DURATION - speed_variation());
	sfSprite_setPosition(duck->sprite, duck->position);
	duck->status = VISIBLE;
	duck->direction = RIGHT;
	duck->hitbox.width = DUCK_WIDTH;
	duck->hitbox.height = DUCK_HEIGHT;
	duck->speed.x = 4.8 + ((double) player->score / 100.0);
	duck->speed.y = rand_y(-6.0, 6.0);
	player->scope.x = OOR;
	player->scope.y = OOR;
}

void	disable_duck(duck_t *duck)
{
	if (duck->status == VISIBLE)
		duck->status = HIDDEN;
	duck->hitbox.width = 0;
	duck->hitbox.height = 0;
	duck->speed.x = 0;
	duck->speed.y = 0;
	sfClock_restart(duck->spawntimer.clock);
}

int	remove_duck(duck_t *duck)
{
	sfTexture_destroy(duck->texture);
	sfSprite_destroy(duck->sprite);
	return (1);
}
