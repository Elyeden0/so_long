/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:55:02 by abonnard          #+#    #+#             */
/*   Updated: 2024/11/22 13:48:50 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbr_hex(unsigned long long n, int uppercase)
{
	char	*base;
	int		count;

	count = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, uppercase);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	addr;
	int					count;

	count = 0;
	addr = (unsigned long long)ptr;
	if (addr == 0)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_putnbr_hex(addr, 0);
	return (count);
}
