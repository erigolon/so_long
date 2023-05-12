/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:30:23 by erigolon          #+#    #+#             */
/*   Updated: 2022/12/05 16:55:38 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c_hs;
	size_t	c_nd;

	c_hs = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[c_hs] && c_hs < len)
	{
		c_nd = 0;
		while (haystack[c_hs + c_nd] == needle[c_nd]
			&& (c_hs + c_nd) < len && needle[c_nd])
			c_nd++;
		if (!needle[c_nd])
			return ((char *)(haystack + c_hs));
		c_hs++;
	}
	return (0);
}
