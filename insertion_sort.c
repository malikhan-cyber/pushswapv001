/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:49:26 by alkhan            #+#    #+#             */
/*   Updated: 2026/05/02 15:43:53 by alkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list_utils.h"
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
	move_and_sort_to(stacks, B);
	rev_move_to(stacks);
}
int	find_pos_in_b(t_stacks *stacks, int value)
{
	int		max_value;
	int		min_value;
	t_list	*node_b;

	node_b = stacks->b.top;
	max_value = find_max_value();
	min_value = find_min_value();
	if (value > max_value)
	{
		if (find_max_pos() == 0)
			return (0);
		else
			return (find_max_pos() - 1);
	}
	while (node_b)
	{
		if (value > get_content(node_b)->value)
			;
		node_b = node_b->next;
	}
}
void	move_and_sort_to(t_stacks *stacks, t_stack_name *stackname)
{
	int	listsize;

	listsize = ft_lstsize(stacks->a.top);
	while (listsize > 0)
		stacks->b.top->content
}
// This function is going to set up stack B, before insertion starts,
// add 3 numbers from stack a, and sort them.

int	set_stack_b(t_stacks *stacks)
{
	while (ft_lstsize(stacks->b.top) < 3)
		opp_push(stacks, A);
	if (is_stack_sorted_rev(stacks->b.top) == true)
		return (1);
	if (get_content(stacks->b.top)->value > get_content(stacks->b.top->next)->value
		&& get_content(stacks->b.top)->value > get_content(stacks->b.top->next->next)->value)
		return (rotate(stacks->b), swap(stacks->b), 1);
	else if (get_content(stacks->b.top)->value > get_content(stacks->b.top->next)->value
		&& get_content(stacks->b.top)->value < get_content(stacks->b.top->next->next)->value)
		return (reverse_rotate(stacks->b), 1);
	else if (get_content(stacks->b.top)->value < get_content(stacks->b.top->next)->value
		&& get_content(stacks->b.top->next->next)->value < get_content(stacks->b.top->next)->value)
		return (rotate(stacks->b), 1);
	else if (get_content(stacks->b.top->next->next)->value > get_content(stacks->b.top->next)->value
		&& get_content(stacks->b.top->next)->value > get_content(stacks->b.top)->value)
		return (swap(stacks->b), reverse_rotate(stacks->b), 1);
	else if (get_content(stacks->b.top->next)->value > get_content(stacks->b.top)->value
		&& get_content(stacks->b.top->next)->value > get_content(stacks->b.top->next->next)->value)
		return (swap(stacks->b), 1);
	return (-1);
}
