#include <unistd.h>

void	my_putstr(const char *str)
{
	unsigned int	i = 0;

	while (str[i] != '\0')
		i++;
	write(1, str, i);
}
