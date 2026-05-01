/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:49:26 by alkhan            #+#    #+#             */
/*   Updated: 2026/05/01 17:42:11 by alkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "sorting.h"
#include "stack.h"
#include <stdbool.h>

bool	is_stack_sorted_rev(t_stack *stack)
{
	t_list	*node;

	node = stack->top;
	if (!node)
		return (true);
	while (node->next)
	{
		if (!(get_content(node)->value > get_content(node->next)->value))
			return (false);
		node = node->next;
	}
	return (true);
}

static void	insertion_sort(t_stacks *stacks)
{
	if (set_stack_b(stacks) != 1)
		return ;		
	move_and_sort_to(stacks);
	rev_move_to(stacks);
}

void move_and_sort_to(t_stacks *stacks, t_stack_name *stackname)
{ 
	int listsize;

	lis
	listsize = ft_lstsize(stacks->a.top);
	while( listsize == 0)
		stacks->b.top->content
}	
// This function is going to set up stack B, before insertion starts, add 3 numbers from stack a, and sort them.
int	set_stack_b(t_stacks *stacks)
{
	while(ft_lstsize(stacks->b.top) < 3)
		push_b(stacks->a);  
	if (is_stack_sorted_rev(stacks->b.top) == true)
		return (1);
	if (stacks->b.top->content > stacks->b.top->next->content && 
		stacks->b.top->content > stacks->b.top->next->next->content)
			return(rotate(stacks->b), swap(stacks->b), 1);
	else if (stacks->b.top->content > stacks->b.top->next->content && 
		stacks->b.top->content < stacks->b.top->next->next->content)
		return(reverse_rotate(stacks->b), 1);
	else if (stacks->b.top->content < stacks->b.top->next->content && 
		stacks->b.top->next->next->content < stacks->b.top->next->content)
		return(rotate(stacks->b), 1);
	else if (stacks->b.top->next->next->content > stacks->b.top->next->content && 
		stacks->b.top->next->content > stacks->b.top->content)
		return(swap(stacks->b), reverse_rotate(stacks->b) , 1);
	else if (stacks->b.top->next->content > stacks->b.top->content && 
		stacks->b.top->next->content > stacks->b.top->next->next->content)
		return(swap(stacks->b), 1);
	return (-1);
}
