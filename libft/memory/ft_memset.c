/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnassar <lnassar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:32:58 by lnassar           #+#    #+#             */
/*   Updated: 2025/02/19 22:29:47 by lnassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)b;
	while (i < len)
		d[i++] = (unsigned char)c;
	b = (void *)d;
	return (b);
}
// int main()
// {
//     char str[50] = "Hello World!";
//     // Test avec la fonction ft_memset
//     ft_memset(str + 6, 'X', 5);  
// 	//Remplacer 5 caractères à partir de str[6] par 'X'
//     printf("Result: %s\n", str);  
// 	//Attendu: "Hello XXXXX!"
//     return 0;
// }