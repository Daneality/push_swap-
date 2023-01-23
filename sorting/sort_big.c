/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:33:33 by dsas              #+#    #+#             */
/*   Updated: 2023/01/23 13:34:42 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



static void	push_slice_b(t_list **stack_a, t_list **stack_b, t_list **sorted_stack)
{
	int		move;
	int		slice_amount;
	int		current_key;
	int		size;

	size = ft_lstsize(*stack_a);
	slice_amount = ft_slice_count(size);
	move = 1;
	current_key = ft_key(stack_a, st_key, slice, move);
	move++;
	ft_push_to_b(stack_a, stack_b, key);
	if (ft_sorted_stack(*stack_a) == true)
		return ;
	while (move < slice)
	{
		key = ft_next_key(*st_key, slice, move);
		ft_push_to_b(stack_a, stack_b, key);
		move++;
	}
}

void	ft_sort_big(t_list **stack_a, t_list **stack_b)
{
	t_list	*sorted_stack;

	if (ft_sorted_stack(*stack_a) == true)
		return ;
	push_slice_b(stack_a, stack_b, &sorted_stack);
}
