/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** Allocates memory and copies the string given as argument in it
*/
#include "my.h"

char	*my_strdup(char const *src)
{
	int	len = 0;
	char	*copy;

	while (src[len] != '\0')
		len++;
	copy = malloc(len * sizeof(*src) + 1);
	len = 0;
	while (src[len] != '\0') {
		copy[len] = src[len];
		len++;
	}
	copy[len] = '\0';
	return (copy);
}
