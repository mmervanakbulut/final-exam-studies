#include <unistd.h>
#include <stdio.h>  // printf için (test amaçlı)

// ft_putnbr_fd: A function that writes an integer to a file descriptor.
// It handles negative numbers and uses recursion to print each digit.
// The function takes an integer and a file descriptor as arguments.
// It converts the integer to a long to handle the edge case of INT_MIN.
void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	nb = nb % 10 + '0';
	write(fd, &nb, 1);
}
int	main(void)
{
	int	number = -12345;

	// Sayıyı standart çıktıya yazdır
	ft_putnbr_fd(number, 1);

	// Yeni satır ekleyelim ki çıktı daha düzenli olsun
	write(1, "\n", 1);

	return (0);
}