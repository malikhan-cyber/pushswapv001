/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   adaptive_sorting.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/13 18:29:31 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/24 18:01:44 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "sorting.h"
#include "list_utils.h"

float	complexity(t_stack a)
{
	t_list	*i;
	t_list	*j;
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = a.top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs += 1;
			if (get_content(i)->value > get_content(j)->value)
				mistakes += 1;
			j = j->next;
		}
		i = i->next;
	}
	return ((float)mistakes / (float)total_pairs);
}

// Note:
// this currently uses simple sorting for low disorder
// it should run in O(n) time which is harder (probably)
// 
// this can probably use a more complex system anyway
// if disorder is > 0.5 reversing the list might be faster?
// 
// this system doesnt really make sense anyway
int	adaptive_sorting(t_stacks *stacks)
{
	float	disorder;

	disorder = complexity(stacks->a);
	if (disorder < 0.2)
		simple_sorting(stacks);
	if (disorder >= 5.0)
		complex_sorting(stacks);
	else
		medium_sorting(stacks);
	return (0);
}
// <10 selection
// <20 insertion
// <50 bucket
// quick sort
