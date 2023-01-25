/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:31:49 by dsas              #+#    #+#             */
/*   Updated: 2023/01/25 17:34:46 by dsas             ###   ########.fr       */
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
	//int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (!ft_get_input(argc, argv, &stack_a))
	{
		ft_lstclear(&stack_a, free);
		return (-1);
	}
	print_list(stack_a);

	ft_push_not_lls_to_b(&stack_a, &stack_b);
	//put_min_elem_on_top(&stack_a);

	print_list(stack_a);
	print_list(stack_b);
	// size = ft_lstsize(stack_a);
	// if (size <= 10)
	// 	ft_sort_small(&stack_a, &stack_b);
	// else
	// 	ft_sort_big(&stack_a, &stack_b);

	// ft_sort_big(&stack_a, &stack_b);

	//print_list(stack_a);

	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
