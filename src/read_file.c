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

t_val		*put_values(t_val *v, int i, char *line)
{
	int		x;
	int		y;
	int		n;

	x = 0;
	y = 0;
	n = 0;
	while (line[x] != '\0')
	{
		while(line[x + n] == '-' || ft_isalnum(line[x + n]) == 1)
			n++;
		v->tab[i][y] = ft_atoi(ft_strsub(line, x, n));
		n = 0;
		y++;
		while ((line[x] <= '9' && line[x] >= '0') || line[x] == '-') // C'est ici que ca marchait pas pour les nombres negatifs
			x++;
		while (line[x] == ' ' || line[x] == '\n')
			x++;
	}
	return (v);
}

t_val		*read_file(t_val *v, char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	v->tab = (int**)ft_memalloc(sizeof(int*) * 500);
	while (get_next_line(fd, &line) > 0)
	{
		v->tab[i] = (int*)ft_memalloc(sizeof(int) * (line_len(line) + 1));
		put_values(v, i, line);
		v->f_len = line_len(line);
		i++;
		v->f_height++;
	}
	close(fd);
	return (v);
}