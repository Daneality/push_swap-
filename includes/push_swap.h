/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:49:37 by dsas              #+#    #+#             */
/*   Updated: 2023/01/20 16:05:24 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

int			ft_node_find(t_list *stack, int found);
t_list		*new_node(int i);
void		ft_print_list(t_list *ptr);

void		ft_sa(t_list **stack_a);
void		ft_sb(t_list **stack_b);
void		ft_ss(t_list **stack_a, t_list **stack_b);
void		ft_pa(t_list **stack_a, t_list **stack_b);
void		ft_pb(t_list **stack_a, t_list **stack_b);
void		ft_rotate(t_list **stack);
void		ft_ra(t_list **stack_a);
void		ft_rb(t_list **stack_b);
void		ft_rr(t_list **stack_a, t_list **stack_b);
void		ft_revrotate(t_list **stack);
void		ft_rra(t_list **stack_a);
void		ft_rrb(t_list **stack_b);
void		ft_rrr(t_list **stack_a, t_list **stack_b);
int			ft_get_input(int argc, char **argv, t_list **stack_a);
long long	ft_atol(char *str);
int			check_arg(char *arg);
int			check_duplicates(int value, t_list **stack_a);

int			ft_node_find(t_list *stack, int found);
int			ft_mid(int size);
int			ft_min(t_list *stack);
int			ft_max(t_list *stack);
int			ft_next_max(t_list *stack, int max);

#endif
