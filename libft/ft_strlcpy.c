#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	if(!src)
		return(0);
	if(dsize)
	{
		while(i < dsize - i && src[i])
		{
			dest[i] = src[i];
			++i;
		}
		dest[i] = '\0';
	}
	while(src[i])
		++i;
	return (i);
}
/*
int main()
{
    char dest[20];
    const char *src = "Hello, world!";
    size_t dsize = 10;  // Destination buffer size

    size_t result = ft_strlcpy(dest, src, dsize);

    printf("Result: %zu\n", result);
    printf("Destination string: %s\n", dest);

    return 0;
}
*/
