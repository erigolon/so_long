/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:03:26 by erigolon          #+#    #+#             */
/*   Updated: 2022/12/05 12:32:44 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pos_neg(char *str, int pos_neg)
{
	if (*str == '-')
	{
		pos_neg = pos_neg * -1;
	}
	return (pos_neg);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		pos_neg;
	int		result;
	char	*s;

	i = 0;
	result = 0;
	pos_neg = 1;
	s = (char *)str;
	while (s[i] == ' ' || s[i] == '\f' || s[i] == '\n'
		|| s[i] == '\r' || s[i] == '\t' || s[i] == '\v')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		pos_neg = ft_pos_neg(&s[i], pos_neg);
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10 + (s[i] - 48));
		i++;
	}
	if (pos_neg == -1)
		result = result * -1;
	return (result);
}
