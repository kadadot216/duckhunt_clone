#ifndef __MY_H__
#define __MY_H__

#include <stdlib.h>
#include <unistd.h>

int	my_strlen(const char *str);
char	*my_strdup(const char *str);
void	my_putchar(char c);
int	my_put_nbr(int nb);
void	my_putstr(const char *str);
int	my_compute_power_rec(int nb, int p);
char	*my_getbase_nbr(int nb, char const *base_to);


#endif
