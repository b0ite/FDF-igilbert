/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:02:18 by igilbert          #+#    #+#             */
/*   Updated: 2024/11/07 18:05:45 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ret;

	if (!lst)
		return (NULL);
	ret = malloc(sizeof(t_list) + 1);
	ret = lst;
	while (ret->next != NULL)
		ret = ret->next;
	return (ret);
}
