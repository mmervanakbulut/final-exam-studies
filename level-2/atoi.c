#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_atoi(const char *s)
{
	int		sign = 1;
	int	result = 0;

	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	return ((int)(result * sign));
}


int		main(void)
{
	printf("%d\n", ft_atoi("123456789"));
	printf("%d\n", atoi("123456789"));
	return (0);
}