/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 01:34:26 by marine            #+#    #+#             */
/*   Updated: 2023/02/08 17:29:46 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_args_pf(char c, va_list ap, int *n)
{
	if (c == 'c')
		return (ft_putchar_pf(va_arg(ap, int), n));
	if (c == 's' )
		return (ft_putstr_pf(va_arg(ap, char *), n));
	if (c == 'p')
		return (ft_putptr_pf(va_arg(ap, unsigned long int), n));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_pf(va_arg(ap, int), n, 0));
	if (c == 'u')
		return (ft_putnbr_pf(va_arg(ap, unsigned int), n, 1));
	if (c == 'x')
		return (ft_puthexa_pf(va_arg(ap, unsigned int), n, 0));
	if (c == 'X')
		return (ft_puthexa_pf(va_arg(ap, unsigned int), n, 1));
	return ;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		n;
	va_list	ap;

	if (!str)
		return (-1);
	i = 0;
	n = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar_pf(str[i++], &n);
		else
		{
			if (str[i] == '%' && str[i + 1] == '%')
				ft_putchar_pf(str[i], &n);
			else
				ft_args_pf(str[i + 1], ap, &n);
			i += 2;
		}
	}
	va_end(ap);
	return (n);
}
