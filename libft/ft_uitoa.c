/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:32:52 by marine            #+#    #+#             */
/*   Updated: 2023/07/26 15:20:04 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_powten(unsigned int i)
{
	unsigned int	j;
	unsigned int	n;

	j = 0;
	n = 1;
	while (j < i)
	{
		n *= 10;
		j++;
	}
	return (n);
}

static int	ft_nblen(unsigned int i)
{
	int	j;

	j = 0;
	if (i == 0)
		return (1);
	while (i)
	{
		i = i / 10;
		j++;
	}
	return (j);
}


char	*ft_uitoa(unsigned int n)
{
	int		i;
	char	*number;
	int		j;

	i = 0;
	j = ft_nblen(n) - 1;
	number = ft_calloc((ft_nblen(n) + 1), sizeof(char));
	if (number == NULL)
		return (NULL);
	if (n == 0)
		number[i] = '0';
	while (j>= 0)
	{
		number[i] = (n / ft_powten(j)) + 48;
		n = n - (ft_powten(j--) * (number[i++] - 48));
	}
	return (number);
}
