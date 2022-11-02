#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 1

char *copy_up_to_newline(char *dest, char *src)
{
    int i;
    int len;
    i = 0;
    len = 0;
    while (src[i] != '\n')
        i++;
    dest = malloc(sizeof(char) * (i + 2));
    while (len <= i)
    {
        dest[len] = src[len];
        len++;
    }
    dest[len] = '\0';
    return (dest);
}
int    ft_strlen(char const *str)
{
    int    i;
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
int    check_newline(char *buf)
{
    int i;
    i = 0;
    while (buf[i] != '\0')
    {
        if (buf[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}
void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t    i;
    i = 0;
    if (!dest && !src)
        return (0);
    while (i < n)
    {
        ((char *)dest)[i] = ((char *)src)[i];
        i++;
    }
    return (dest);
}
char *ft_read(char *dest, char *src, int location)
{
  dest = malloc(sizeof(char) * BUFFER_SIZE + 1);
  dest[0] = src[location];
  dest[1] = '\0';
  return (dest);
}
char    *get_next_line(char *string)
{
    static char *buf;
    static char *retstr;
    static char *tmp;
    int i;
    int j;
    int k;
    static int location;
    i = 0;
    j = 1;
    k = 0;
    location = 0;
    buf = ft_read(buf, string, location);
    while (j != 0 && (check_newline(buf) == 0))
    {
        buf = ft_read(buf, string, location);
        location++;
        if (!retstr)
        {
            retstr = malloc(sizeof(char) * (ft_strlen(buf) + 1));
            ft_memcpy(retstr, buf, (ft_strlen(buf) + 1));
        }
        else
        {
                tmp = malloc(sizeof(char) * (ft_strlen(retstr) + 1));
                ft_memcpy(tmp, retstr, (ft_strlen(retstr) + 1));
                k = ft_strlen(tmp);
                retstr = malloc(sizeof(char) * (BUFFER_SIZE + ft_strlen(retstr) + 1));
                ft_memcpy(retstr, tmp, (ft_strlen(tmp) + 1));
                while (buf[i] != '\0')
                {
                    retstr[k] = buf[i];
                    if (buf[i] == '\n')
                    {
                        retstr[k + 1] = '\0';
                        break;
                    }
                    i++;
                    k++;
                }
                if (buf[i] != '\n')
                  retstr[k] = '\0';
                i = 0;
        }
    }
    tmp = copy_up_to_newline(tmp, retstr);
    return tmp;
}

int    main()
{
    get_next_line("Hel\nGoo.\n");
    get_next_line("Hel\nGoo.\n");
}
