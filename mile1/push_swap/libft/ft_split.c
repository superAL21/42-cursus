/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:39:01 by lajen-li          #+#    #+#             */
/*   Updated: 2026/03/02 12:33:40 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(const char *s, char c)
{
	size_t	is_word;
	size_t	count;

	count = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c && is_word == 0)
		{
			is_word = 1;
			count++;
		}
		if (*s == c)
		{
			is_word = 0;
		}
		s++;
	}
	return (count);
}

int	word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	return (len);
}

void	free_all(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	res = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = word_len(s, c);
			res[i] = ft_substr(s, 0, len);
			if (!res[i++])
				return (free_all(res), NULL);
			s = s + len;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}

/* #include <stdio.h>

int	main(void)
{
	char	**subs;
	int	i;
	i = 0;
	subs = ft_split("Hola a todos. a b c", ' ');

	if(!subs)
		return(1);
	while (subs[i])
	{
		printf("Este es el resultado %s\n", subs[i]);
		free(subs[i]);
		i++;
	}
	free(subs);
} */