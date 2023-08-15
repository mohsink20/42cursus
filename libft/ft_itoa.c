#include "libft.h"

static size_t ft_abs(int n)
{
    if (n < 0)
        return -n;
    return n;
}

static size_t ft_intlen(int n)
{
    size_t len = 0;
    if (n < 0)
        len = 1;
    
    while (1)
    {
        len++;
        if (!(n / 10))
            break;
        n /= 10;
    }
    
    return len;
}

char *ft_itoa(int n)
{
    int negative = 0;
    
    if (n < 0)
        negative = 1;
    
    int i = -1;
    
    if (!negative)
        i = 0;
    
    int count = (int)ft_intlen(n);
    char *buffer = (char *)ft_calloc(count + 1, sizeof(char));
    
    if (buffer == NULL)
        return NULL;
    
    if (negative)
    {
        buffer[0] = '-';
    }
    else
    {
        i = 0;
    }
    
    while (++i < count)
    {
        int digit = ft_abs(n % 10);
        buffer[count - (!negative) - i] = "0123456789"[digit];
        n /= 10;
    }
    
    buffer[count] = '\0';
    return buffer;
}
