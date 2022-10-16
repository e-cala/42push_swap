/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:15:56 by ecabanas          #+#    #+#             */
/*   Updated: 2022/10/16 17:55:46 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*sort:
 * Checks how many values there are in the linked list and calls the appriate
 * sorting function. 
 * Returns 1 if the stack is sorted or 0 at the end of the function once the
 * list is sorted
 */
int	sort(t_stack **head_a, t_stack **head_b)
{
	if (stack_is_sorted(*head_a))
		return (1);
	else
	{
		if (nodes_in_stack(*head_a) == 2)
			sa(head_a);
		else if (nodes_in_stack(*head_a) == 3)
			sort_three(head_a);
		else if (nodes_in_stack(*head_a) == 4)
			sort_four(head_a, head_b);
		else if (nodes_in_stack(*head_a) == 5)
			sort_five(head_a, head_b);
		else if (nodes_in_stack(*head_a) > 5)
			radix_sort(head_a, head_b);
	}
	return (0);
}

/*sort_three:
 */
void	sort_three(t_stack **head)
{
	if (max_index(head) == 1)
		ra(head);
	else if (max_index(head) == 2)
		rra(head);
	if ((*head)->value > (*head)->next->value)
		sa(head);
}

/*sort_four:
 * 1. Sends the value with the lowest index to stack B.
 * 2. Sorts stack A containing three values.
 * 3. Pushes the least minimum index value back to stack A.
 */
void	sort_four(t_stack **head_a, t_stack **head_b)
{
	min_index(head_a, head_b, 1);
	sort_three(head_a);
	pa(head_b, head_a);
}

/*sort_five:
 * 1. Sends the 2 values with the lowest index to stack B 
 * (in Ascending order).
 * 2. Sorts Stack A containing three values.
 * 3. Pushes the least minimum index value back to Stack A.
 */
void	sort_five(t_stack **head_a, t_stack **head_b)
{	
	min_index(head_a, head_b, 1);
	min_index(head_a, head_b, 2);
	sort_three(head_a);
	pa(head_b, head_a);
	pa(head_b, head_a);
}
