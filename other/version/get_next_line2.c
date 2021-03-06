/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:01:42 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/06 17:50:35 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_end_of_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0') 
	{
		if (str[i] == '\n' || str[i] == EOF)
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(int fd)
{
	char	*buffer;
	char	*str;
	int		i;
	int		test;

	i = 0;
	str = calloc(BUFFER_SIZE + 1, sizeof(char));
	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	while (buffer[i] != '\n' && buffer[i] != EOF && buffer[i])
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		str[i] = '\n';
	if (buffer[i] == EOF)
		str[i] = EOF;
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*str_2;
	char		*result;
	int			buffer_size_nbr;

	buffer_size_nbr = 0;
	str = get_line(fd);
	while (!(check_end_of_line(str)))
	{
		printf("test\n");
		str_2 = get_line(fd);
		str = ft_strjoin(str, str_2);
		free(str_2);
	}
	return (str);
}

int	main(void)
{
	int		fd;
	int		i = 1;
	char	*str;

	fd = open("./file", O_RDONLY);
	if (fd > 0)
	{
		str = get_next_line(fd);
		printf("Line %d = %s", i++, str);
		str = get_next_line(fd);
		printf("Line %d = %s", i++, str);
		// str = get_next_line(fd);
		// printf("Line %d = %s", i++, str);
		// str = get_next_line(fd);
		// printf("Line %d = %s", i++, str);
		close(fd);
		free(str);
	}
	return (0);
}
