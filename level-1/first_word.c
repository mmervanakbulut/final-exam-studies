#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
int		main(int ac, char **av)
{
	if (ac == 2)
	{
		while (*av[1] && (*av[1] == ' ' || *av[1] == '\t'))
			++av[1];
		while (*av[1] != '\0' && (*av[1] != ' ' && *av[1] != '\t'))
			write(1, av[1]++, 1);
	}
	ft_putchar('\n');
	return (0);
}