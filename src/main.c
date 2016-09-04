/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:34:52 by cchicote          #+#    #+#             */
/*   Updated: 2016/02/25 19:40:10 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		env_init(t_env *new, char *argv)
{
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, WINX, WINY, "mlx 42");
	new->img = mlx_new_image(new->mlx, WINX, WINY);
	new->data = mlx_get_data_addr(new->img, &(new->bpp), &(new->sl), &(new->endian));
	new->key = 0;
	new->posv = 200;
	new->posh = 200;
	new->x = 0;
	new->y = 0;
	new->f_len = 0;
	new->f_height = 0;
	read_file(new, argv);
}

void		my_pixel_put(t_env *e, int x, int y, int color)
{
	unsigned int	biscolor;

	biscolor = mlx_get_color_value(e->mlx, color);
	if (x < WINX && y < WINY && x > 0 && y > 0)
	{
		e->data[y * e->sl + x * e->bpp / 8] = (biscolor  & 0x0000ff);  //on va chercher dans biscolor la valeur binaire du Bleu et on la met direct dans e->data
		e->data[y * e->sl + x * e->bpp / 8 + 1] = (biscolor & 0x00ff00) >> 8;  //on va chercher dans biscolor la valeur binaire du Vert et on la met direct dans e->data
		e->data[y * e->sl + x * e->bpp / 8 + 2] = (biscolor & 0xff0000) >> 16;  //on va chercher dans biscolor la valeur binaire du Rouge et on la met direct dans e->data
	}
	// les couleurs sont mises dans DATA au bon endroit (x, y)
}

int			main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf fichier");
		return (0);
	}
	env_init(&e, argv[1]);
	my_pixel_put(&e, 20, 20, 0xFFFFFF);
	my_pixel_put(&e, 10, 10, 0xFFFFFF);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_loop(e.mlx);
	return (0);
}
