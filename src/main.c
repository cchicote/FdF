/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:34:52 by cchicote          #+#    #+#             */
/*   Updated: 2016/09/08 19:18:46 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx_macos/X.h"

int			env_init(t_env *new, char *argv)
{
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, WINX, WINY, "fdf");
	new->img = mlx_new_image(new->mlx, WINX, WINY);
	new->data = mlx_get_data_addr(new->img, &(new->bpp), &(new->sl)
		, &(new->endian));
	new->color = 0xFFFFFF;
	new->key = 0;
	new->posx = 200;
	new->posy = 200;
	new->size = 10;
	new->inc = 1;
	new->f_len = 0;
	new->f_height = 0;
	new->z = 1;
	if (read_file(new, argv) == -1)
		return (-1);
	return (0);
}

void		my_pixel_put(t_env *e, int x, int y, int color)
{
	unsigned int	biscolor;

	biscolor = mlx_get_color_value(e->mlx, color);
	if (x < WINX && y < WINY && x > 0 && y > 0)
	{
		e->data[y * e->sl + x * e->bpp / 8] = (biscolor & 0x0000ff);
		e->data[y * e->sl + x * e->bpp / 8 + 1] = (biscolor & 0x00ff00) >> 8;
		e->data[y * e->sl + x * e->bpp / 8 + 2] = (biscolor & 0xff0000) >> 16;
	}
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

int			main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf fichier");
		return (0);
	}
	if (env_init(&e, argv[1]) == -1)
		return (0);
	ft_putendl("File red, start drawing now");
	draw_grid(&e);
	mlx_hook(e.win, KeyPress, KeyPressMask, manage_key, &e);
	//mlx_key_hook(e.win, manage_key, &e);
	mlx_loop(e.mlx);
	return (0);
}
