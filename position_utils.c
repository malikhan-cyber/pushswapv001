/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 10:08:18 by alkhan            #+#    #+#             */
/*   Updated: 2026/05/11 10:34:28 by alkhan           ###   ########.fr       */
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
	int		max_value;
	int		pos;

	max_value = find_max_value(stack);
	pos = 0;
	node = stack->top;
	while (node)
	{
		if (max_value == ((t_list_contents *)node->content)->value)
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

int	find_insert_pos_rev(t_stack *stack, int value)
{
	int		counter;
	t_list	*node;

	counter = 0;
	node = stack->top;
	if (value > find_max_value(stack))
		return(find_max_position(stack));
	if (value < find_min_value(stack))
	{
		if (find_min_pos(stack) == ft_lstsize(stack))
			return (ft_lstsize(stack));
		return (find_min_pos(stack) + 1);
	}
	while (counter != ft_lstsize(stack))
	{
		if (node->next && ((value < get_content(node)->value)
				&& (value > get_content(node->next)->value)))
			return (counter+1);
		node = node->next;
		counter++;
	}
}
//MOET HERSCHREVEN WORDEN, DIT IS LOGICA VOOR STACK B,
// VAN GROOT NAAR KLEIN HET MOET ANDERSOM
int	find_insert_pos(t_stack *stack, int value)
{
	int		counter;
	t_list	*node;

	counter = 0;
	node = stack->top;
	if (value > find_max_value(stack))
		return(find_max_position(stack));
	if (value < find_min_value(stack))
	{
		if (find_min_pos(stack) == ft_lstsize(stack))
			return (ft_lstsize(stack));
		return (find_min_pos(stack) - 1);
	}
	while (counter != ft_lstsize(stack))
	{
		if (node->next && ((value < get_content(node)->value)
				&& (value > get_content(node->next)->value)))
			return (counter+1);
		node = node->next;
		counter++;
	}
}
