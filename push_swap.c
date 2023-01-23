/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:31:49 by dsas              #+#    #+#             */
/*   Updated: 2023/01/23 16:24:03 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

void	print_list(t_list	*head)
{
	while (head)
	{
		printf("%d ", *(int *)head->content);
		head = head->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!ft_get_input(argc, argv, &stack_a))
	{
		ft_lstclear(&stack_a, free);
		return (-1);
	}

	print_list(stack_a);

	ft_sort_big(&stack_a, &stack_b);
	
	print_list(stack_a);

	print_list(stack_b);

	ft_sort_stack(&stack_a);

	print_list(stack_a);
}
