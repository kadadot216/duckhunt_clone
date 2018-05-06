/*
** EPITECH PROJECT, 2018
** my_getbase_nbr.c
** File description:
** Converts a decimal int into its base representation
*/

#include "my.h"

char	*my_getbase_nbr(int nb, char const *base_to)
{
	int	maxpow = 0;
	int	i = 0;
	int	baselen = my_strlen(base_to);
	char	*result;

	while (nb >= my_compute_power_rec(baselen, maxpow))
		maxpow++;
	result = malloc(sizeof(char *) * (maxpow + 1));
	while (i < maxpow) {
		result[maxpow-i-1] = base_to[nb % baselen];
		nb /= baselen;
		i++;
	}
	result[maxpow] = '\0';
	return (result);
}
