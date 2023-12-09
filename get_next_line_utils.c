/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:29:47 by sonia             #+#    #+#             */
/*   Updated: 2023/12/09 15:24:28 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	size_t	size_src;
	int		i;

	size_src = ft_strlen(src);
	str = malloc((size_src + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		str[i] = ((char *)src)[i];
		i++;
	}
	str[i] = '\0';
//	free(src);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*newstr;
	unsigned int	i;
	unsigned int	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (newstr == NULL)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		newstr[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	newstr[i + 1] = '\0';
	free(s1);
	return (newstr);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;

	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
