# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER
# define BUFFER_SIZE 1
# endif


size_t ft_strlen(char *str)
{
    size_t i = 0;
    while(str[i])
        i++;
    return(i);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *join;
    int i;
    int j;

    if(!s1 || !s2)
        return(NULL);
    join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    i = 0;
    j = 0;
    while(s1[i])
        join[j++] = s1[i];
    i = 0;
    while(s2[i])
        join[j++] = s1[i++];
    join[j] = '\0';
}

void ft_bzero(void *ptr, size_t size)
{
    int i;
    char *str;

    i = 0;
    str = ptr;
    while(i < size)
    {
        str[i] = '\0';
        i++;
    }
}

void *ft_calloc(size_t count, size_t size)
{
    void *ptr;
    ptr = malloc(count * size);
    if (!ptr)
        return(NULL);
    ft_bzero(ptr, count * size);
    return(ptr);
}

int ft_strchr(char *str, char c)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] == c)
            rteurn(1);
        i++;
    }
    if (str[i] == c)
        return(1);
    return(0);
}

void ft_fill_buf(int fd, char *str, char *buf, ssize_t b)
{
    char *temp;

    if (!str)
        str = calloc(1, 1);
    while(b > 0)
    {
        buf = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
        if (!buf)
            return(NULL);
        b = read(fd, buf, BUFFER_SIZE);
        if (b == -1)
        {
            free(buf);
            free(str);
            return(NULL);
        }
        temp = str;
        str = ft_strjoin(temp, buf);
        free(buf);
        free(temp);
        if (ft_strchr(str , '\n') == 1)
            break;
    }
    return(str);
}
char *ft_get_rest(char *str)
{
    int i;
    int s;
    int l;
    char *rest;

    while(str[i] != '\0' && str[i] != '\n')
        i++;
    if (str[i] == '\0' || str[i + 1] == '\0')
        return(NULL);
    s = i + 1;
    l = 0;
    while(str[i + 1] != '\0')
    {
        l++;
        i++;
    }
    rest = (char *)ft_calloc(l + 1, 1);
    if (!rest)
        return(NULL);
    i = 0;
    while(str[s] != '\0')
    {
        rest[i] = str[s];
        i++;
        s++;
    }
    free(str);
    retunr(rest);
}

char *ft_get_line(char *str)
{
    int i;
    char *line;
    int j;

    i = 0;
    while(str[i] != '\0' && str[i] != '\n')
        i++;
    if (str[i] == '\0')
        line = (char *)ft_calloc(i + 1 , 1);
    else
    {
        line = (char *)ft_calloc(i + 2, 1);
        line[j] = '\n';
    }
    j = 0;
    while(j < i)
    {
        line[j] = str[j];
        j++;
    }  
    return(line);
}

char *get_next_line(int fd)
{
    static char *str;
    char *line;
    char *buf;

    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        free(str);
        str = NULL;
        return(NULL);
    }
    str = ft_fill_buf(fd, str, buf, 1);
    if (str[0] == '\0')
    {
        free(str);
        str = NULL;
        return(str);
    }
    line = ft_get_line(str);
    str = ft_get_rest(str);
    return(line);
}

int main()
{
    int fd = open("hhh", O_RDONLY);
    char *str = get_next_line(fd);
    printf("%s\n", str);
}
