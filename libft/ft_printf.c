/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:51:41 by abonnard          #+#    #+#             */
/*   Updated: 2024/11/22 11:24:15 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	handle_format(const char *format, va_list args, int *i)
{
	int	count;

	count = 0;
	if (format[*i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format[*i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format[*i] == 'd' || format[*i] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format[*i] == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format[*i] == 'x')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 0);
	else if (format[*i] == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 1);
	else if (format[*i] == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (format[*i] == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += handle_format(format, args, &i);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
