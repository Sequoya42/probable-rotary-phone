/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:19:49 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/13 16:43:14 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int i;
	int j;

	if (s != NULL)
	{
		i = ft_strlen(s);
		j = 0;
		while (j < i)
		{
			s[j] = '\0';
			j++;
		}
	}
}
