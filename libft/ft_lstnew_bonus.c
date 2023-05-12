/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:49:40 by erigolon          #+#    #+#             */
/*   Updated: 2022/12/22 12:33:17 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*initialize;

	initialize = (t_list *)malloc(sizeof(t_list));
	if (!initialize)
		return (0);
	initialize->content = content;
	initialize->next = 0;
	return (initialize);
}
