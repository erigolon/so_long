/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:06:44 by erigolon          #+#    #+#             */
/*   Updated: 2022/12/23 09:02:05 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	splits(char const *s, char c)
{
	int	i;
	int	split;

	i = 0;
	split = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{	
			i = 1;
			split++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (split);
}

char	*split_word(const char *s, int st, int fn)
{
	char	*str;
	int		i;

	str = (char *)malloc(fn - st + 1);
	if (!str)
		return (0);
	i = 0;
	while (st < fn)
	{
		str[i] = s[st];
		i++;
		st++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str_split;
	size_t	i;
	size_t	o;
	int		pos;

	str_split = malloc((splits(s, c) + 1) * sizeof(char *));
	if (!s || !str_split)
		return (0);
	i = 0;
	o = 0;
	pos = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && pos < 0)
			pos = i;
		else if ((s[i] == c || i == ft_strlen(s)) && pos >= 0)
		{
			str_split[o] = split_word(s, pos, i);
			o++;
			pos = -1;
		}
		i++;
	}
	str_split[o] = 0;
	return (str_split);
}
