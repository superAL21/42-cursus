/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:52:23 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/17 16:29:29 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while(*s)
	{
		s++;
		count++;
	}
	return (count);
}
char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char) c;
	while (*s  != '\0')
	{
		if(*s == ch)
		{
			return ((char *)s);
		}
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}
char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	i;

	new = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(src);
	if (size == 0)
	{
		return (len_s);
	}
	while (src[i] != '\0' && i + 1 < size)
	{
		dst[i] = src [i];
		i++;
	}
	dst[i] = '\0';
	return (len_s);
}
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_s;
	size_t	len_d;

	len_s = ft_strlen(src);
	if (size == 0)
	{
		return (len_s);
	}
	len_d = ft_strlen(dst);
	if (size <= len_d)
	{
		return (len_s + size);
	}
	i = 0;
	while (src[i] != '\0' && len_d + i < size -1)
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_s + len_d);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	new = malloc((len_1 + len_2 + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, len_1 + len_2 + 1);
	ft_strlcat(new, s2, len_1 + len_2 + 1);
	return (new);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*sub;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
char	*ft_free_join(char const *s1, char const *s2)
{
	char	*temp;

	if(!s1)
		s1 = ft_strdup("");
	temp = ft_strjoin(s1, s2);
	free((void *)s1);
	return (temp);
}