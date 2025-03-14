#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dup;

	// src dizisinin uzunluğunu hesapla
	len = 0;
	while (src[len])
		len++;

	// src uzunluğu kadar +1 (null karakter için) bellek tahsis et
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup) // malloc başarısız olursa NULL döndür
		return (NULL);

	// src içeriğini dup'a kopyala
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}

	// Sonuna null karakter ekleyerek stringi sonlandır
	dup[i] = '\0';

	// Kopyalanmış stringin adresini döndür
	return (dup);
}
