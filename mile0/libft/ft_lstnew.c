/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:37 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/30 11:43:08 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}
/*
#include <stdio.h>

int main(void)
{
	t_list	*node;
	char 	*text;

	text = "Hola, mundo!";
	node = ft_lstnew(text);
	printf("El contenido del nodo: %s\n", (char *)node->content);
	free(node);
	return (0);
}
*/