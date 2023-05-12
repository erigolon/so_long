/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:15:11 by erigolon          #+#    #+#             */
/*   Updated: 2022/12/22 15:34:43 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*add;

	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			add = ft_lstlast(*lst);
			add->next = new;
		}
	}
}
