/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:55:49 by erigolon          #+#    #+#             */
/*   Updated: 2022/12/06 22:35:15 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcat(char *dest, char *src, unsigned int i_dest, unsigned int s)
{
	unsigned int	i_src;

	i_src = 0;
	s--;
	while (src[i_src] != '\0' && i_dest < s)
	{
		dest[i_dest] = src[i_src];
		i_dest++;
		i_src++;
	}
	dest[i_dest] = '\0';
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	lenght_src;
	size_t	lenght_dest;

	lenght_src = ft_strlen(src);
	lenght_dest = ft_strlen(dest);
	if (size == 0)
		return (lenght_src);
	if (size < lenght_dest)
		lenght_dest = size;
	else
		ft_strcat(dest, src, lenght_dest, size);
	return (lenght_src + lenght_dest);
}
