/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:34:52 by cchicote          #+#    #+#             */
/*   Updated: 2016/02/25 19:40:10 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_1(t_env *e, int color)
{
	int		dx;
	int		dy;

	dy = 0;
	if ((dx = e->x2 - e->x1) != 0)
	{
		if (dx > 0)
			draw_2(e, dx, dy, color);
		else
			draw_3(e, dx, dy, color);
	}
	else
	{
		if ((dy = e->y2 - e->y1) != 0)
		{
			if (dy > 0)
			{
				while (e->y1++ != e->y2)
					my_pixel_put(e, e->x1, e->y1, color);
			}
			else
			{
				while (e->y1-- != e->y2)
					my_pixel_put(e, e->x1, e->y1, color);
			}
		}
	}
}

void		draw_2(t_env *e, int dx, int dy, int color)
{
	if ((dy = e->y2 - e->y1) != 0)
	{
		if (dy > 0)
		{
			if (dx >= dy)
				oct_1(e, dx, dy, color);
			else
				oct_2(e, dx, dy, color);
		}
		else
		{
			if (dx >= -dy)
				oct_8(e, dx, dy, color);
			else
				oct_7(e, dx, dy, color);
		}
	}
	else
	{
		while (e->x1++ != e->x2)
			my_pixel_put(e, e->x1, e->y1, color);
	}
}

void		draw_3(t_env *e, int dx, int dy, int color)
{
	if ((dy = e->y2 - e->y1) != 0)
	{
		if (dy > 0)
		{
			if (-dx >= dy)
				oct_4(e, dx, dy, color);
			else
				oct_3(e, dx, dy, color);
		}
		else
		{
			if (dx <= dy)
				oct_5(e, dx, dy, color);
			else
				oct_6(e, dx, dy, color);
		}
	}
	else
	{
		while (e->x1-- != e->x2)
			my_pixel_put(e, e->x1, e->y1, color);
	}
}