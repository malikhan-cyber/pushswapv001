/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rotate.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/13 14:16:55 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/24 17:23:53 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "operations.h"

// Shift up all elements of the stack by one.
// The first element becomes the last one.
// for use in opp_ra(), opp_rb() and opp_rr()
static void	rotate_stack(t_stack *stack)
{
	ft_lstadd_back(&stack->bottom->next, stack->top);
	stack->bottom = stack->top;
	stack->top = stack->bottom->next;
	stack->bottom->next = NULL;
}

// Shift up all elements of stack a by one.
// The first element becomes the last one.
void	opp_rot(t_stacks *stacks, t_stack_name name)
{
	stacks->info.operations++;
	if (name == A)
	{
		write(1, "ra\n", 4);
		stacks->info.ra++;
		rotate_stack(&stacks->a);
	}
	else if (name == B)
	{
		write(1, "rb\n", 4);
		stacks->info.rb++;
		rotate_stack(&stacks->b);
	}
	else
	{
		write(1, "rrr\n", 4);
		stacks->info.rrr++;
		rotate_stack(&stacks->a);
		rotate_stack(&stacks->b);
	}
}
