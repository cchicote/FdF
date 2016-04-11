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

void		draw_grid(t_draw *d, t_env *e, t_val *v)
{
	int i;
	int j;

	i = -1;
	while (++i < v->f_height -1)
	{
		j = -1;
		while (++j < v->f_len - 1)
		{
			d->x1 = j * v->f_len + 200;				// Grille verticale
			d->y1 = i * v->f_height - v->tab[i][j] + 200;
			d->x2 = (j + 1) * v->f_len + 200;
			d->y2 = i * v->f_height - v->tab[i][j + 1] + 200;
			line(d, e);
			d->x1 = j * v->f_len + 200; 				// Grille horizontale
			d->y1 = i * v->f_height - v->tab[i][j] + 200;
			d->x2 = j * v->f_len + 200;
			d->y2 = (i + 1) * v->f_height - v->tab[i + 1][j] + 200;
			line(d, e);
		}
	}
}
