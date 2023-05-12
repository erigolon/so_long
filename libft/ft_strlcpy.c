/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:05:15 by erigolon          #+#    #+#             */
/*   Updated: 2022/12/08 18:35:49 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	lenght_count;

	count = 1;
	lenght_count = ft_strlen(src);
	if (lenght_count == 0)
		*dst = '\0';
	if (size <= 0 || lenght_count == 0)
		return (lenght_count);
	while (count < size && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		count++;
	}
	*dst = '\0';
	return (lenght_count);
}
