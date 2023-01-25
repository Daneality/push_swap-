/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotating.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:34:52 by dsas              #+#    #+#             */
/*   Updated: 2023/01/25 16:23:53 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*stack_to_arr(t_list *stack)
{
	int		stack_size;
	int		*ret;
	int		i;
	t_list	*tmp;

	if (!stack)
		return (NULL);
	stack_size = ft_lstsize(stack);
	ret = (int *)malloc(sizeof(int) * (stack_size + 1));
	i = 1;
	tmp = stack;
	ret[0] = stack_size;
	while (tmp != NULL)
	{
		ret[i] = *(int *)(tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (ret);
}

void	put_min_elem_on_top(t_list **stack)
{
	int	min_elem;
	int	ind;
	int	stack_size;
	int	i;

	min_elem = ft_min(*stack);
	ind = value_at_pos(*stack, min_elem);
	stack_size = ft_lstsize(*stack);
	i = 0;
	if (ind > stack_size / 2)
	{
		while (i < stack_size - ind)
		{
			ft_revrotate(stack);
			i++;
		}
	}
	else
	{
		while (i < ind)
		{
			ft_rotate(stack);
			i++;
		}
	}
}
