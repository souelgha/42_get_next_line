#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE _H 

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 7
#endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_readbuffer(int fd, char *str);
char	*ft_strrchr(const char *str, int c);
char	*ft_strchr(const char *str, int c);
char	*ft_line(char *stringread);
char	*get_next_line(int fd);

#endif