/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:34:52 by cchicote          #+#    #+#             */
/*   Updated: 2016/02/25 19:40:10 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		vertical(t_draw *d, t_env *e)
{
	float	x;
    float	a;
    float	b;
    float	y_start;
    float	y_end;
    
    y_start = (d->y1 < d->y2) ? d->y1 : d->y2;
    y_end = (d->y1 < d->y2) ? d->y2 : d->y1;
    a = (d->x2 - d->x1) / (y_end - y_start);
    b = d->x1 - a * d->y1;
    while (y_start++ <= y_end)
    {
    	x = a * y_start + b;
        mlx_pixel_put(e->mlx, e->win, (int)x, y_start, 0xFFFFFF);
    }
}

void		line(t_draw *d, t_env *e)
{
	float	y;
	float	a;
	float	b;
	float	x_start;
	float	x_end;

	x_start = (d->x1 < d->x2) ? d->x1 : d->x2;
	x_end = (d->x1 < d->x2) ? d->x2 : d->x1;
	a = (d->y2 - d->y1) / (x_end - x_start);
	b = d->y1 - a * d->x1;
	if (a > 1 || a < -1)
		vertical(d, e);
	else
	{
		while (x_start++ <= x_end)
		{
			y = a * x_start + b;
			mlx_pixel_put(e->mlx, e->win, x_start, (int)y, 0xFFFFFF);
		}
	}
}
