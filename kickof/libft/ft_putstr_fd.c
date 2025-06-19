#include <unistd.h>  // write

// ft_putstr_fd: A function that writes a string to a file descriptor.
// It iterates through each character of the string and writes it one by one.
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return;

	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
int	main(void)
{
	ft_putstr_fd("Hello, 42!\n", 1); // stdout'a yazar
	return (0);
}
