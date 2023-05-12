/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:27:26 by erigolon          #+#    #+#             */
/*   Updated: 2023/02/02 20:28:48 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	char	i;

	i = c;
	while (*s != '\0')
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (s == 0 || i == 0)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;
	int		i;
	int		o;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	o = 0;
	while (s2[o] != '\0')
	{
		str[i] = s2[o];
		i++;
		o++;
	}
	str[i] = '\0';
	return (str);
}
