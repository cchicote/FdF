/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:24:24 by cchicote          #+#    #+#             */
/*   Updated: 2015/11/26 18:23:58 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_strclr(char *s)
{
	int index;

	index = 0;
	if (s != NULL)
	{
		while (s[index] != '\0')
		{
			s[index] = '\0';
			s++;
		}
		s[index] = '\0';
	}
}