/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:16:00 by erigolon          #+#    #+#             */
/*   Updated: 2022/12/03 14:36:46 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 1;
	if (n == 0)
		return (0);
	while (*s1 == *s2 && *s1 != '\0' && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
