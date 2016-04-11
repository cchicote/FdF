/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:34:52 by cchicote          #+#    #+#             */
/*   Updated: 2016/02/25 19:40:10 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			get_keycode(int keycode, t_env *e, t_draw *d, t_val *v)
{
	e->key = keycode;
	treat_keycode(e);
	// mlx_clear_window(e->mlx, e->win);
	draw_grid(d, e, v);
	return (0);
}

int			treat_keycode(t_env *e)
{
	if (e->key == 65364)
		e->posv += 50;
	if (e->key == 65362)
		e->posv -= 50;
	if (e->key == 65363)
		e->posh += 50;
	if (e->key == 65361)
		e->posh -= 50;
	return (0);
}