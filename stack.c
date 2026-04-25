/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   stack.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/14 12:55:34 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/24 14:58:47 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "sorting.h"
#include "parsing.h"
#include "stack.h"

// adds an ellement to the back of the list
// returns -1 on error
int	ft_lstadd_ell_back(t_list **lst, void *new)
{
	t_list	*new_element;

	new_element = ft_lstnew(new);
	if (!new_element)
		return (-1);
	ft_lstadd_back(lst, new_element);
	return (0);
}

// returns a new stack because this is usually used for parsing erros
// (this doesnt allocate anything)
t_stack	stack_cleanup(t_stack stack)
{
	ft_lstclear(&stack.top, free);
	return (new_stack(stack.name));
}

t_stack	new_stack(char name)
{
	t_stack	stack;

	stack.name = name;
	stack.top = NULL;
	stack.bottom = NULL;
	return (stack);
}

t_sorting_info	new_info(t_stack stack_a)
{
	t_sorting_info	info;

	info.init_disorder = complexity(stack_a);
	info.sorting_strategy = NULL;
	info.operations = 0;
	info.sa = 0;
	info.sb = 0;
	info.ss = 0;
	info.pa = 0;
	info.pb = 0;
	info.ra = 0;
	info.rb = 0;
	info.rr = 0;
	info.rra = 0;
	info.rrb = 0;
	info.rrr = 0;
	return (info);
}

t_stacks	setup_stacks(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.a = parse_stack_a(argc, argv);
	stacks.b = new_stack('b');
	stacks.info = new_info(stacks.a);
	return (stacks);
}
