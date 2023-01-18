/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:45:39 by dsas              #+#    #+#             */
/*   Updated: 2023/01/18 19:49:00 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list		*new_node(int i)
{
	int	*i_ptr;	

	i_ptr = malloc(sizeof(int));
	if (!i_ptr)
		return (NULL);
	*i_ptr = i;
	return (ft_lstnew(i_ptr));
}