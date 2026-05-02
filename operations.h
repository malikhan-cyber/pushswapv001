/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:13:10 by kmurray           #+#    #+#             */
/*   Updated: 2026/05/02 15:53:49 by alkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "stack.h"

// swap.c
// Swap the first two elements at the top of stack.
// Do nothing if there is only one or no elements.
void	opp_swap(t_stacks *stacks, t_stack_name name);

// push.c
// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// void	opp_pa(t_stacks *stacks);
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// void	opp_pb(t_stacks *stacks);

// push from src to dest
void	opp_push(t_stacks *stacks, t_stack_name name);

// rotate.c
// Shift up all elements of stack by one.
// The first element becomes the last one.
void	opp_rot(t_stacks *stacks, t_stack_name name);

// reverse_rotate.c
// Shift down all elements of stack by one.
// The last element becomes the first one.
void	opp_rrot(t_stacks *stacks, t_stack_name name);
#endif
