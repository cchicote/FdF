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

t_env		*env_init(t_env *new)
{
	if ((new = (t_env*)ft_memalloc(sizeof(t_env))) == NULL)
		return (NULL);
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, 1001, 1001, "mlx 42");
	new->key = 0;
	new->posv = 200;
	new->posh = 200;
	return (new);
}

t_val		*val_init(t_val *new)
{
	if ((new = (t_val*)ft_memalloc(sizeof(t_val))) == NULL)
		return (NULL);
	new->x = 0;
	new->y = 0;
	new->f_len = 0;
	new->f_height = 0;
	return (new);
}

t_draw		*draw_init(t_draw *new)
{
	if ((new = (t_draw*)ft_memalloc(sizeof(t_draw))) == NULL)
		return (NULL);
	ft_bzero(new, sizeof(t_draw));
	return (new);
}

int			main(int argc, char **argv)
{
	t_env *e = NULL;
	t_val *v = NULL;
	t_draw *d = NULL;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf fichier");
		return (0);
	}
	if (((d = draw_init(d)) == NULL) || ((e = env_init(e)) == NULL)
	|| ((v = val_init(v)) == NULL))
		return (0);
	read_file(v, argv[1]);
	draw_grid(d, e, v);
	// mlx_key_hook(e->win, get_keycode, e->mlx);
	mlx_loop(e->mlx);
	return (0);
}
