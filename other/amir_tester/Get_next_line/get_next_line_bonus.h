/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:12:16 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/22 18:12:28 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strchr_gnl(char *s, int c);
void	remove_last_line(char *buffer);
int		is_end_of_line(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	get_line(char *line, char *buffer);

#endif
