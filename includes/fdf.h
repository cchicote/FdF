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

typedef	struct	s_env
{
	void		*win;
	void		*mlx;
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
	int			key;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			posx;
	int			posy;
	int			**tab;
	int			f_len;
	int			f_height;
	int			size;
	int			color;
	int			inc;
	int			z;
}				t_env;

/*
** MAIN.C
*/

int				env_init(t_env *new, char *argv);
void			my_pixel_put(t_env *e, int x, int y, int color);
void			print_file(t_env *e);
int				main(int argc, char **argv);

/*
** READ_FILE.C
*/

int				line_len(char *line);
int				put_values(t_env *e, int i, char *line);
void			error(char *filename, int errnum);
int				check_line(char *line, char *file);
int				read_file(t_env *e, char *file);

/*
** INPUTS / INPUT_COLOR.C / KEYCODE.C / KEYCODE_2.C
*/

int				manage_key(int keycode, void *e);
void			treat_keycode(int keycode, t_env *e);
void			move_around_1(int keycode, t_env *e);
void			move_around_2(int keycode, t_env *e);
void			divide(int keycode, t_env *e);
void			height(int keycode, t_env *e);
void			color(int keycode, t_env *e);
void			size(int keycode, t_env *e);

/*
** DRAW_GRID.C
*/

int				get_color(int h);
void			draw_vert(t_env *e, int i, int j);
void			draw_hori(t_env *e, int i, int j);
void			draw_grid(t_env *e);

/*
** DRAW / TRACE.C
*/

void			draw_1(t_env *e, int color);
void			draw_2(t_env *e, int dx, int dy, int color);
void			draw_3(t_env *e, int dx, int dy, int color);
void			draw_4(t_env *e, int dy, int color);

/*
** OCTANTS / OCT_1-8.C
*/

void			oct_1(t_env *e, int dx, int dy, int color);
void			oct_2(t_env *e, int dx, int dy, int color);
void			oct_3(t_env *e, int dx, int dy, int color);
void			oct_4(t_env *e, int dx, int dy, int color);
void			oct_5(t_env *e, int dx, int dy, int color);
void			oct_6(t_env *e, int dx, int dy, int color);
void			oct_7(t_env *e, int dx, int dy, int color);
void			oct_8(t_env *e, int dx, int dy, int color);

#endif
