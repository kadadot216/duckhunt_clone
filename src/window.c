#include "window.h"

window_t	create_window(unsigned int width, unsigned int height,
unsigned int depth, char *title)
{
	window_t	new;

	new.title = my_strdup(title);
	new.mode.width = width;
	new.mode.height = height;
	new.mode.bitsPerPixel = depth;
	new.render = sfRenderWindow_create(new.mode, new.title,
	sfResize | sfClose, NULL);
	new.bg = set_bg();
	sfRenderWindow_setFramerateLimit(new.render, 60);
	return (new);
}

int		destroy_window(window_t *win)
{
	win->mode.width = 0;
	win->mode.height = 0;
	win->mode.bitsPerPixel = 0;
	sfRenderWindow_destroy(win->render);
	if (win->render)
		return (-1);
	free(win->title);
	if (win->title)
		return (-1);
	return (0);
}

void	close_window(sfRenderWindow *window)
{
	sfRenderWindow_close(window);
}

bg_t	set_bg(void)
{
	bg_t	bg;

	bg.texture = sfTexture_createFromFile(BG_PATH, NULL);
	bg.sprite = sfSprite_create();
	sfSprite_setTexture(bg.sprite, bg.texture, sfFalse);
	return (bg);
}

void	unset_bg(bg_t *bg)
{
	sfTexture_destroy(bg->texture);
	sfSprite_destroy(bg->sprite);
}
