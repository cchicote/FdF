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

// void		draw_grid(t_draw *d, t_env *e, t_val *v)
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	while (++i < v->f_height -1)
// 	{
// 		j = -1;
// 		while (++j < v->f_len - 1)
// 		{
// 			d->x1 = j * v->f_len + 200;				// Grille horizontale
// 			d->y1 = i * v->f_height - v->tab[i][j] + 200;
// 			d->x2 = (j + 1) * v->f_len + 200;
// 			d->y2 = i * v->f_height - v->tab[i][j + 1] + 200;
// 			line(d, e);
// 			d->x1 = j * v->f_len + 200; 				// Grille verticale
// 			d->y1 = i * v->f_height - v->tab[i][j] + 200;
// 			d->x2 = j * v->f_len + 200;
// 			d->y2 = (i + 1) * v->f_height - v->tab[i + 1][j] + 200;
// 			line(d, e);
// 		}
// 	}
// }
//ICI COMMENCE L'ISOMETRIQUE
// void		draw_grid(t_env *e)
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	while (++i < e->f_height -1)
// 	{
// 		j = -1;
// 		while (++j < e->f_len - 1)
// 		{
// 			e->x1 = (j * 10 - (i * 10)) + 300; // grille horizontale
// 			e->y1 = (j * 10 + (i * 10)) - e->tab[i][j] / 2 + 300;
// 			e->x2 = ((j + 1) * 10 - (i * 10)) + 300;
// 			e->y2 = ((j + 1) * 10 + (i * 10)) - e->tab[i][j + 1] / 2 + 300;
// 			draw_1(e, 0xFFFFFF);


// 			e->x1 = (j * 10 - (i * 10)) + 300; // grille verticale
// 			e->y1 = (j * 10 + (i * 10)) - e->tab[i][j] / 2 + 300;
// 			e->x2 = (j * 10 - ((i + 1) * 10)) + 300;
// 			e->y2 = (j * 10 + ((i + 1) * 10)) - e->tab[i + 1][j] / 2 + 300;
// 			draw_1(e, 0xFFFFFF);
// 		}
// 	}
// 	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
// 	mlx_loop(e->mlx);
// }

int			get_color(int h)
{
	if (h == 0)
		return (0xFFFFFF);
	if (h > 5)
		return (0xFF0000);
	if (h < 0)
		return (0x0000FF);
	if (h > 0 && h < 5)
		return (0xFFFF00);
	return (0xFFFFFF);
}

void		draw_grid(t_env *e)
{
	int i;
	int j;

	i = -1;
	while (++i < e->f_height -1)
	{
		j = -1;
		while (++j < e->f_len - 1)
		{
			e->x1 = (j * e->size) - (i * e->size - e->tab[i][j]) + e->posx;
			e->y1 = ((j * e->size) + (i * e->size)) / e->inc - e->tab[i][j] + e->posy;
			e->x2 = ((j + 1) * e->size) - (i * e->size - e->tab[i][j + 1]) + e->posx;
			e->y2 = (((j + 1) * e->size) + (i * e->size)) / e->inc - e->tab[i][j + 1] + e->posy;
			draw_1(e, get_color(e->tab[i][j]));
			
			e->x1 = (j * e->size) - (i * e->size - e->tab[i][j]) + e->posx;
			e->y1 = ((j * e->size) + (i * e->size)) / e->inc - e->tab[i][j] + e->posy;
			e->x2 = (j * e->size) - ((i + 1) * e->size - e->tab[i + 1][j]) + e->posx;
			e->y2 = ((j * e->size) + ((i + 1) * e->size)) / e->inc - e->tab[i + 1][j] + e->posy;
			draw_1(e, get_color(e->tab[i][j]));
		}
	}
	ft_putendl("let's draw");
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}



// x_iso = (x - y)
// y_iso = (x + y) / 3 ou si on veut : y_iso = (x + y) / 2 