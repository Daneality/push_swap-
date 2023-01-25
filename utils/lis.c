/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:03:09 by dsas              #+#    #+#             */
/*   Updated: 2023/01/25 16:20:00 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

ft_push_not_lls_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		*list;
	int		list_size;
	int		i;
	int		*arr;

	tmp = ft_copy_stack(*stack_a);
	put_min_elem_on_top(&tmp);
	arr = stack_to_arr(tmp);
	list = get_lis(&arr[1], arr[0], &list_size, 0);
	arr[0] = get_stack_size(*stack_a);
	i = 1;
	while (i <= arr[0])
	{
		if (int_in_arr(*(int *)((*stack_a)->content), list, list_size))
			ft_ra(stack_a);
		else
			ft_pb(stack_a, stack_b);
		i++;
	}
	ft_lstclear(&tmp, free);
	free(arr);
	free(list);
}