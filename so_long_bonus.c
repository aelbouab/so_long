/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:13:26 by aelbouab          #+#    #+#             */
/*   Updated: 2024/03/03 13:29:50 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void write_err_bonus(char *str)
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
		name_error_bonus(line);
		maps = maps_s_bonus(line);
		if (!maps)
			write_err_bonus("empty or not existe file");
		lines = ft_split(maps, '\n');
		parssing_bonus(lines, maps);
		pp = player_pous_bonus(lines, 0);
		lines = floodfill_bonus(lines, pp.y, pp.x);
		flood_test_bonus(lines);
		drowing_bonus(maps);
	}
}
