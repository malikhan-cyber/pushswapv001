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

int	find_ideal_pivot(t_stack *stack, t_segment segment)
{
	int	pivot[3];

	pivot[0] = get(stack, segment.start);
	pivot[1] = get(stack, segment.end);
	pivot[2] = get(stack, segment.end - segment.start);
	return (ft_median_pivot(pivot[0], pivot[1], pivot[2]));
}

int	ft_median_pivot(int first, int middle, int last)
{
	int	result;

	if (middle > first && middle < last || middle > last && middle < first)
		result = middle;
	else if (first > middle && first < last || first > last && first < middle)
		result = first;
	else
		result = last;
	return (result);
}
void	alis_quickie(t_stacks *stacks)
{
	int				listsize;
	t_list_contents	*pivot_content;

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
	start_quickie_pivots(stacks->a.top, pivot_content);
	reverse_insertion(stacks->b.top);
	free(pivot_content);
}
t_list_contents	*find_pivots(t_stacks *stacks, int amount)
{
	t_list_contents	*pivot_options;
	
	pivot_options = find_pivot_options(stacks, amount);
	
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
	return(pivot_options);
}

// t_stacks → t_stack → t_list → t_list_contents

// Ja precies! In stack.h staan in totaal 4 structs:

// t_list_contents — één getal (value + index)
// t_stack — één stack (top, bottom)
// t_sorting_info — het logboek (telt operaties)
// t_stacks — de grote wrapper die de andere 3 bevat