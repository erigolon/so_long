/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:02:01 by erigolon          #+#    #+#             */
/*   Updated: 2023/01/19 09:45:03 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strinvcpy(char *dst, char *src)
{
	int	i;
	int	len;

	len = ft_strlen(src);
	i = 0;
	len--;
	while (len >= 0)
	{
		dst[i] = src[len];
		i++;
		len--;
	}
	dst[i] = '\0';
}

char	*newstr(char *str)
{
	int		len;
	char	*str_done;

	len = ft_strlen(str);
	str_done = (char *)malloc(len + 1);
	if (!str_done)
		return (0);
	ft_strinvcpy(str_done, str);
	return (str_done);
}

char	*ft_hex(unsigned long decimal, int mayus)
{
	unsigned int		remainder;
	int					i;
	char				hex[100];
	char				*str;

	i = 0;
	if (decimal == 0)
		hex[i++] = '0';
	while (decimal != 0)
	{
		remainder = decimal % 16;
		if (remainder < 10)
			hex[i] = 48 + remainder;
		else if (remainder >= 10 && mayus == 1)
			hex[i] = 55 + remainder;
		else if (remainder >= 10 && mayus == 0)
			hex[i] = 87 + remainder;
		i++;
		decimal = decimal / 16;
	}
	hex[i] = '\0';
	str = &hex[0];
	str = newstr(str);
	return (str);
}
/*
int	main(void)
{
	char	*str;

	str = ft_hex(0);
	printf("%s", str);
	return (0);
}
*/