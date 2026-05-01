/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 10:08:18 by alkhan            #+#    #+#             */
/*   Updated: 2026/05/01 13:09:26 by alkhan           ###   ########.fr       */
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


