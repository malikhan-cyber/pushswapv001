/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   complex_sorting.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/14 14:43:05 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/24 17:46:38 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

// returns the amount the stack was rotated by
// sorts in stack a
// `partition_start` is the starting index of the partition that is being sorted
// `partition_end` is the starting index of the partition that is being sorted
// (non inclusive)
// todo: find pivot for this partition
// todo: sort partition on pivot this should set rotation
int	quick_sort(t_stacks *stacks, int partition_start, int partition_end)
{
	int	rotation;
	int	pivot_index;
	int	stack_len;

	stack_len = ft_lstsize(stacks->a.top);
	if (partition_start > stack_len)
		partition_start -= stack_len;
	if (partition_end > stack_len)
		partition_start -= stack_len;
	rotation = 0;
	pivot_index = 0;
	if (partition_start != partition_end)
	{
		rotation += quick_sort(
				stacks, pivot_index + 1, partition_end + rotation);
		rotation = quick_sort(stacks,
				partition_start + rotation, pivot_index + rotation);
	}
	return (rotation);
}

int	complex_sorting(t_stacks *stacks)
{
	opp_swap(stacks, A);
	return (0);
}
