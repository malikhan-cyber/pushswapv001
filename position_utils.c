/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 10:08:18 by alkhan            #+#    #+#             */
/*   Updated: 2026/05/08 14:07:06 by alkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "stack.h"
#include "list_utils.h"

int	find_min_value(t_stack *stack)
{
	t_list	*node;
	int		min_value;

	node = stack->top;
	min_value = ((t_list_contents *)node->content)->value;
	while (node)
	{
		if (((t_list_contents *)node->content)->value < min_value)
			min_value = ((t_list_contents *)node->content)->value;
		node = node->next;
	}
	return (min_value);
}

int	find_min_position(t_stack *stack)
{
	t_list	*node;
	int		min_value;
	int		pos;

	min_value = find_min_value(stack);
	pos = 0;
	node = stack->top;
	while (node)
	{
		if (min_value == ((t_list_contents *)node->content)->value)
			return (pos);
		node = node->next;
		pos++;
	}
	return (-1);
}
int	find_max_position(t_stack *stack)
{
	t_list	*node;
	int		min_value;
	int		pos;

	min_value = find_max_value(stack);
	pos = 0;
	node = stack->top;
	while (node)
	{
		if (min_value == ((t_list_contents *)node->content)->value)
			return (pos);
		node = node->next;
		pos++;
	}
	return (-1);
}

int	find_max_value(t_stack *stack)
{
	t_list	*node;
	int		max_value;

	node = stack->top;
	max_value = ((t_list_contents *)node->content)->value;
	while (node)
	{
		if (((t_list_contents *)node->content)->value > max_value)
			max_value = ((t_list_contents *)node->content)->value;
		node = node->next;
	}
	return (max_value);
}

bool	is_stack_sorted(t_stack *stack)
{
	t_list	*node;

	node = stack->top;
	if (!node)
		return (true);
	while (node->next)
	{
		if (!(get_content(node)->value < get_content(node->next)->value))
			return (false);
		node = node->next;
	}
	return (true);
}

int	find_insert_pos(t_stack *stack, int value)
{
	int		max_value;
	int		min_value;
	t_list	*node_b;

	node_b = stack->top;
	max_value = find_max_value(stack);
	min_value = find_min_value(stack);
	if (value > max_value)
	{
		if (find_max_pos() == 0)
			return (0);
		else
			return (find_max_pos() - 1);
	}
	if (value < min_value)
	{
		if (find_min_pos() == ft_lstsize(stack))
			return (ft_lstsize(stack));
		else
			return (find_min_pos(stack) + 1);
	}
	while (node_b)
	{
		if (((value < get_content(node_b)->value)
				&& (value > get_content(node_b->next)->value)))
			return (get_content(node_b)->index);
		node_b = node_b->next;
	}
}
