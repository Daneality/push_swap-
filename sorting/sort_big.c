/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:33:33 by dsas              #+#    #+#             */
/*   Updated: 2023/01/23 16:29:01 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int 	all_pushed(t_list *stack_a, int key)
{
	while (stack_a)
	{
		if (*(int *)(stack_a->content) < key)
		{
			return (0);
		}
		stack_a = stack_a -> next;
	}
	return (1);
}

static void	ft_push_one_b(t_list **stack_a, t_list **stack_b, int content)
{
	int	pos;
	int	mid;
	int	size;

	size = ft_lstsize(*stack_a);
	mid = ft_mid(size);
	pos = ft_node_find(*stack_a, content);
	while (pos)
	{
		if(pos <= mid)
		{
			ft_ra(stack_a);
			pos--;
		}
		else
		{
			ft_rra(stack_a);
			pos++;
		}
		if (ft_issorted(*stack_a))
			return ;
		if (pos == size)
			break;
	}
	ft_pb(stack_a, stack_b);
}

static void	ft_push_to_b(t_list **stack_a, t_list **stack_b, int key)
{
	t_list	*current;
	int		content;
	int		min;

	current = *stack_a;
	while (! all_pushed(*stack_a, key))
	{
		content = *(int *)(current->content);
		if (content <= key)
		{
			ft_push_one_b(stack_a, stack_b, content);
			current = *stack_a;
		}
		min = ft_min(*stack_b);
		if (content == min)
			ft_rb(stack_b);
		current = current->next;
		if (!current)
			current = *stack_a;
	}
}

static void	push_slice_b(t_list **stack_a, t_list **stack_b, t_list **sorted_stack)
{
	int		move;
	int		slice_amount;
	int		current_key;
	int		size;

	size = ft_lstsize(*stack_a);
	slice_amount = ft_slice_count(size);
	move = 1;
	current_key = ft_key(stack_a, sorted_stack, slice_amount, move);
	move++;
	ft_push_to_b(stack_a, stack_b, current_key);
	if (ft_issorted(*stack_a))
		return ;
	while (move < slice_amount)
	{
		current_key = ft_next_key(*sorted_stack, slice_amount, move);
		ft_push_to_b(stack_a, stack_b, current_key);
		move++;
	}
}

void	ft_sort_big(t_list **stack_a, t_list **stack_b)
{
	t_list	*sorted_stack;

	if (ft_issorted(*stack_a) == 1)
		return ;
	push_slice_b(stack_a, stack_b, &sorted_stack);
}
