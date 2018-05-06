/*
** EPITECH PROJECT, 2018
** term.c
** File description:
** Display messages on terminal
*/

#include "player.h"
#include "duck.h"

void	term_score(int score)
{
	my_putstr("SCORE: ");
	my_put_nbr(score);
	my_putchar('\n');
}

void	term_lives_left(int lives)
{
	if (lives == 0) {
		my_putstr("G A M E\n O V E R\nYou died hunted by the duck.");
	} else {
		my_putstr("Oops! ");
		my_put_nbr(lives);
		my_putstr((lives == 1) ? " life" : " lives");
		my_putstr(" left! ");
	}
	my_putchar('\n');
}

