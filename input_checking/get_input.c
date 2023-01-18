/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:17:04 by dsas              #+#    #+#             */
/*   Updated: 2023/01/18 19:00:33 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_arg(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (! (arg[i] <= '9' && arg[i] >= '0'))
			return (0);
	}
	if (ft_strlen(arg) > 10)
		return (0);
	return (1);
}

int		check_duplicates(int value, t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (*(int *)(tmp->content) == value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_get_input(int argc, char **argv, t_list **stack_a)
{
	
}