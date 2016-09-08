/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:34:52 by cchicote          #+#    #+#             */
/*   Updated: 2016/02/25 19:40:10 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		color(int keycode, t_env *e)
{
	if (keycode == 65436)
		e->color = 0xFFFFFF;
	else if (keycode == 65433)
		e->color = 0xFF0000;
	else if (keycode == 65435)
		e->color = 0x00FF00;
	else if (keycode == 65430)
		e->color = 0x0000FF;
	else if (keycode == 65437)
		e->color = 0xFF8C00;
	else if (keycode == 65432)
		e->color = 0xFF00FF;
	else if (keycode == 65429)
		e->color = 0x7B68EE;
	else if (keycode == 65431)
		e->color = 0x2E8B57;
	else if (keycode == 65434)
		e->color = 0x66CDAA;
}
