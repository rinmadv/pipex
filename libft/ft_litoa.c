/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:32:52 by marine            #+#    #+#             */
/*   Updated: 2023/07/25 20:34:09 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_powten(int i)
{
	int	j;
	int	n;

	j = 0;
	n = 1;
	while (j < i)
	{
		n *= 10;
		j++;
	}
	return (n);
}

static int	ft_nblen(int i)
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

static int	absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_litoa(unsigned int n)
{
	int		i;
	char	*number;
	int		j;

	i = 0;
	j = ft_nblen(n) - 1;
	printf("litoa n = %u\n", n);
	number = ft_calloc((ft_nblen(n) + 1), sizeof(char));
	if (number == NULL)
		return (NULL);
	if (n == 0)
		number[i] = '0';
	while (j>= 0)
	{
		number[i] = (absolute(n) / ft_powten(j)) + 48;
		n = absolute(n) - (ft_powten(j--) * (number[i++] - 48));
	}
	return (number);
}
