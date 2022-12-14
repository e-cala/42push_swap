/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:16:11 by ecabanas          #+#    #+#             */
/*   Updated: 2022/10/16 17:47:26 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/*stack_is_sorted:
 * Checks if the stack is sorted in ascending order.
 * Returns 1 if stack is sorted and 0 if it is not sorted
 */
int	stack_is_sorted(t_stack *head)
{
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

/*min_index:
 * Iterates through the linked list looking for the node with lowest index
 */
void	min_index(t_stack **head_a, t_stack **head_b, int i)
{
	int		j;
	int		size_a;
	t_stack	*tmp;

	j = 0;
	size_a = nodes_in_stack(*head_a);
	tmp = *head_a;
	while (tmp->index != i)
	{
		tmp = tmp->next;
		j++;
	}
	while ((*head_a)->index != i)
	{		
		if (j <= size_a / 2)
			ra(head_a);
		else if (j > size_a / 2)
			rra(head_a);
	}
	pb(head_a, head_b);
}
