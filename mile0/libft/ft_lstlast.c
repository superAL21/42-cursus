/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:52:37 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/30 14:04:39 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux;

	if (!lst)
		return (NULL);
	aux = lst;
	while (aux -> next)
	{
		aux = aux -> next;
	}
	return (aux);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*top;
	t_list	*temp;
	t_list	*res;
	
	top = NULL;
	ft_lstadd_front(&top, ft_lstnew("a"));
	ft_lstadd_front(&top, ft_lstnew("2"));
	ft_lstadd_front(&top, ft_lstnew("3"));
	res = ft_lstlast(top);
	printf("%s\n", (char *)res -> content);
	while(top != NULL)
	{
		temp = top -> next;
		free(top);
		top = temp;
	}
		return (0);
}
*/