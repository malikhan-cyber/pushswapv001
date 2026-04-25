/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   parsing.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/20 14:12:09 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/24 16:36:23 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "stack.h"

static bool	is_integer(char *string)
{
	int	i;

	i = 0;
	if (string[i] == '-')
		i++;
	while (string[i])
	{
		if (!((string[i] >= '0') && (string[i] <= '9')))
			return (false);
		i++;
	}
	return (true);
}

// parse the stack
// the first argument is the top of the stack
// the last will be the bottom
// so it keeps inserting at the end 
t_stack	parse_stack_a(int argc, char **argv)
{
	t_stack				stack;
	int					i;
	t_list_contents		*value;

	i = 0;
	stack = new_stack('a');
	while (i < argc)
	{
		if (!is_integer(argv[i]))
			return (stack_cleanup(stack));
		value = malloc(sizeof(t_list_contents));
		if (!value)
			return (stack_cleanup(stack));
		*value = new_contents(ft_atoi(argv[i]), i);
		if (ft_lstadd_ell_back(&stack.top, value) == -1)
			return (stack_cleanup(stack));
		i++;
	}
	stack.bottom = ft_lstlast(stack.top);
	return (stack);
}
