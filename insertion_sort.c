/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:49:26 by alkhan            #+#    #+#             */
/*   Updated: 2026/04/30 16:34:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "sorting.h"

static void	insertion_sort(t_stacks *stacks)
{
	if (set_stack_b(stacks, B) != 1)
		return ;		
	move_and_sort_to(stacks, B);
	rev_move_to(stacks, A);
}

void move_and_sort_to(t_stacks *stacks, t_stack_name *stackname)
{
	
}	
int	set_stack_b(stacks, B)
{
	while(ft_lstsize(stacks, B) < 3)
		push_b(stacks, A);
	if (is_stack_sorted_rev(stacks, B) == 1)
		return (1);
	if (stacks_b->value > stack_b->-next->value && 
		stack_b->value > stack_b->-next->next->value)
			return(rotate(stacks, B), swap(stack,B), 1);
	if (stacks_b->value > stack_b->-next->value && 
		stack_b->value < stack_b->-next->next->value)
		return(reverse_rotate(stacks_B), 1);
	if (stack_b->value < stack_b->next->value)
}