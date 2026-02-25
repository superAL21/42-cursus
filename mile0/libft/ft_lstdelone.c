/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:58:14 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/30 16:00:12 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
	return ;
}
/*
#include <stdio.h>

void	delete_str(void *content)
{
	free (content);
}

int	main(void)
{
	t_list	*node;
	char	*str;

	str = ft_strdup("Esto será eliminado");
	node = ft_lstnew(str);
	printf("Esto es lo que había: %s\n", (char *)node -> content);
	ft_lstdelone(node, delete_str);
	return (0);
}
*/