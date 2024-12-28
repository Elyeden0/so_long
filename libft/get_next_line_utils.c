/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:44:27 by abonnard          #+#    #+#             */
/*   Updated: 2024/10/27 18:46:57 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			c;

	p = s;
	c = '\0';
	while (n-- > 0)
	{
		*p = (unsigned char)c;
		p++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
		return ((void *)malloc(0));
	total_size = nmemb * size;
	if (total_size / nmemb != size)
		return (NULL);
	alloc = (void *)malloc(total_size);
	if (!alloc)
		return (NULL);
	ft_bzero(((unsigned char *)alloc), (total_size));
	return (alloc);
}

char	*ft_strchr(const char *str, int char_to_find)
{
	while (*str != (unsigned char)char_to_find)
	{
		if (!*str)
			return (0);
		str++;
	}
	return ((char *)str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[len] = '\0';
	return (str);
} */
