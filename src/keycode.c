/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:34:52 by cchicote          #+#    #+#             */
/*   Updated: 2016/02/25 19:40:10 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			manage_key(int keycode, void *e)
{
	treat_keycode(keycode, e);
	draw_grid(e);
	return (0);
}

void		move_around_1(int keycode, t_env *e)
{
	if (keycode == 65361 || keycode == 124)
		e->posx -= 50;
	else if (keycode == 65362 || keycode == 125)
		e->posy -= 50;
	else if (keycode == 65363 || keycode == 65364 || keycode == 123 || keycode == 126)
		move_around_2(keycode, e);
}

void		move_around_2(int keycode, t_env *e)
{
	if (keycode == 65363 || keycode == 123)
		e->posx += 50;
	else if (keycode == 65364 || keycode == 126)
		e->posy += 50;
}

void		size(int keycode, t_env *e)
{
	if (keycode == 65451 || keycode == 69)
		e->size++;
	else if ((keycode == 65453 || keycode == 78) && e->size >= 2)
		e->size--;
}

void		divide(int keycode, t_env *e)
{
	if (keycode == 46 || keycode == 47)
		e->inc++;
	else if ((keycode == 44 || keycode == 43) && e->inc > 1)
		e->inc--;
}

void		height(int keycode, t_env *e)
{
	if (keycode == 30)
		e->z++;
	else
		e->z--;
}

void		treat_keycode(int keycode, t_env *e)
{
	ft_putnbrendl(keycode);
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	ft_bzero(e->data, e->sl * WINY);
	if ((keycode >= 65361 || keycode >= 123) && (keycode <= 65364 || keycode <= 126))
		move_around_1(keycode, e);
	else if (keycode == 65451 || keycode == 65453 || keycode == 69 || keycode == 78)
		size(keycode, e);
	else if (keycode >= 65429 && keycode <= 65437)
		color(keycode, e);
	else if (keycode == 46 || keycode == 44 || keycode == 47 || keycode == 43)
		divide(keycode, e);
	else if (keycode == 30 || keycode == 33)
		height(keycode, e);
}
