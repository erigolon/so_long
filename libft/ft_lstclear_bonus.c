/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:51:30 by erigolon          #+#    #+#             */
/*   Updated: 2022/12/23 10:11:52 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*start;

	if (lst && del)
	{
		while (*lst)
		{
			start = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = start;
		}
	}
}
