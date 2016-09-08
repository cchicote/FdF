/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:34:52 by cchicote          #+#    #+#             */
/*   Updated: 2016/02/25 19:40:10 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			line_len(char *line)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (line[i] != '\0')
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			c++;
			while (line[i] >= '0' && line[i] <= '9')
				i++;
		}
		i++;
	}
	return (c);
}

int			put_values(t_env *e, int i, char *line)
{
	int			x;
	int			y;
	int			n;

	x = 0;
	y = 0;
	n = 0;
	while (line[x] != '\0')
	{
		while (line[x + n] == '-' || ft_isalnum(line[x + n]) == 1)
			n++;
		e->tab[i][y] = ft_atoi(ft_strsub(line, x, n));
		n = 0;
		y++;
		while ((line[x] <= '9' && line[x] >= '0') || line[x] == '-')
			x++;
		while (line[x] == ' ')
			x++;
	}
	return (0);
}

void		error(char *filename, int errnum)
{
	ft_putstr("Error: ");
	ft_putstr(filename);
	if (errnum == 1)
	{
		ft_putstr(" : this file is too long or too short");
		ft_putendl(", please modify its size.");
	}
	else if (errnum == 2)
	{
		ft_putstr(" : there is an invalid character in this file");
		ft_putendl(", please choose a valid file");
	}
}

int			check_line(char *line, char *file)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (ft_isalnum(line[i]) == 0 && (line[i] != '-' && line[i] != ' '))
		{
			error(file, 2);
			return (-1);
		}
	}
	return (0);
}

int			read_file(t_env *e, char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY, S_IREAD);
	e->tab = (int**)ft_memalloc(sizeof(int*) * 500);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) < 1 || ft_strlen(line) > 5000)
		{
			error(file, 1);
			return (-1);
		}
		if (check_line(line, file) != 0)
			return (-1);
		e->tab[i] = (int*)ft_memalloc(sizeof(int) * (line_len(line) + 1));
		put_values(e, i, line);
		e->f_len = line_len(line);
		i++;
		e->f_height++;
	}
	close(fd);
	return (0);
}
