#ifndef __GAMEWINDOW_H__
#define __GAMEWINDOW_H__

#include <SFML/Graphics.h>
#include "my.h"

void	manage_mouse_click(sfMouseButtonEvent event);
void	close_window(sfRenderWindow *window);
void	analyse_events(sfRenderWindow *window, sfEvent event);

#endif
