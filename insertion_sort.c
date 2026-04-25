/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:49:26 by alkhan            #+#    #+#             */
/*   Updated: 2026/04/25 17:57:41 by alkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "sorting.h"

static void	insertion_sort(t_stacks *stacks)
{
	move_and_sort_to(stacks, B);
	rev_move_to(stacks, A);
}

move_and_sort_to(t_stacks *stacks, t_stack_name *stackname)
{
	push_a();
	push_a();
	push_a();
	
	if (stacks_b->value > stack_b->-next->value && stack_b->-next->value > stack_b->-next->next->value )
		start_insertion();
	if(strs)
}	
