/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:49:26 by alkhan            #+#    #+#             */
/*   Updated: 2026/05/08 13:12:39 by alkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list_utils.h"
#include "operations.h"
#include "sorting.h"
#include "stack.h"
#include <stdbool.h>
#include "position_utils.h"

static void	insertion_sort(t_stacks *stacks)
{
	int	insert_position;

	if (set_stack_b(stacks) != 1)
		return ;
	while(stacks->b.top)
		{	
			insert_position = find_insert_pos(&stacks->b, get_content(stacks->a.top)->value);
			rotate_and_move(stacks, insert_position);
		}
	rev_move_to(stacks);
}

// This function is going to set up stack B, before insertion starts,
// add 3 numbers from stack a, and sort them.

int	set_stack_b(t_stacks *stacks)
{
	while (ft_lstsize(stacks->b.top) != 3)
		opp_push(stacks, B);
	if (is_stack_sorted_rev(stacks->b.top) == true)
		return (1);
	if (get_content(stacks->b.top)->value > get_content(stacks->b.top->next)->value
		&& get_content(stacks->b.top)->value > get_content(stacks->b.top->next->next)->value)
		return (opp_rot(stacks, B), opp_swap(stacks, B), 1);
	else if (get_content(stacks->b.top)->value > get_content(stacks->b.top->next)->value
		&& get_content(stacks->b.top)->value < get_content(stacks->b.top->next->next)->value)
		return (opp_rrot(stacks, B), 1);
	else if (get_content(stacks->b.top)->value < get_content(stacks->b.top->next)->value
		&& get_content(stacks->b.top->next->next)->value < get_content(stacks->b.top->next)->value)
		return (opp_rot(stacks, B), 1);
	else if (get_content(stacks->b.top->next->next)->value > get_content(stacks->b.top->next)->value
		&& get_content(stacks->b.top->next)->value > get_content(stacks->b.top)->value)
		return (opp_swap(stacks, B), opp_rrot(stacks, B), 1);
	else if (get_content(stacks->b.top->next)->value > get_content(stacks->b.top)->value
		&& get_content(stacks->b.top->next)->value > get_content(stacks->b.top->next->next)->value)
		return (opp_swap(stacks, B), 1);
	return (-1);
}
bool	is_stack_sorted_rev(t_stack *stacks)
{
	t_list	*node;

	node = stacks->top;
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
		if ((ft_lstsize(stacks->b.top) / 2) < current_pos)
			opp_rot(stacks, B);
		else
			opp_rrot(stacks, B);
	if (current_pos == 0)
		opp_push(stacks, B);
}
void	rev_move_to(t_stacks *stacks)
{
	while(stacks->b.top)
		opp_push(stacks, A);
}


// void	move_and_sort_to(t_stacks *stacks, t_stack_name *stackname)
// {
// 	int	move_pos;

// 	while (ft_lstsize(stacks->a.top) != 0)
// 	{
// 		move_pos = find_pos_in_b(stacks, get_content(stacks->a.top)->value);
// 		rotate_and_move(stacks, move_pos);
// 	}
// 	while (ft_lstsize(stacks->b.top))
// 		opp_push(stacks, B);
// }
