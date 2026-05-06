/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:24:45 by alkhan            #+#    #+#             */
/*   Updated: 2026/05/06 17:27:46 by alkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list_utils.h"
#include "operations.h"
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
		pivot_content = find_pivots(stacks, 1);
	else if (listsize > 75 && listsize <= 125)
		pivot_content = find_pivots(stacks, 2);
	else if (listsize > 125 && listsize <= 250)
		pivot_content = find_pivots(stacks, 3);
	else if (listsize > 250)
		pivot_content = find_pivots(stacks, 4);
	start_quickie_pivots(stacks->a.top, pivot_content, pivot_count);
	start_moving_back(stacks->b.top);
	free(pivot_content);
}
	
		/* doe de berekeningen door een counter bij te houden en 
		dan te kijken naar hoe ver iets van top of bottem staat 
		hou altijd list-size bij zodat je weet wat eerste en laatste plek is,
		hou een counter bij voor het getal wat je wil inserten of selecten,
		nu kan je met simpele berekeningen alles uitrekenen zonder index te weten.
		
		zoek grootste getal, in stack B
		kijk hoeveel plekken hij van top verwijderd is of van bodem
		sla het kleinste getal op in "selection_moves"
		kijk naar value van getal boven in stack B
		kijk naar juist plek waarin hij geinsert zou moeten worden 
		kijk hoe ver die locatie van top of bodem is verwijderd
		kies kleinste getal en sla op in "insertion_moves"
		afhankelijke van welke minste moves moet maken kies die methode om getal naar A te pushen */
		
void	start_moving_back(t_stacks *stacks)
{
	int index_a;
	int index_b;
	t_list *node;
	
	node = stacks->b.top;
	set_stack_a(stacks);
	while (ft_lstsize(node) != 0)
	{
		index_b = find_selection_value(stacks);
		index_a = insertion_insertion_value(stacks);
		if (index_b < index_a)
			insertion(stacks, index_b);
		else 
			selection(stacks, index_a);
	}
}
void insertion(t_stacks *stacks, int index)
{
	
}
void selection(t_stacks *stacks, int index)
{
	
}
int	find_selection_value(t_stacks *stacks)
{
	t_list *node;
	int max_value;
	int counter;

	counter = 0;
	node = stacks->b.top;
	max_value = get_content(node)->value;
	while(node)
	{
		if(get_content(node->next)->value > max_value)
			max_value = get_content(node->next)->value;
		node = node->next;
		counter++;
	}
	return(counter);
}

int find_insertion_value(t_stacks *stacks)
{
	int	value_b;
	int counter;
	t_list *node;
	
	node = stacks->a.top;
	counter = 0;
	value_b = get_content(stacks->b.top)->value;
	while(node)
		if
}

int	set_stack_a(t_stacks *stacks)
{
	while (ft_lstsize(stacks->a.top) != 3)
		opp_push(stacks, A);
	if (is_stack_sorted_rev(stacks->a.top) == true)
		return (1);
	if (get_content(stacks->a.top)->value > get_content(stacks->a.top->next)->value
		&& get_content(stacks->a.top)->value > get_content(stacks->a.top->next->next)->value)
		return (opp_rot(stacks, A), opp_swap(stacks, A), 1);
	else if (get_content(stacks->a.top)->value > get_content(stacks->a.top->next)->value
		&& get_content(stacks->a.top)->value < get_content(stacks->a.top->next->next)->value)
		return (opp_rrot(stacks, A), 1);
	else if (get_content(stacks->a.top)->value < get_content(stacks->a.top->next)->value
		&& get_content(stacks->a.top->next->next)->value < get_content(stacks->a.top->next)->value)
		return (opp_rot(stacks, A), 1);
	else if (get_content(stacks->a.top->next->next)->value > get_content(stacks->a.top->next)->value
		&& get_content(stacks->a.top->next)->value > get_content(stacks->a.top)->value)
		return (opp_swap(stacks, A), opp_rrot(stacks, A), 1);
	else if (get_content(stacks->a.top->next)->value > get_content(stacks->a.top)->value
		&& get_content(stacks->a.top->next)->value > get_content(stacks->a.top->next->next)->value)
		return (opp_swap(stacks, A), 1);
	return (-1);
}

void	start_quickie_pivots(t_stacks *stacks, t_list_contents *pivots,
		int pivot_count)
{
	t_list	*node;

	node = stacks->a.top;
	while (ft_lstsize(node) != 0)
	{
		while (node)
		{
			if (get_content(node)->value <= pivots[0].value)
				move_to_b(stacks, get_content(node)->index, ft_lstsize(node));
			node = node->next;
		}
	}
}
void	move_to_b(t_stacks *stacks, int move_index, int listsize)
{
	int	i;

	i = move_index;
	if (move_index <= listsize / 2)
		while (i != 0)
		{
			opp_rot(stacks, A);
			i--;
		}
	else
		while (i != listsize)
		{
			opp_rrot(stacks, A);
			i++;
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
	if (amount == 1)
		final_pivots[0] = pivot_options[2];
	if (amount == 2)
	{
		final_pivots[0] = pivot_options[2];
		final_pivots[1] = pivot_options[5];
	}
	if (amount == 3)
	{
		final_pivots[0] = pivot_options[2];
		final_pivots[1] = pivot_options[5];
		final_pivots[2] = pivot_options[8];
	}
	if (amount == 4)
	{
		final_pivots[0] = pivot_options[2];
		final_pivots[1] = pivot_options[5];
		final_pivots[2] = pivot_options[8];
		final_pivots[3] = pivot_options[11];
	}
	return (free(pivot_options), pivot_options = NULL, final_pivots);
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
	return (free(pivot_options), pivot_options = NULL, pivot_options_sorted);
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
	pivot_options = sort_pivot_options(pivot_options, (amount * 3));
	return (pivot_options);
}

// t_stacks → t_stack → t_list → t_list_contents

// Ja precies! In stack.h staan in totaal 4 structs:

// t_list_contents — één getal (value + index)
// t_stack — één stack (top, bottom)
// t_sorting_info — het logboek (telt operaties)
// t_stacks — de grote wrapper die de andere 3 bevat