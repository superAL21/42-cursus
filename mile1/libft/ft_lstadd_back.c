/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:08:34 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/30 14:57:38 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last -> next = new;
	return ;
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*back;
	t_list	*my_list;
	char	*text1;
	char	*text2;
	
	text1 = "Ser o no ser";
	text2 = "he ahí el dilema...";
	my_list = ft_lstnew(text2);
	back = ft_lstnew(text1);
	ft_lstadd_back(&my_list, back);
	printf("Resultado 1: %s\n", (char *) my_list -> content);
	printf("Resultado 2: %s\n", (char *) my_list -> next -> content);
	free(back);
	free(my_list);
	return (0);
}
*/