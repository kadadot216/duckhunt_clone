/*
** EPITECH PROJECT, 2018
** random.h
** File description:
** Header file for random.c
*/

#ifndef __RANDOM_H__
#define __RANDOM_H__

#include "window.h"
#include <SFML/Graphics/RenderWindow.h>

float	spawn_rand(int limit);
float	rand_y(float min, float max);
float	spawn_choice(int choice1, int choice2);

#endif
