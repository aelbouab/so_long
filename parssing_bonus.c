/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:00:18 by aelbouab          #+#    #+#             */
/*   Updated: 2024/03/03 13:28:13 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_control(char *maps, char **lines, int l)
{
	int	i;
	int	j;
	int	ls;

	i = 0;
	j = 0;
	ls = map_len(lines);
	ls = (ls * (l + 1));
	while (maps[i])
	{
		if ((maps[i] == '\n' && maps[i + 1] == '\n')
			|| maps[0] == '\n' || maps[ls - 1] == '\n')
			write_err_bonus("don't include empty lines");
		if (maps[i] != 'P' && maps[i] != 'E'
			&& maps[i] != 'C' && maps[i] != '1'
			&& maps[i] != '0' && maps[i] != 'M'
			&& maps[i] != 'Q' && maps[i] != '\n')
			write_err_bonus("there is some unknown chars");
		i++;
	}
}

static void	wall_error(char **lines)
{
	int	i;
	int	ls;

	i = 0;
	while (lines[0][i])
	{
		if (lines[0][i] != '1')
			write_err_bonus("Map must be enclosed by walls");
		i++;
	}
	i = 0;
	ls = line_len(lines[i]);
	while (lines[i])
	{
		if (lines[i][0] != '1' || lines[i][ls - 1] != '1')
			write_err_bonus("Map must be enclosed by walls");
		i++;
	}
	i = -1;
	ls = map_len(lines);
	while (lines[ls - 1][++i])
	{
		if (lines[ls - 1][i] != '1')
			write_err_bonus("Map must be enclosed by walls");
	}
}

void	name_error_bonus(char *name)
{
	int	ls;

	ls = line_len(name) - 1;
	if (name[ls] != 'r' || name[ls - 1] != 'e'
		|| name[ls - 2] != 'b' || name[ls - 3] != '.')
		write_err_bonus("map must be *.ber");
}

static void	items_error(char **lines, int p, int e, int c)
{
	int	i;
	int	j;
	int	m;

	i = -1;
	j = 0;
	m = 0;
	while (lines[++i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'P')
				p++;
			else if (lines[i][j] == 'E')
				e++;
			else if (lines[i][j] == 'C')
				c++;
			else if (lines[i][j] == 'M')
				m++;
			j++;
		}
	}
	if (p != 1 || e != 1 || c < 1 || m < 1)
		write_err_bonus("you need 1P & 1E & at less 1 C & M");
}

void	parssing_bonus(char **lines, char *maps)
{
	len_check(lines);
	map_control(maps, lines, line_len(lines[0]));
	wall_error(lines);
	items_error(lines, 0, 0, 0);
	if (line_len(*lines) > 136 || map_len(lines) > 136)
		write_err_bonus("map is to big");
}
