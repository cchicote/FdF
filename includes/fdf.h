/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:34:52 by cchicote          #+#    #+#             */
/*   Updated: 2016/02/25 19:40:10 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../minilibxLinux/mlx.h"
# include "../src/get_next_line/get_next_line.h"
# include <stdio.h>
# include <math.h>
# define RED 0xFF0000
# define BLUE 0x4169E1
# define PURPLE 0x9932CC
# define YELLOW 0xFFFF00
# define GREEN 0x008000

typedef		struct	s_env
{
	void	*win;
	void	*mlx;
	int		key;
	int		posv;
	int		posh;
}					t_env;

typedef		struct	s_val
{
	int		x;
	int		y;
	int		**tab;
	int		f_len;
	int		f_height;
}					t_val;

typedef		struct	s_draw
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}					t_draw;

int			main(int argc, char **argv);
t_env		*env_init(t_env *new);
t_val		*val_init(t_val *new);
t_draw		*draw_init(t_draw *new);
int			my_key_funct(int keycode, t_env *fdf);
int			my_mouse_funct(int mousecode, int x, int y, t_env *fdf);
int			line_len(char *line);
t_val		*read_file(t_val *v, char *file);
t_val		*put_values(t_val *v, int i, char *line);
void		line(t_draw *d, t_env *e);
void		vertical(t_draw *d, t_env *e);
void		draw_grid(t_draw *d, t_env *e, t_val *v);
int			get_keycode(int keycode, t_env *e, t_draw *d, t_val *v);
int			treat_keycode(t_env *e);

#endif