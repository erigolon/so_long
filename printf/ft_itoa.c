/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:47:51 by erigolon          #+#    #+#             */
/*   Updated: 2023/01/19 09:41:47 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	nb;

	nb = n;
	len = num_len(nb);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[0] = '0';
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
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
