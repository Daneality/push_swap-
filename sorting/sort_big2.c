/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:54:17 by dsas              #+#    #+#             */
/*   Updated: 2023/01/24 14:57:30 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_one_max(t_list **stack_a, t_list **stack_b, int max, int mid)
{
	int	max_pos;
	int	size;

	size = ft_lstsize(*stack_b);
	max_pos = ft_node_find(*stack_b, max);
	while (max_pos)
	{
		if(max_pos <= mid)
		{
			ft_rb(stack_b);
			max_pos--;
		}
		else
		{
			ft_rrb(stack_b);
			max_pos++;
		}
		if (max_pos == size)
			break;
	}
	ft_pa(stack_a, stack_b);
}

void	ft_push_maxes(t_list **stack_a, t_list **stack_b, int max, int next_max)
{
	int	max_pos;
	int next_max_pos;
	int	size;
	int	mid;

	size = ft_lstsize(*stack_b);
	mid = ft_mid(size);
	max_pos = ft_node_find(*stack_b, max);
	next_max_pos = ft_node_find(*stack_b, next_max);
	if ((max_pos <= mid) && (next_max_pos < mid) && \
		(next_max_pos < max_pos) && (next_max_pos != -1))
	{
		ft_push_one_max(stack_a, stack_b, next_max, mid);
		ft_push_one_max(stack_a, stack_b, max, --mid);
		ft_sa(stack_a);
	}
	else if ((max_pos > mid) && (next_max_pos > mid) && \
		(next_max_pos > max_pos) && (next_max_pos != -1))
	{
		ft_push_one_max(stack_a, stack_b, next_max, mid);
		ft_push_one_max(stack_a, stack_b, max, --mid);
		ft_sa(stack_a);
	}
	else
		ft_push_one_max(stack_a, stack_b, max, mid);
}

void	ft_push_maxs_to_a(t_list **stack_a, t_list **stack_b)
{
	int	max;
	int	next_max;

	if (!stack_b)
		return ;
	max = 0;
	next_max = 0;
	while (*stack_b != NULL)
	{
		max = ft_max(*stack_b);
		if ((*stack_b)->next != NULL)
			next_max = ft_next_max(*stack_b, max);
		ft_push_maxes(stack_a, stack_b, max, next_max);
	}
}
