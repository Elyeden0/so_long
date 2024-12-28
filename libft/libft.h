/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:54:31 by abonnard          #+#    #+#             */
/*   Updated: 2024/12/16 15:02:33 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_calloc(size_t count, size_t size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
long	ft_atol(const char *str);
int		ft_error(void);

typedef struct s_Llist
{
	void			*content;
	struct s_Llist	*next;
}					t_Llist;

t_Llist	*ft_lstnew(void *content);
t_Llist	*ft_lstmap(t_Llist *lst, void *(*f)(void *), void (*del)(void *));
t_Llist	*ft_lstlast(t_Llist *lst);
int		ft_lstsize(t_Llist *lst);
void	ft_lstiter(t_Llist *lst, void (*f)(void *));
void	ft_lstdelone(t_Llist *lst, void (*del)(void*));
void	ft_lstclear(t_Llist **lst, void (*del)(void*));
void	ft_lstadd_front(t_Llist **lst, t_Llist *new);
void	ft_lstadd_back(t_Llist **lst, t_Llist *new);

#endif
