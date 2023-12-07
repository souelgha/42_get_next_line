/* recup des données de read sur le buffer => fait */
/*regarder ce qu'il y a dans le buffer si pas de n continuer sinon arreter => fait */
/* le placer dans une string de type strjoin => fait */
/*identifier la position de \n et couper la string en 2*/
/*puis le mettre dans une autre string*/
#include"get_next_line.h"

char	*ft_readbuffer(int fd, char *str)
{
	char	*buf;
	int		read_bytes;

 	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return(NULL);
	read_bytes = 1;
	while (read_bytes != 0 && (!ft_strchr(str, '\n')))
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] ='\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);    
}

char	*ft_line(char *stringread)
{
	int	i;
	char	*line;

	i = 0;
	while (stringread[i] != '\0' && stringread[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (stringread[i] != '\0' && stringread[i] != '\n')
	{
		line[i] = stringread[i];
		i++;
	}
	if (stringread[i] == '\n')
	{
		line[i] = stringread[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}


int main(void)
{
	int 	fd;
	char	*line;
	char 	*file = "file.txt";
	line = "";
    fd = open(file, O_RDWR);	
	printf("fd=%d\n",fd);	
	printf("buffer_size=%d\n",BUFFER_SIZE);
	line =ft_readbuffer(fd, line);
	line = ft_line(line);

//	line = get_next_line(fd);
	printf("line=%s\n", line);
	close(fd);
	// free(newstr);
	// free(line);
	return(0);
}
	// newstr = ft_readbuffer(fd);
	// printf("newstr=%s\n", newstr);
	// 
	