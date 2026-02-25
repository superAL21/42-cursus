/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:11:27 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/02 15:20:42 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*my_list;
	t_list	*my_node;
	void	*res;

	my_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		res = f(lst -> content);
		my_node = ft_lstnew(res);
		if (!my_node)
		{
			del(res);
			ft_lstclear(&my_list, del);
			return (NULL);
		}
		ft_lstadd_back(&my_list, my_node);
		lst = lst -> next;
	}
	return (my_list);
}
/*
#include <stdio.h>

void	*print_put(void *content)
{
	printf("Mapeando: %s\n", (char *)content);
	return (ft_strdup((char *)content));
}

int	main(void)
{
	t_list	*my_list;
	t_list	*new_list;

	my_list = ft_lstnew(ft_strdup("línea de prueba 1"));
	ft_lstadd_back(&my_list, ft_lstnew(ft_strdup("línea de prueba 2")));
	new_list = ft_lstmap(my_list, print_put, free);
	ft_lstclear(&my_list, free);
	ft_lstclear(&new_list, free);
	return (0);
}
*/