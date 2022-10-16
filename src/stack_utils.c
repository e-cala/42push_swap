/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:17:26 by ecabanas          #+#    #+#             */
/*   Updated: 2022/10/16 17:56:05 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*is_last_node:
 * Returns the last node in a linked list.
 */
t_stack	*is_last_node(t_stack *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}

/* is_before_last_node:
 * Returns the second to last node in a linked list.
 */
t_stack	*is_before_last_node(t_stack *head)
{
	while (head && head->next && head->next->next)
		head = head->next;
	return (head);
}
