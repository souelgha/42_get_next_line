/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:11:18 by sonouelg          #+#    #+#             */
/*   Updated: 2023/12/07 18:09:38 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* recup des données de read sur le buffer => fait */
/*regarder ce qu'il y a dans le buffer si pas de n continuer sinon arreter => fait */
/* le placer dans une string de type strjoin => fait */
/*identifier la position de \n et couper la string en 2*/
/*puis le mettre dans une autre string*/
#include"get_next_line.h"
/***************************************************************************************/
/*******************lire le buffer et renvoyer la string lue via strjoin****************/
/***************************************************************************************/
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
/****************************************************************************************/
/********************retirer tout ce qui arrive apres le \n******************************/
/****************************************************************************************/
char	*ft_line(char *strread)
{
	int		i;
	char	*line;

	i = 0;
	while (strread[i] != '\0' && strread[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (strread[i] != '\0' && strread[i] != '\n')
	{
		line[i] = strread[i];
		i++;
	}
	if (strread[i] == '\n')
	{
		line[i] = strread[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
/****************************************************************************************/
/********recuperer les char apres le \n et l utiliser pour le next line******************/
/****************************************************************************************/
char	*ft_nextline(char *strread)
{
	int		i;
	int		j;
	char	*nextline;

	i = 0;
	j = 0;
	while (strread[i] != '\0' && strread[i] != '\n')
		i++;
//	printf("i=%d\n", i);
//	printf("long_str=%zu\n", ft_strlen(strread));
	i++;
	nextline = malloc(sizeof(char) * (ft_strlen(strread) -i + 1));
	if (nextline == NULL)
		return (NULL);
	while (strread[i] != '\0')
	{
		nextline[j] = strread[i];
		i++;
		j++;
	}
	nextline[j] = '\0';
//	printf("long_nextstr=%zu\n", ft_strlen(nextline));
	return (nextline);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char		*line;
	
	buffer =ft_readbuffer(fd, buffer);
	printf("lineread=%s\n", buffer);
	line =ft_line(buffer);
	printf("line=%s", line);
	buffer =ft_nextline(buffer);
	printf("nextline=%s", buffer);
	return(line);
	
}
int main(void)
{
	int 	fd;
	char	*line;
	char 	*file = "file.txt";
    fd = open(file, O_RDWR);	
	printf("fd=%d\n",fd);	
	line = get_next_line(fd);
	printf("line main=%s\n",line);
	close(fd);
	// free(newstr);
	// free(line);
	return(0);
}
	// newstr = ft_readbuffer(fd);
	// printf("newstr=%s\n", newstr);
	// 
	