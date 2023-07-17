/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd _new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 03:11:21 by marine            #+#    #+#             */
/*   Updated: 2023/07/17 21:39:35 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr_pf(int output, char *str, int *n)
{
	int	i;

	i = 0;
	while (str[i])
		write(output, &str[i++], 1);
	*n = *n + i;
}

void	ft_addstr(char *buffer, char *str, int *n)
{
	int	i;
	char *null_str;
	
	i = 0;
	if (!str)
	{
		null_str = "(null)";
		while (null_str[i])
		{
			buffer[*n] = null_str[i];
			*n += 1;
			i++;
		}
	}
	else
		while (str[i])
		{
			buffer[*n] = str[i];
			*n += 1;
			i++;
		}
}

// void	ft_putnbr_pf(char *buffer, long long int nb, int *n, int is_unsigned)
// {
// 	if (!is_unsigned && nb < 0)
// 	{
// 		ft_putchar_pf(output, '-', n);
// 		nb *= -1;
// 	}
// 	if (nb <= 9)
// 	{
// 		ft_putchar_pf(output, nb + '0', n);
// 	}
// 	if (nb > 9)
// 	{
// 		ft_putnbr_pf(output, nb / 10, n, is_unsigned);
// 		ft_putchar_pf(output, nb % 10 + '0', n);
// 	}
// }

// void	ft_puthexa(char *buffer, unsigned long long int nb, int *n, int c)
// {
// 	char	*base;

// 	if (c == 0)
// 		base = "0123456789abcdef";
// 	else
// 		base = "0123456789ABCDEF";
// 	if (nb <= 15)
// 	{	
// 		buffer[*n] = (base[0 + nb]);
// 		n += 1;
// 	}
// 	if (nb > 15)
// 	{
// 		ft_puthexa_pf(output, nb / 16, n, c);
// 		ft_putchar_pf(output, (base[0 + nb % 16]), n);
// 	}
// }

// void	ft_putptr_pf(char *buffer, unsigned long int ptr, int *n)
// {
// 	if (ptr == 0)
// 		return (ft_addstr(buffer, "(nil)", n));
// 	ft_addstr(buffer, "0x", n);
// 	ft_puthexa(buffer, ptr, n, 0);
// }

void	ft_args_pf(char c, va_list ap, int *n, char *buffer)
{
	if (c == 's')
		ft_addstr(buffer, va_arg(ap, char *), n);
	// else if (c == 'p')
	// 	ft_putptr_pf(buffer, va_arg(ap, unsigned long int), n);
	// else if (c == 'd' || c == 'i')
	// 	ft_putnbr_pf(buffer, va_arg(ap, int), n, 0);
	// else if (c == 'u')
	// 	ft_putnbr_pf(buffer, va_arg(ap, unsigned int), n, 1);
	// else if (c == 'x')
	// 	ft_puthexa_pf(buffer, va_arg(ap, unsigned int), n, 0);
	// else if (c == 'X')
	// 	ft_puthexa_pf(buffer, va_arg(ap, unsigned int), n, 1);
	return ;
}
// compter la taille 

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_countstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		i = 6;
	else
		i = ft_strlen(str);
	return (i);
}

int	ft_counthexa(unsigned long long int nb)
{
	int	n;

	n = 1;
	while (nb > 15)
	{
		n++;
		nb = nb / 16;
	}
	return (n);
}

int	ft_count_ptr(unsigned long int ptr)
{
	if (ptr == 0)
		return (5);
	return(2 + ft_counthexa(ptr));
}

int	ft_countnbr(long long int nb,int is_unsigned)
{
	int	count;

	count = 1;
	if (!is_unsigned && nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb > 9)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}

void	ft_count_arg_len(char c, va_list ap, int *n)
{
	if (c == 'c')
		*n += 1;
	else if (c == 's' )
		*n = *n + ft_countstr(va_arg(ap, char *));
	else if (c == 'p')
		*n = *n + (ft_count_ptr(va_arg(ap, unsigned long int)));
	else if (c == 'd' || c == 'i')
		*n = *n + (ft_countnbr(va_arg(ap, int), 0));
	else if (c == 'u')
		*n = *n + (ft_countnbr(va_arg(ap, unsigned int), 1));
	else if (c == 'x' || c == 'X')
		*n = *n + (ft_counthexa(va_arg(ap, unsigned int)));
	return ;
}

int	ft_count(const char *str, va_list ap)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			i++;
			n++;
		}
		else
		{
			if (str[i] == '%' && str[i + 1] == '%')
			{	
				i += 2;
				n++;
			}
			else
				ft_count_arg_len(str[i + 1], ap, &n);
			i += 2;
		}
	}
	return (n);
}

void	*ft_memset_pf(char *s, int c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	ft_bzero_pf(char *s, int n)
{
	ft_memset_pf(s, 0, n);
}

void	fill_buffer(char *buffer, int *n, const char *str, va_list ap)
{
	ft_bzero_pf(buffer, *n + 1);
	int i;
	
	i = 0; // naviguer dans la chaine
	*n = 0; // naviguer dans mon buffer
	while (str[i])
	{
		if (str[i] != '%')
		{
			buffer[*n] = str[i];
			*n += 1;
			i++;
		}
		else
		{
			if (str[i] == '%' && str[i + 1] == '%')
			{	
				buffer[*n] = '%';
				*n += 1;
			}
			else
			{
				if (str[i + 1] == 'c')
				{
					buffer[*n] = va_arg(ap, int);
					*n += 1;
				}
				else
					ft_args_pf(str[i + 1], ap, n, buffer);
			}
			i += 2;
		}
	}
	buffer[*n] = 0;
}

int	ft_printf(int output, const char *str, ...)
{
	int		i;
	int		n;
	char	*buffer;
	va_list	ap;

	(void) output;
	if (!str)
		return (-1);
	i = 0;
	n = 0;
	(void) i;
	va_start(ap, str);
	n = ft_count(str, ap);
	buffer = malloc(sizeof(char) * (n + 1));
	if (buffer == NULL)
		return (-1);
	fill_buffer(buffer, &n, str, ap);
	n = 0;
	ft_putstr_pf(output, buffer, &n);
	va_end(ap);
	return (n);
}

int	main(void)
{
	// /* test ecriture*/

	// ft_printf(1, "Coucou\n");

	/*test longueur*/
	// int b = 12;
	printf("test normal\n");
	printf("ft_printf\t%d\n", ft_printf(1, "Coucou\n"));
	printf("printf\t%d\n", printf("Coucou\n"));
	printf("\n");
	
	printf("test %%c\n");
	printf("ft_printf\t%d\n", ft_printf(1, "Coucou %c \n", 'd'));
	printf("printf\t%d\n", printf("Coucou %c \n", 'd'));
	printf("\n");
	

	// printf("test %%s\n");
	// printf("ft_printf\t%d\n", ft_printf(1, "Coucou %s \n", "wesh alors"));
	// printf("printf\t%d\n", printf("Coucou %s \n", "wesh alors"));
	// printf("\n");
	
	
	// printf("test %%d\n");
	// printf("ft_printf\t%d\n", ft_printf(1, "Coucou %d \n", 1024));
	// printf("printf\t%d\n", printf("Coucou %d \n", 1024));
	// printf("\n");
	

	// printf("test %%i\n");
	// printf("ft_printf\t%d\n", ft_printf(1, "Coucou %i \n", 1024));
	// printf("printf\t%d\n", printf("Coucou %i \n", 1024));
	// printf("\n");
	

	// printf("test %%u\n");
	// printf("ft_printf\t%d\n", ft_printf(1, "Coucou %u \n", -1024));
	// printf("printf\t%d\n", printf("Coucou %u \n", -1024));
	// printf("\n");
	

	// printf("test %%x\n");
	// printf("ft_printf\t%d\n", ft_printf(1, "Coucou %x \n", 1042));
	// printf("printf\t%d\n", printf("Coucou %x \n", 1042));
	// printf("\n");
	
	
	// printf("test %%X\n");
	// printf("ft_printf\t%d\n", ft_printf(1, "Coucou %X \n", 1042));
	// printf("printf\t%d\n", printf("Coucou %X \n", 1042));
	// printf("\n");
	
	// printf("test %%p\n");
	// printf("ft_printf\t%d\n", ft_printf(1, "Coucou %p \n", &b));
	// printf("printf\t%d\n", printf("Coucou %p \n", &b));
	// printf("\n");
	return (0);
}