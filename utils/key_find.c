/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:02:19 by dsas              #+#    #+#             */
/*   Updated: 2023/01/20 17:22:58 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_stack(t_list **list)
{
	int	i;
	int	j;
	int	len;
	t_list	*current;
	int	*tmp;

	if (! list)
		return;
	i = 0;
	j = 0;
	current = *list;
	len = ft_lstsize(current) - 1;
	while (i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (*(int *)(current->content) > *(int *)(current->next->content))
			{
				tmp = current->content;
				current->content = current->next->content;
				current->next->content = tmp;
			}
			current = current->next;
		}
		current = *list;
		i++;
	}
}

t_list		*ft_copy_stack(t_list *stack_a)
{
	return (stack_a);
}
