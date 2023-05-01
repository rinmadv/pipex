/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 03:11:21 by marine            #+#    #+#             */
/*   Updated: 2023/02/08 17:29:05 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_pf(char c, int *n)
{
	write(1, &c, 1);
	*n += 1;
}

void	ft_putstr_pf(char *str, int *n)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_pf("(null)", n);
		return ;
	}
	while (str[i])
		write(1, &str[i++], 1);
	*n = *n + i;
}

void	ft_putnbr_pf(long long int nb, int *n, int is_unsigned)
{
	if (!is_unsigned && nb < 0)
	{
		ft_putchar_pf('-', n);
		nb *= -1;
	}
	if (nb <= 9)
	{
		ft_putchar_pf(nb + '0', n);
	}
	if (nb > 9)
	{
		ft_putnbr_pf(nb / 10, n, is_unsigned);
		ft_putchar_pf(nb % 10 + '0', n);
	}
}

void	ft_puthexa_pf(unsigned long long int nb, int *n, int c)
{
	char	*base;

	if (c == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb <= 15)
		ft_putchar_pf((base[0 + nb]), n);
	if (nb > 15)
	{
		ft_puthexa_pf(nb / 16, n, c);
		ft_putchar_pf((base[0 + nb % 16]), n);
	}
}

void	ft_putptr_pf(unsigned long int ptr, int *n)
{
	if (ptr == 0)
		return (ft_putstr_pf("(nil)", n));
	ft_putstr_pf("0x", n);
	ft_puthexa_pf(ptr, n, 0);
}
