/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:51:07 by ccartet           #+#    #+#             */
/*   Updated: 2021/12/10 12:17:23 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (*alst)
		ft_lstlast(*alst)->next = new;
	else
		*alst = new;
}

/*int main()
{
	t_list	*list;

	list = NULL;
	ft_lstadd_back(&list, ft_lstnew("Hello"));
	ft_lstadd_back(&list, ft_lsLSTADtnew(" World !"));
}*/