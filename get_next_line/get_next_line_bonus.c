/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylambark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 07:45:17 by ylambark          #+#    #+#             */
/*   Updated: 2022/02/24 14:33:25 by ylambark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_all(int fd, char *text)
{
	ssize_t	i;
	char	*line;

	line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (0);
	i = 1;
	while (!(ft_strchr(text, '\n')) && i != 0)
	{
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
		{
			free(line);
			return (0);
		}
		line[i] = '\0';
		text = ft_strjoin(text, line);
	}
	free(line);
	return (text);
}

char	*get_line(char *text)
{
	char	*newtext;
	size_t	len;
	size_t	j;

	len = 0;
	j = 0;
	if (text[0] == '\0')
		return (NULL);
	while (text[len] != '\n' && text[len] != '\0')
		len++;
	if (text[len] == '\n')
		len++;
	newtext = (char *)malloc(len + 1);
	if (!newtext)
		return (0);
	while (j < len)
	{
		newtext[j] = text[j];
		j++;
	}
	newtext[j] = '\0';
	return (newtext);
}

char	*new_txt(char *text)
{
	char	*newtxt;
	size_t	k;
	size_t	i;

	k = 0;
	i = 0;
	while (text[k] != '\n' && text[k] != '\0')
		k++;
	if (!text[k])
	{
		free(text);
		return (0);
	}
	newtxt = (char *)malloc(ft_strlen(text) - k + 1);
	if (!newtxt)
		return (0);
	while (text[k++])
		newtxt[i++] = text[k];
	newtxt[i] = '\0';
	free(text);
	return (newtxt);
}

char	*get_next_line(int fd)
{
	static char	*text[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	text[fd] = read_all(fd, text[fd]);
	if (!text[fd])
		return (0);
	line = get_line(text[fd]);
	text[fd] = new_txt(text[fd]);
	return (line);
}
