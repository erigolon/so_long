/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:38:53 by erigolon          #+#    #+#             */
/*   Updated: 2022/12/03 17:00:02 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	ch = c;
	i = 0;
	while (i < n)
	{
		if (*str == ch)
			return (str);
		str++;
		i++;
	}
	return (0);
}
