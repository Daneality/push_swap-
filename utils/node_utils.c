/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:45:39 by dsas              #+#    #+#             */
/*   Updated: 2023/01/20 17:50:18 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*new_node(int i)
{
	int	*i_ptr;	

	i_ptr = malloc(sizeof(int));
	if (!i_ptr)
		return (NULL);
	*i_ptr = i;
	return (ft_lstnew(i_ptr));
}

int	value_at_pos(t_list *stack, int pos)
{
	int	i;

	i = 0;
	while (i != pos)
	{
		stack = stack->next;
	}
	return (*(int *)(stack->content));
}
