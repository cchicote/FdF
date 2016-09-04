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
	new->color = 0xFFFFFF;
	new->key = 0;
	new->posx = 200;
	new->posy = 200;
	new->size = 10;
	new->inc = 1;
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

void		gros_cercle_sa_mere(t_env *e)
{
	e->x1 = 10;
	e->y1 = 10;
	e->x2 = 100;
	e->y2 = 10;
	draw_1(e, 0xFFFFFF);
}

void		print_file(t_env *e)
{
	int i;
	int j;

	i = -1;
	while (++i < e->f_height)
	{
		j = -1;
		while (++j < e->f_len)
		{
			ft_putnbr(e->tab[i][j]);
			if (e->tab[i][j] >= 10 || e->tab[i][j] < 0)
				ft_putchar(' ');
			else
				ft_putstr("  ");

		}
		ft_putchar('\n');
	}
}

void			clear(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	mlx_new_image(e->mlx, WINX, WINY);
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
	print_file(&e);
	// draw_grid(&e);
	mlx_key_hook(e.win, manage_key, &e);
	mlx_loop(e.mlx);
	// gros_cercle_sa_mere(&e);
	return (0);
}
