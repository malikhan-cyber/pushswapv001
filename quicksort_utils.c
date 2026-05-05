/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */ 
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:24:45 by alkhan            #+#    #+#             */
/*   Updated: 2026/04/29 16:03:56 by alkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "list_utils.h"

void	alis_quickie(t_stacks *stacks)
{
	int				listsize;
	t_list_contents	*pivot_content;
	int	pivot_count;

	pivot_count =  0;
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
	reverse_insertion(stacks->b.top);
	free(pivot_content);
}
void start_quickie_pivots(t_stacks *stacks, t_list_contents *pivots, int pivot_count)
{
	t_list *node;

	node = stacks->a.top;
	while(get_content(node)->value )
		node = node->next;
}
t_list_contents	*find_pivots(t_stacks *stacks, int amount)
{
	t_list_contents	*pivot_options;
	t_list_contents *final_pivots;

	pivot_options = malloc((amount * 3) * sizeof(t_list_contents));
	final_pivots = malloc(amount * sizeof(t_list_contents));
	if(!final_pivots || !pivot_options)
		return (NULL);
	pivot_options = find_pivot_options(stacks, amount);
	if(amount == 1)
		final_pivots[0] = pivot_options[2];
	if (amount ==  2)
	{
		final_pivots[0] = pivot_options[2];
		final_pivots[1] = pivot_options[5];
	}
	if (amount ==  3)
	{
		final_pivots[0] = pivot_options[2];
		final_pivots[1] = pivot_options[5];
		final_pivots[2] = pivot_options[8];
	}
	if (amount ==  4)
	{
		final_pivots[0] = pivot_options[2];
		final_pivots[1] = pivot_options[5];
		final_pivots[2] = pivot_options[8];
		final_pivots[3] = pivot_options[11];
	}
	return(free(pivot_options), pivot_options = NULL, final_pivots);
}

t_list_contents *sort_pivot_options(t_list_contents *pivot_options, int size_pivot_list)
{
	t_list_contents *pivot_options_sorted;
	int	smallest;
	int i;

	i = 0;
	pivot_options_sorted = malloc(size_pivot_list * sizeof(t_list_contents));
	if (!pivot_options);
		return (NULL);
	while(size_pivot_list != 0)
		{
			smallest = find_smallest_pivot(pivot_options, size_pivot_list);
			pivot_options_sorted[i].value = pivot_options[smallest].value;
			pivot_options_sorted[i].index = pivot_options[smallest].index;
			size_pivot_list--;
			i++;
		}
	return(free(pivot_options), pivot_options= NULL, pivot_options_sorted);
}

int	find_smallest_pivot(t_list_contents *pivot_options, int size_pivot_list)
{
	int i;
	int smallest;

	i = 0;
	smallest = 0;
	while (i != size_pivot_list)
		{
			if(pivot_options[i].value < pivot_options[smallest].value)
				smallest = i;
			i++;
		}
	return(smallest);
}

t_list_contents	*find_pivot_options(t_stacks *stacks, int amount)
{
	int				listsize;
	int				chunksize;
	int				remainder;
	int 			i;
	t_list_contents	*pivot_options;

	i = 0;
	listsize = ft_lstsize(stacks->a.top);
	chunksize = listsize / amount;
	remainder = listsize % amount;
	pivot_options = malloc((amount * 3) * sizeof(t_list_contents));
	if(!pivot_options)
		return( NULL);
	while(i < amount)
	{
		pivot_options[i * 3] = *get(&stacks->a, (i * chunksize));
		pivot_options [i * 3 + 1] = *get(&stacks->a, ((i * chunksize) + (chunksize/2)));
		if (i == amount -1)
		 pivot_options [i * 3 + 2] = *get(&stacks->a, ((i * chunksize) + chunksize + remainder));
		else
		pivot_options [i * 3 + 2] = *get(&stacks->a, (i * chunksize) + chunksize);
		i++;
	}
	pivot_options = sort_pivot_options(pivot_options, (amount * 3));
	return(pivot_options);
}

// t_stacks → t_stack → t_list → t_list_contents

// Ja precies! In stack.h staan in totaal 4 structs:

// t_list_contents — één getal (value + index)
// t_stack — één stack (top, bottom)
// t_sorting_info — het logboek (telt operaties)
// t_stacks — de grote wrapper die de andere 3 bevat