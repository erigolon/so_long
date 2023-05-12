/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:51:09 by erigolon          #+#    #+#             */
/*   Updated: 2022/12/08 17:01:31 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*str;
	unsigned int		i;
	unsigned int		size;

	size = ft_strlen(s);
	if (size <= len)
		str = (char *)malloc(size + 1);
	else
		str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	if (start >= size)
	{
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while (i < len && s[i + start] != '\0')
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
