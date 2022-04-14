/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylambark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:09:51 by ylambark          #+#    #+#             */
/*   Updated: 2022/02/23 11:37:15 by ylambark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<fcntl.h>
# include<stdlib.h>
# include<unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
int		ft_strchr(char *s1, char c);
char	*ft_strjoin(char *s1, char *s2);

#endif
