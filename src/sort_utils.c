/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:16:11 by ecabanas          #+#    #+#             */
/*   Updated: 2022/10/02 11:48:56 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

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

void	min_index(t_stack **head_a, t_stack **head_b, int i)
{
	int	j;
	int	size_a;
	t_stack	*tmp;

	j = 0;
	size_a = nodes_in_stack(*head_a);
	tmp = *head_a;
	while(tmp->index != i)
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
