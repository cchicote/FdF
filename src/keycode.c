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
	if (keycode == 65361)
		e->posx -= 50;
	else if (keycode == 65362)
		e->posy -= 50;
	else if (keycode == 65363 || keycode == 65364)
		move_around_2(keycode, e);
}

void		move_around_2(int keycode, t_env *e)
{
	if (keycode == 65363)
		e->posx += 50;
	else if (keycode == 65364)
		e->posy += 50;
}

void		size(int keycode, t_env *e)
{
	if (keycode == 65451)
		e->size++;
	else if (keycode == 65453 && e->size > 2)
		e->size--;
	ft_putnbrendl(e->size);
}

void		divide(int keycode, t_env *e)
{
	if (keycode == 46)
		e->inc++;
	else if (keycode == 44 && e->inc > 1)
		e->inc--;
}

void		treat_keycode(int keycode, t_env *e)
{
	ft_putnbrendl(keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	clear(e);
	if (keycode >= 65361 && keycode <= 65364)
		move_around_1(keycode, e);
	if (keycode == 65451 || keycode == 65453)
		size(keycode, e);
	if (keycode >= 65429 && keycode <= 65437)
		color(keycode, e);
	if (keycode == 46 || keycode == 44)
		divide(keycode, e);
}
