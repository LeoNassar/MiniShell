/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnassar <lnassar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:51:25 by lnassar           #+#    #+#             */
/*   Updated: 2025/02/19 22:26:02 by lnassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_formats(va_list args, const char format)
{
	int		pl;
	char	*lower_hex;
	char	*upper_hex;

	pl = 0;
	lower_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	if (format == 'c')
		pl += ft_printchar(va_arg(args, int));
	else if (format == 's')
		pl += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		pl += ft_putnbr_base(va_arg(args, long), lower_hex, 16, format);
	else if (format == 'd' || format == 'i')
		pl += ft_putnbr_base(va_arg(args, int), "0123456789", 10, format);
	else if (format == 'u')
		pl += ft_putnbr_base(va_arg(args, unsigned), "0123456789", 10, format);
	else if (format == 'x')
		pl += ft_putnbr_base(va_arg(args, unsigned), lower_hex, 16, format);
	else if (format == 'X')
		pl += ft_putnbr_base(va_arg(args, unsigned), upper_hex, 16, format);
	else if (format == '%')
		pl += ft_printchar('%');
	return (pl);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		pl;

	i = 0;
	pl = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			pl += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			pl += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (pl);
}
