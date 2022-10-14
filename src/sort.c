/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:15:56 by ecabanas          #+#    #+#             */
/*   Updated: 2022/10/02 11:13:00 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	sort_three(t_stack **head)
{
	if (max_index(head) == 1)
		ra(head);
	else if (max_index(head) == 2)
		rra(head);
	if ((*head)->value > (*head)->next->value)
		sa(head);
}

void	sort_four(t_stack **head_a, t_stack **head_b)
{
	min_index(head_a, head_b, 1);
	sort_three(head_a);
	pa(head_b, head_a);
}

void	sort_five(t_stack **head_a, t_stack **head_b)
{
	
	min_index(head_a, head_b, 1);
	min_index(head_a, head_b, 2);
	sort_three(head_a);
	pa(head_b, head_a);
	pa(head_b, head_a);
}
