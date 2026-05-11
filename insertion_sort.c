/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:49:26 by alkhan            #+#    #+#             */
/*   Updated: 2026/05/11 11:55:22 by alkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list_utils.h"
#include "operations.h"
#include "position_utils.h"
#include "sorting.h"
#include "stack.h"
#include <stdbool.h>

static void	insertion_sort(t_stacks *stacks)
{
	int	insert_position;

	if (set_stack_b(stacks) != 1)
		return ;
	while (stacks->b.top)
	{
		insert_position = find_insert_pos_rev(&stacks->b,
				get_content(stacks->a.top)->value);
		rotate_and_move(stacks, insert_position);
	}
}

// This function is going to set up stack B, before insertion starts,
// add 3 numbers from stack a, and sort them.

int	set_stack_b(t_stacks *stacks)
{
	while (ft_lstsize(stacks->b.top) != 3)
		opp_push(stacks, B);
	if (is_stack_sorted_rev(stacks) == true)
		return (1);
	if (get_content(stacks->b.top)->value > get_content(stacks->b.top->next->next)->value
		&& get_content(stacks->b.top->next->next)->value > get_content(stacks->b.top->next)->value)
		return (opp_rrot(stacks, B), opp_swap(stacks, B), 1);
	else if (get_content(stacks->b.top->next)->value > get_content(stacks->b.top)->value
		&& get_content(stacks->b.top)->value > get_content(stacks->b.top->next->next)->value)
		return (opp_swap(stacks, B), 1);
	else if (get_content(stacks->b.top->next->next)->value > get_content(stacks->b.top)->value
		&& get_content(stacks->b.top)->value > get_content(stacks->b.top->next)->value)
		return (opp_rrot(stacks, B), 1);
	else if (get_content(stacks->b.top->next)->value > get_content(stacks->b.top->next->next)->value
		&& get_content(stacks->b.top->next->next)->value > get_content(stacks->b.top)->value)
		return (opp_rot(stacks, B), 1);
	else if (get_content(stacks->b.top->next->next)->value > get_content(stacks->b.top->next)->value
		&& get_content(stacks->b.top->next)->value > get_content(stacks->b.top)->value)
		return (opp_swap(stacks, B), opp_rot(stacks, B), 1);
	return (-1);
}
bool	is_stack_sorted_rev(t_stacks *stacks)
{
	t_list	*node;

	node = stacks->b.top;
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

void	rotate_and_move(t_stacks *stacks, int current_pos)
{
	while (current_pos != 0)
	{
		if ((ft_lstsize(stacks->b.top) / 2) < current_pos)
			opp_rot(stacks, B);
		else
			opp_rrot(stacks, B);
		current_pos--;
	}
	if (current_pos == 0)
		opp_push(stacks, A);
}