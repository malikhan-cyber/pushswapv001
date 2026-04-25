/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                   :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:24:45 by alkhan            #+#    #+#             */
/*   Updated: 2026/04/24 14:53:49 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

int	find_ideal_pivot(t_stack *stack, t_segment segment)
{
	int	pivot[3];

	pivot[0] = get(segment.start);
	pivot[1] = get(segment.end);
	pivot[2] = get(segment.end - segment.start);
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
