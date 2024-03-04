/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:14:49 by aelbouab          #+#    #+#             */
/*   Updated: 2024/03/03 13:13:46 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void write_err(char *str)
{
	write(2, "Error\n", 6);
	ft_putstr_fd(str, 2);
	exit (1);
}

int	main(int ac, char **av)
{
	char	*line;
	char	*maps;
	char	**lines;
	t_pos	pp;

	if (ac == 2)
	{
		line = av[1];
		name_error(line);
		maps = maps_s(line);
		if (!maps)
			write_err("empty or not existe file");
		lines = ft_split(maps, '\n');
		parssing(lines, maps);
		pp = player_pous(lines, 0);
		lines = floodfill(lines, pp.y, pp.x);
		flood_test(lines);
		drowing(maps);
	}
}
