/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:30:37 by kmurray           #+#    #+#             */
/*   Updated: 2026/05/11 11:56:14 by alkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	find_min_value(t_stack *stack);
int	find_min_position(t_stack *stack);
int	find_max_position(t_stack *stack);
int	find_max_value(t_stack *stack);
int	find_insert_pos(t_stack *stack, int value);
int	find_insert_pos_rev(t_stack *stack, int value);