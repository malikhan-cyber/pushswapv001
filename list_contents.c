/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   list_contents.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/22 17:20:13 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/22 17:28:33 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list_contents	new_contents(int value, int index)
{
	t_list_contents	contents;

	contents.value = value;
	contents.index = index;
	return (contents);
}
