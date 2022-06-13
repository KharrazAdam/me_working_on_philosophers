/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_func_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:28:47 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/13 10:29:12 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == 0)
		return (NULL);
	new->id = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (ptr->next != *lst)
			ptr = ptr->next;
		ptr->next = new;
	}
	new->next = *lst;
}

int	ft_lstsize(t_list *lst)
{
	int	x;

	x = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		x++;
	}
	return (x);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*head;
	t_list	*tmp;

	head = *lst;
	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
