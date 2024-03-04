/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnstr_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:56:27 by aelbouab          #+#    #+#             */
/*   Updated: 2024/03/04 11:25:59 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	m_move_u(t_data	*img, int i, t_mdata *mon)
{
	t_mpos	mp;

	mp = monster_pos(img->lines, -1);
	if (img->lines[mp.x[i] - 1][mp.y[i]] == '0')
	{
		img->lines[mp.x[i]][mp.y[i]] = '0';
		img->lines[mp.x[i] - 1][mp.y[i]] = 'M';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, mp.y[i] * 60, mp.x[i] * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, mon->d_monster, mp.y[i] * 60, (mp.x[i] - 1) * 60);
	}
	else if (img->lines[mp.x[i] - 1][mp.y[i]] == 'P')
		return (write(1, "haha loser", 10), exit (1));
	free (mp.x);
	free (mp.y);
}

void	m_move_d(t_data	*img, int i)
{
	t_mpos	mp;

	mp = monster_pos(img->lines, -1);
	if (img->lines[mp.x[i] + 1][mp.y[i]] == '0')
	{
		img->lines[mp.x[i]][mp.y[i]] = '0';
		img->lines[mp.x[i] + 1][mp.y[i]] = 'M';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, mp.y[i] * 60, mp.x[i] * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->monster, mp.y[i] * 60, (mp.x[i] + 1) * 60);
	}
	else if (img->lines[mp.x[i] + 1][mp.y[i]] == 'P')
		return (write(1, "haha loser", 10), exit (1));
	free (mp.x);
	free (mp.y);
}

void	m_move_r(t_data	*img, int i, t_mdata *mon)
{
	t_mpos	mp;

	mp = monster_pos(img->lines, -1);
	if (img->lines[mp.x[i]][mp.y[i] + 1] == '0')
	{
		img->lines[mp.x[i]][mp.y[i]] = '0';
		img->lines[mp.x[i]][mp.y[i] + 1] = 'M';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, mp.y[i] * 60, mp.x[i] * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, mon->r_monster, (mp.y[i] + 1) * 60, mp.x[i] * 60);
	}
	else if (img->lines[mp.x[i]][mp.y[i] + 1] == 'P')
		return (write(1, "haha loser", 10), exit (1));
	free (mp.x);
	free (mp.y);
}

void	m_move_l(t_data	*img, int i, t_mdata *mon)
{
	t_mpos	mp;

	mp = monster_pos(img->lines, -1);
	if (img->lines[mp.x[i]][mp.y[i] - 1] == '0')
	{
		img->lines[mp.x[i]][mp.y[i]] = '0';
		img->lines[mp.x[i]][mp.y[i] - 1] = 'M';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, mp.y[i] * 60, mp.x[i] * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, mon->l_monster, (mp.y[i] - 1) * 60, mp.x[i] * 60);
	}
	else if (img->lines[mp.x[i]][mp.y[i] - 1] == 'P')
		return (write(1, "haha loser", 10), exit (1));
	free (mp.x);
	free (mp.y);
}
