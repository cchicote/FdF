/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:34:52 by cchicote          #+#    #+#             */
/*   Updated: 2016/02/25 19:40:10 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			get_color(int h)
{
	if (h == 0)
		return (0x4682b4);
	else if (h >= 15)
		return (0xff4000);
	else if (h < 0)
		return (0x191970);
	else if (h > 0 && h < 5)
		return (0xffa500);
	else if (h >= 5 && h < 15)
		return (0xff8000);
	return (0xFFFFFF);
}

void		draw_vert(t_env *e, int i, int j)
{
	e->x1 = (j * e->size) - (i * e->size) + e->posx;
	e->y1 = ((j * e->size) + (i * e->size))
	/ e->inc - e->tab[i][j] * e->z + e->posy;
	e->x2 = (j * e->size) - ((i + 1) * e->size) + e->posx;
	e->y2 = ((j * e->size) + ((i + 1) * e->size))
	/ e->inc - e->tab[i + 1][j] * e->z + e->posy;
	draw_1(e, get_color(e->tab[i][j]));
}

void		draw_hori(t_env *e, int i, int j)
{
	e->x1 = (j * e->size) - (i * e->size) + e->posx;
	e->y1 = ((j * e->size) + (i * e->size))
	/ e->inc - e->tab[i][j] * e->z + e->posy;
	e->x2 = ((j + 1) * e->size) - (i * e->size) + e->posx;
	e->y2 = (((j + 1) * e->size) + (i * e->size))
	/ e->inc - e->tab[i][j + 1] * e->z + e->posy;
	draw_1(e, get_color(e->tab[i][j]));
}

void		draw_grid(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < e->f_height - 1)
	{
		j = -1;
		while (++j < e->f_len - 1)
		{
			draw_hori(e, i, j);
			draw_vert(e, i, j);
		}
	}
	ft_putendl("loading : 100% : let's draw !");
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
