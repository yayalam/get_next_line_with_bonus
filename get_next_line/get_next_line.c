/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylambark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:22:30 by ylambark          #+#    #+#             */
/*   Updated: 2022/02/24 14:33:16 by ylambark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_all(int fd, char *text)
{
	char		*line;
	ssize_t		i;

	line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	i = 1;
	while (!(ft_strchr(text, '\n')) && i != 0)
	{
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
		{
			free(line);
			return (NULL);
		}
		line[i] = '\0';
		text = ft_strjoin(text, line);
	}
	free(line);
	return (text);
}

char	*get_line(char	*text)
{
	char	*line;
	size_t	len;
	size_t	y;

	len = 0;
	y = 0;
	if (text[0] == '\0')
		return (NULL);
	while (text[len] != '\n' && text[len] != '\0')
		len++;
	if (text[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (0);
	while (y < len)
	{
		line[y] = text[y];
		y++;
	}
	line[y] = '\0';
	return (line);
}

char	*skip_line(char	*text)
{
	size_t	i;
	size_t	l;
	char	*newtxt;

	i = 0;
	l = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	newtxt = (char *)malloc(ft_strlen(text) - i + 1);
	if (!newtxt)
		return (0);
	while (text[i++])
		newtxt[l++] = text[i];
	newtxt[l] = '\0';
	free(text);
	return (newtxt);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	text = read_all(fd, text);
	if (!text)
		return (NULL);
	line = get_line(text);
	text = skip_line(text);
	return (line);
}
