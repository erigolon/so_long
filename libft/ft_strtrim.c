/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:29:40 by erigolon          #+#    #+#             */
/*   Updated: 2022/12/10 12:54:40 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen2(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

int	check_front(char const *s1, char const *set)
{
	int	i;
	int	o;

	i = 0;
	while (s1[i] != '\0')
	{
		o = 0;
		while (s1[i] != set[o])
		{
			if (set[o] == '\0')
				return (i);
			o++;
		}
		i++;
	}
	return (i);
}

int	check_back(char const *s1, char const *set)
{
	int	len;
	int	o;

	len = ft_strlen2(s1) - 1;
	while (len > 0)
	{
		o = 0;
		while (s1[len] != set[o])
		{
			if (set[o] == '\0')
				return (len);
			o++;
		}
		len--;
	}
	return (ft_strlen2(s1) - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		back;
	char	*str;
	int		i;

	front = check_front(s1, set);
	back = check_back(s1, set);
	str = (char *)malloc(back - front + 2);
	if (!str)
		return (0);
	i = 0;
	while (front <= back)
	{
		str[i] = s1[front];
		i++;
		front++;
	}
	str[i] = '\0';
	return (str);
}
