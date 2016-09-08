/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:12:13 by cchicote          #+#    #+#             */
/*   Updated: 2016/09/08 18:12:26 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		move_around_1(int keycode, t_env *e)
{
	if (keycode == 65361 || keycode == 124)
		e->posx -= 50;
	else if (keycode == 65362 || keycode == 125)
		e->posy -= 50;
	else if (keycode == 65363 || keycode == 65364 || keycode == 123
		|| keycode == 126)
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
