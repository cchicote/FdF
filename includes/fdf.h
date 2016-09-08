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
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# define RED 0xFF0000
# define BLUE 0x4169E1
# define PURPLE 0x9932CC
# define YELLOW 0xFFFF00
# define GREEN 0x008000
# define WINX 1000
# define WINY 1000

typedef		struct	s_env
{
	void	*win;
	void	*mlx;
	void	*img;
	char	*data;
	int		bpp;
	int		sl;
	int		endian;
	int		key;
	int		posv;
	int		posh;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		posx;
	int		posy;
	int		**tab;
	int		f_len;
	int		f_height;
	int		size;
	int		color;
	int		inc;
}					t_env;

int			main(int argc, char **argv);
int			env_init(t_env *new, char *argv);
int			my_key_funct(int keycode, t_env *e);
int			my_mouse_funct(int mousecode, int x, int y, t_env *fdf);
int			line_len(char *line);
int			read_file(t_env *e, char *file);
int			put_values(t_env *e, int i, char *line);
void		my_pixel_put(t_env *e, int x, int y, int color);
void		draw_grid(t_env *e);
void		clear(t_env *e);

/*
** INPUTS
*/

int			manage_key(int keycode, void *e);
void		treat_keycode(int keycode, t_env *e);
void		move_around_1(int keycode, t_env *e);
void		move_around_2(int keycode, t_env *e);
void		size(int keycode, t_env *e);
void		color(int keycode, t_env *e);
void		divide(int keycode, t_env *e);



/*
** DRAW
*/

void		draw_1(t_env *e, int color);
void		draw_2(t_env *e, int dx, int dy, int color);
void		draw_3(t_env *e, int dx, int dy, int color);
void		draw_4(t_env *e, int dy, int color);

/*
** OCTANTS
*/

void		oct_1(t_env *e, int dx, int dy, int color);
void		oct_2(t_env *e, int dx, int dy, int color);
void		oct_3(t_env *e, int dx, int dy, int color);
void		oct_4(t_env *e, int dx, int dy, int color);
void		oct_5(t_env *e, int dx, int dy, int color);
void		oct_6(t_env *e, int dx, int dy, int color);
void		oct_7(t_env *e, int dx, int dy, int color);
void		oct_8(t_env *e, int dx, int dy, int color);

#endif