/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnassar <lnassar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:09:55 by lnassar           #+#    #+#             */
/*   Updated: 2025/02/19 22:32:16 by lnassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	print_base(ssize_t num, char *base, size_t base_len)
{
	char	str[20];
	size_t	pl;
	size_t	rem;
	size_t	i;

	i = 0;
	pl = 0;
	if (num == 0)
		pl += ft_printchar(base[0]);
	while (num != 0)
	{
		rem = num % base_len;
		str[i] = base[rem];
		num /= base_len;
		++i;
	}
	while (i--)
		pl += ft_printchar(str[i]);
	return (pl);
}

size_t	ft_putnbr_base(ssize_t nbr, char *base, size_t base_len, char spf)
{
	size_t	pl;

	pl = 0;
	if ((spf == 'd' || spf == 'i' || spf == 'u') && nbr < 0)
	{
		pl += ft_printchar('-');
		nbr = -nbr;
	}
	else if (spf == 'p' && nbr == 0)
	{
		pl += ft_printstr("(nil)");
		return (pl);
	}
	else if (spf == 'p')
		pl += ft_printstr("0x");
	pl += print_base(nbr, base, base_len);
	return (pl);
}
