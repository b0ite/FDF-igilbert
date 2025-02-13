/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:49:29 by igilbert          #+#    #+#             */
/*   Updated: 2024/11/05 00:00:01 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 1;
	while (lst->next != NULL)
	{
		lst->next = lst->next->next;
		i++;
	}
	return (i);
}
