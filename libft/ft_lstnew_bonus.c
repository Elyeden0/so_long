/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:12:55 by abonnard          #+#    #+#             */
/*   Updated: 2024/12/16 15:01:57 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_Llist	*ft_lstnew(void *content)
{
	t_Llist	*new;

	new = (t_Llist *)malloc(sizeof(t_Llist));
	new->content = content;
	new->next = NULL;
	return (new);
}
