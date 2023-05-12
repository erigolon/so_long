/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:10:29 by erigolon          #+#    #+#             */
/*   Updated: 2022/12/08 17:40:22 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
