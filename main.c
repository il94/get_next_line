/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:45:36 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/22 18:39:36 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		i = 0;
	int		number_of_lines = 15;
	char	*str;

	fd = open("./file/file", O_RDONLY);
	if (fd >= 0)
	{
		while (i < number_of_lines)
		{
			str = get_next_line(fd);
			printf("RESULT Line %d = %s", i + 1, str);
			if (i < number_of_lines)
				free(str);
			i++;
		}
		close(fd);
	}
	return (0);
}
