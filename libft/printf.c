/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:51:46 by ccartet           #+#    #+#             */
/*   Updated: 2021/12/16 11:19:37 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_count(char c);
int	ft_putstr_count(char *str);
int	ft_putnbr(int n);
int	ft_putnbru_base(unsigned long long n, char *base);
int	ft_put_pointer(unsigned long long p);

static int	ft_eval_format(char c, va_list ap)
{
	if (c == '\0')
		return (0);
	if (c == 's')
		return (ft_putstr_count(va_arg(ap, char *)));
	else if (c == 'c')
		return (ft_putchar_count(va_arg(ap, int)));
	else if (c == '%')
		return (ft_putchar_count('%'));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putnbru_base(va_arg(ap, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbru_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbru_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_put_pointer(va_arg(ap, unsigned long long)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	arg;

	va_start(arg, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_eval_format(format[i + 1], arg);
			if (format[i + 1] != '\0')
				i++;
		}
		else
			count += ft_putchar_count(format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}

/*#include <limits.h>

int	main(void)
{
	char	*str;
	int i;

	i = printf(" %p %p \n", LONG_MIN, LONG_MAX);
	i = printf("%d %p %p \n", i, INT_MIN, INT_MAX);
	i = printf("%d %p %p \n", i, ULONG_MAX, -ULONG_MAX);
	printf("%d\n", i);


	i = ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
	i = ft_printf("%d %p %p \n", i, INT_MIN, INT_MAX);
	i = ft_printf("%d %p %p \n", i, ULONG_MAX, -ULONG_MAX);
	ft_printf("%d\n", i);
	str = "Test";
	printf("%d\n", printf("Hellp %p ", "blop"));
	printf("%d\n", ft_printf("Hellf %p ", "blop"));
	return (0);
}*/