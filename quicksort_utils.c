/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:24:45 by alkhan            #+#    #+#             */
/*   Updated: 2026/05/11 15:05:57 by alkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list_utils.h"
#include "operations.h"
#include "position_utils.h"
#include "sorting.h"
#include "stack.h"
#include <stdbool.h>

void	alis_quickie(t_stacks *stacks)
{
	int				listsize;
	t_list_contents	*pivot_content;
	int				pivot_count;

	pivot_count = 0;
	listsize = ft_lstsize(stacks->a.top);
	if (listsize <= 0)
		return ;
	if (listsize <= 75)
		pivot_content = find_pivots(stacks, pivot_count += 1);
	else if (listsize > 75 && listsize <= 125)
		pivot_content = find_pivots(stacks, pivot_count += 2);
	else if (listsize > 125 && listsize <= 250)
		pivot_content = find_pivots(stacks, pivot_count += 3);
	else if (listsize > 250)
		pivot_content = find_pivots(stacks, pivot_count += 4);
	start_quickie_pivots(stacks, pivot_content, pivot_count);
	start_moving_back(stacks);
	free(pivot_content);
}

void	start_moving_back(t_stacks *stacks)
{
	int	index_a;
	int	index_b;
	int	moves_a;
	int	moves_b;

	set_stack_a(stacks);
	while (ft_lstsize(stacks->b.top) != 0)
	{
		index_b = find_selection_pos(stacks);
		index_a = find_insert_pos(&stacks->a,
				get_content(stacks->b.top)->value);
		if (index_a < (ft_lstsize(stacks->a.top) - index_a))
			moves_a = index_a;
		else
			moves_a = ft_lstsize(stacks->a.top) - index_a;
		if (index_b < (ft_lstsize(stacks->b.top) - index_b))
			moves_b = index_b;
		else
			moves_b = ft_lstsize(stacks->b.top) - index_b;
		if (moves_b > moves_a)
			insertion(stacks, index_a);
		else
			selection(stacks, index_b);
	}
}

void	insertion(t_stacks *stacks, int index)
{
	if (index < ft_lstsize(stacks->a.top) - index)
	{
		while (index != 0)
		{
			opp_rot(stacks, A);
			index--;
		}
	}
	else
	{
		while (index != ft_lstsize(stacks->a.top) + 1)
		{
			opp_rrot(stacks, A);
			index++;
		}
	}
	opp_push(stacks, A);
}

void	selection(t_stacks *stacks, int index)
{
	if (index < ft_lstsize(stacks->b.top) - index)
	{
		while (index != 0)
		{
			opp_rot(stacks, B);
			index--;
		}
	}
	else
	{
		while (index != ft_lstsize(stacks->b.top) + 1)
		{
			opp_rrot(stacks, B);
			index++;
		}
	}
	opp_push(stacks, A);
}

int	find_selection_pos(t_stacks *stacks)
{
	t_list	*node;
	int		max_value;
	int		counter;

	counter = 0;
	node = stacks->b.top;
	max_value = get_content(node)->value;
	while (node)
	{
		if (node->next != NULL && get_content(node->next)->value > max_value)
			max_value = get_content(node->next)->value;
		node = node->next;
	}
	node = stacks->b.top;
	while (get_content(node->next)->value != max_value)
	{
		counter++;
		node = node->next;
	}
	return (counter);
}

int	set_stack_a(t_stacks *stacks)
{
	while (ft_lstsize(stacks->a.top) != 3)
		opp_push(stacks, A);
	if (is_stack_sorted(stacks) == true)
		return (1);
	if (get(stacks->a.top, 0)->value > get(stacks->a.top, 1)->value
		&& get(stacks->a.top, 1)->value > get(stacks->a.top, 2)->value)
		return (opp_rot(stacks, A), opp_swap(stacks, A), 1);
	else if (get(stacks->a.top, 0)->value > get(stacks->a.top, 2)->value
		&& get(stacks->a.top, 2)->value > get(stacks->a.top, 1)->value)
		return (opp_rot(stacks, A), 1);
	else if (get(stacks->a.top, 0)->value < get(stacks->a.top, 1)->value
		&& get(stacks->a.top, 2)->value < get(stacks->a.top, 1)->value)
		return (opp_rrot(stacks, A), opp_swap(stacks, A), 1);
	else if (get(stacks->a.top, 2)->value > get(stacks->a.top, 0)->value
		&& get(stacks->a.top, 0)->value > get(stacks->a.top, 1)->value)
		return (opp_swap(stacks, A), 1);
	else if (get(stacks->a.top, 1)->value > get(stacks->a.top, 0)->value
		&& get(stacks->a.top, 0)->value > get(stacks->a.top, 2)->value)
		return (opp_rrot(stacks, A), 1);
	return (-1);
}

bool	is_stack_sorted(t_stacks *stacks)
{
	t_list	*node;

	node = stacks->a.top;
	while (node && node->next != NULL)
	{
		if (!(get_content(node)->value < get_content(node->next)->value))
			return (false);
		node = node->next;
	}
	return (true);
}

// IK KAN HIERIN NOG EEN EXTRA CHECK TOEVOEGEN DOOR TE GAAN KIJKEN WAAR HET
// KLEINSTE GETAL VAN STACK STAAT EN WAAR GROOTSTE GETAL TOT DIE PIVOT STAAT 
// EN BLIJVEN ROTEREN IN MAKKELIJKSTE RICHTING TOT ALLE GETALLEN ZIJ GEWEEST
// EN TUSSENTIJDS PUSHEN.
void	start_quickie_pivots(t_stacks *stacks, t_list_contents *pivots,
		int pivot_count)
{
	int		counter;
	t_list	*node;

	counter = 0;
	node = stacks->a.top;
	while (ft_lstsize(stacks->a.top) != 0)
	{
		while (node)
		{
			if (get_content(node)->value <= pivots[pivot_count].value)
			{
				move_to_b(stacks, counter, ft_lstsize(stacks->a.top));
				node = stacks->a.top;
				counter = 0;
			}
			node = node->next;
			counter++;
		}
	}
}

void	move_to_b(t_stacks *stacks, int move_index, int listsize)
{
	int	i;

	i = move_index;
	if (move_index <= listsize / 2)
	{
		while (i != 0)
		{
			opp_rot(stacks, A);
			i--;
		}
		opp_push(stacks, B);
	}
	else
	{
		while (i != listsize)
		{
			opp_rrot(stacks, A);
			i++;
		}
		opp_push(stacks, B);
	}
}

t_list_contents	*find_pivots(t_stacks *stacks, int amount)
{
	t_list_contents	*pivot_options;
	t_list_contents	*final_pivots;

	pivot_options = malloc((amount * 3) * sizeof(t_list_contents));
	final_pivots = malloc(amount * sizeof(t_list_contents));
	if (!final_pivots || !pivot_options)
		return (NULL);
	pivot_options = find_pivot_options(stacks, amount);
	if (amount >= 1)
		final_pivots[0] = pivot_options[1];
	if (amount >= 2)
		final_pivots[1] = pivot_options[4];
	if (amount >= 3)
		final_pivots[2] = pivot_options[7];
	if (amount == 4)
		final_pivots[3] = pivot_options[10];
	return (free(pivot_options), final_pivots);
}

t_list_contents	*sort_pivot_options(t_list_contents *pivot_options,
		int size_pivot_list)
{
	t_list_contents	*pivot_options_sorted;
	int				smallest;
	int				i;

	i = 0;
	pivot_options_sorted = malloc(size_pivot_list * sizeof(t_list_contents));
	if (!pivot_options_sorted)
		return (NULL);
	while (size_pivot_list != 0)
	{
		smallest = find_smallest_pivot(pivot_options, size_pivot_list);
		pivot_options_sorted[i].value = pivot_options[smallest].value;
		pivot_options_sorted[i].index = pivot_options[smallest].index;
		size_pivot_list--;
		i++;
	}
	return (free(pivot_options), pivot_options_sorted);
}

int	find_smallest_pivot(t_list_contents *pivot_options, int size_pivot_list)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = 0;
	while (i != size_pivot_list)
	{
		if (pivot_options[i].value < pivot_options[smallest].value)
			smallest = i;
		i++;
	}
	return (smallest);
}

// MOET OOK HERSCHREVEN WORDEN OF GESPLITS IN MEERDERE FUNCTIES.
t_list_contents	*find_pivot_options(t_stacks *stacks, int amount)
{
	int				listsize;
	int				chunksize;
	int				remainder;
	int				i;
	t_list_contents	*pivot_options;

	i = 0;
	listsize = ft_lstsize(stacks->a.top);
	chunksize = listsize / amount;
	remainder = listsize % amount;
	pivot_options = malloc((amount * 3) * sizeof(t_list_contents));
	if (!pivot_options)
		return (NULL);
	while (i < amount)
	{
		pivot_options[i * 3] = *get(&stacks->a, (i * chunksize));
		pivot_options[i * 3 + 1] = *get(&stacks->a, ((i * chunksize)
					+ (chunksize / 2)));
		if (i == amount - 1)
			pivot_options[i * 3 + 2] = *get(&stacks->a, ((i * chunksize)
						+ chunksize + remainder));
		else
			pivot_options[i * 3 + 2] = *get(&stacks->a, (i * chunksize)
					+ chunksize);
		i++;
	}
	return (sort_pivot_options(pivot_options, (amount * 3)));
}
