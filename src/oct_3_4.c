/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_3_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:34:52 by cchicote          #+#    #+#             */
/*   Updated: 2016/02/25 19:40:10 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		oct_4(t_env *e, int dx, int dy, int color)
{
	int		f;

	f = dx;
	dx = f * 2;
	dy *= 2;
	while (e->x1-- != e->x2)
	{
		my_pixel_put(e, e->x1, e->y1 , color);
		if ((f += dy) >= 0)
		{
			e->y1++;
			f += dx;
		}
	}
}

void		oct_3(t_env *e, int dx, int dy, int color)
{
	int		f;

	f = dy;
	dy = f * 2;
	dx *= 2;
	while (e->y1++ != e->y2)
	{
		my_pixel_put(e, e->x1, e->y1 , color);
		if ((f += dx) <= 0)
		{
			e->x1--;
			f += dy;
		}
	}
}