/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/13 12:07:17 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/24 14:55:09 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include "sorting.h"
#include "stack.h"

// get the amount of configuration flags
// this is to get the point where the stack starts for parsing it
// while not having a flag for the strategy selector is invalid
// it is allowed here so the stack can be parsed anyway
int	configuration_flag_count(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i + 1 < argc)
	{
		if (ft_strncmp(argv[i + 1], "--simple", 9) == 0)
			i++;
		else if (ft_strncmp(argv[i + 1], "--medium", 9) == 0)
			i++;
		else if (ft_strncmp(argv[i + 1], "--complex", 10) == 0)
			i++;
		else if (ft_strncmp(argv[i + 1], "--adaptive", 11) == 0)
			i++;
		else if (ft_strncmp(argv[i + 1], "--bench", 8) == 0)
			i++;
		else
			break ;
	}
	return (i);
}

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

// this should print to stderr
void	print_bench_info(t_stacks stacks)
{
	ft_fprintf(2, "[bench] disorder: %.2f%%\n",
		(double)stacks.info.init_disorder);
	ft_fprintf(2, "[bench] strategy: %s\n", stacks.info.sorting_strategy);
	ft_fprintf(2, "[bench] total_ops: %i\n", stacks.info.operations);
	ft_fprintf(2, "[bench] sa: %i, sb: %i, ss: %i, pa: %i, pb: %i\n",
		stacks.info.sa, stacks.info.sb, stacks.info.ss,
		stacks.info.pa, stacks.info.pb);
	ft_fprintf(2, "[bench] ra: %i, rb: %i, rr: %i, rra: %i, rrb: %i, rrr: %i\n",
		stacks.info.ra, stacks.info.rb, stacks.info.rr,
		stacks.info.rra, stacks.info.rrb, stacks.info.rrr);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			flag_count;

	flag_count = configuration_flag_count(argc, argv);
	stacks = setup_stacks(argc - 1 - flag_count, argv + 1 + flag_count);
	if (!stacks.a.top)
		return (print_error());
	if (ft_strncmp(argv[1], "--simple", 9) == 0)
		simple_sorting(&stacks);
	else if (ft_strncmp(argv[1], "--medium", 9) == 0)
		medium_sorting(&stacks);
	else if (ft_strncmp(argv[1], "--complex", 10) == 0)
		complex_sorting(&stacks);
	else if (ft_strncmp(argv[1], "--adaptive", 11) == 0)
		adaptive_sorting(&stacks);
	else
		adaptive_sorting(&stacks);
	if (ft_strncmp(argv[2], "--bench", 8) == 0)
		print_bench_info(stacks);
	stack_cleanup(stacks.a);
	stack_cleanup(stacks.b);
	return (0);
}
// a and b are pointers to the base of the stack
// each node in the list contains a value
// sort them by switching the nodes
