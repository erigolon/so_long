/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:02:00 by erigolon          #+#    #+#             */
/*   Updated: 2022/12/07 13:37:35 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*str;
	size_t			i;
	unsigned char	*s;

	str = (void *)malloc(count * size);
	if (!str)
		return (0);
	i = 0;
	s = (unsigned char *)str;
	while (i < (count * size))
	{
		s[i] = (unsigned char) 0;
		i++;
	}
	return ((void *)s);
}
