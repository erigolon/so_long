/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:50 by erigolon          #+#    #+#             */
/*   Updated: 2023/01/18 13:18:25 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len_u(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len ++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_u(unsigned int n)
{
	char			*str;
	int				len;
	unsigned long	nb;

	nb = n;
	len = num_len_u(nb);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[0] = '0';
	str[len] = '\0';
	if (nb < 0)
	{
		nb = nb * -1;
	}
	while (nb > 0)
	{
		len--;
		str[len] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (str);
}
