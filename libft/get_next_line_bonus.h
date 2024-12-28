/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:09:13 by abonnard          #+#    #+#             */
/*   Updated: 2024/11/25 17:44:11 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

size_t	ft_strlen(const char *str); */

char	*get_next_line(int fd);
/* char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int char_to_find); */

#endif
