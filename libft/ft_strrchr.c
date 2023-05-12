/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:15:19 by erigolon          #+#    #+#             */
/*   Updated: 2022/12/03 12:52:28 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	i;
	char	*str;

	i = c;
	str = (char *)s;
	c = ft_strlen(s);
	while (c >= 0)
	{
		if (str[c] == i)
			return (&str[c]);
		c--;
	}
	if (i == 0)
		return (&str[c]);
	return (0);
}
