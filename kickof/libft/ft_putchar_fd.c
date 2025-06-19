#include <unistd.h>  // write

// ft_putchar_fd: A function that writes a single character to a file descriptor.
// It uses the write system call to output the character.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
int	main(void)
{
	ft_putchar_fd('A', 1); // stdout'a 'A' yazar
	ft_putchar_fd('\n', 1); // newline
	return (0);
}
