/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:34:25 by dsas              #+#    #+#             */
/*   Updated: 2023/01/24 14:56:18 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_list **stack)
{
	int	first;
	int second;
	int third;

	first = *(int *)((*stack)->content);
	second = *(int *)((*stack)->next->content);
	third = *(int *)((*stack)->next->next->content);
	if ((first > second) && (first < third))
		ft_sa(stack);
	else if ((first > second) && (second > third))
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else if ((third > second) && (third < first))
		ft_ra(stack);
	else if ((second > third) && (third < first))
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else if ((second > first) && (first > third))
		ft_rra(stack);
}

void	ft_push_mins_to_b(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int min;
	int mid;
	int pos;

	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		min = ft_min(*stack_a);
		mid = ft_mid(size);
		pos = ft_node_find(*stack_a, min);
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
		size--;
	}
}

void	ft_sort_small(t_list **stack_a, t_list **stack_b)
{
	if ((ft_issorted(*stack_a)))
		return ;
	if (ft_lstsize(*stack_a) == 2)
	{
		ft_sa(stack_a);
		return ;
	}
	ft_push_mins_to_b(stack_a, stack_b);
	if (!ft_issorted(*stack_a))
		sort_three(stack_a);
	while (*stack_b != NULL)
		ft_pa(stack_a, stack_b);
}
