/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:32:52 by marine            #+#    #+#             */
/*   Updated: 2023/07/26 16:54:52 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_powsixteen(unsigned int i)
{
	unsigned int	j;
	unsigned int	n;

	j = 0;
	n = 1;
	while (j < i)
	{
		n *= 16;
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
		i = i / 16;
		j++;
	}
	return (j);
}


char	*ft_uitoa_hexa(unsigned int n, int c)
{
	int		i;
	char	*number;
	int		j;
	char	*base;

	if (c == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	int p = 0;
	while (base[p])
	{
		printf("base[%d] = %c\n", p, base[p]);
		p++;
	}
	i = 0;
	j = ft_nblen(n) - 1;
	number = ft_calloc((ft_nblen(n) + 1), sizeof(char));
	if (number == NULL)
		return (NULL);
	if (n == 0)
		number[i] = base[0];
	while (j>= 0)
	{
		number[i] = base[n / ft_powsixteen(j)];
		printf("number : %c\n", number[i]);
		n = n - (ft_powsixteen(j--) * (number[i++] - base[0]));
	}
	return (number);
}
