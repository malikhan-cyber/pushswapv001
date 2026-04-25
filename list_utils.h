/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   list_utils.h                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/24 17:59:19 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/24 18:00:04 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H

// might return null if the index is invalid
t_list_contents	*get(t_stack *stack, int n);

// might return null if the index is invalid
// this does not return back to the start of the list if it needs to
t_list_contents	*get_n(t_list *list, int n);

// get the contents of list
t_list_contents	*get_content(t_list *list);
#endif
