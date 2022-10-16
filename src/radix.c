/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:13:44 by ecabanas          #+#    #+#             */
/*   Updated: 2022/10/16 20:51:28 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*get_max_bits:
 * Locates the value with highest index (most digits)
 * Counts the number of >> it takes for the highest index to become 0.
 * Returns the number of digits the number has.
 * i.e.
 * 7 / 2^0 ->7
 * 7 / 2^1 ->3
 * 7 / 2^2 ->1
 * 7 / 2^3 ->0 (7 contains 3 bits and is 111)
 */
int	get_max_bits(t_stack **head)
{
	int		max_idx;
	int		max_bits;
	t_stack	*tmp;

	tmp = *head;
	max_idx = tmp->index;
	max_bits = 0;
	while (tmp)
	{
		if (tmp->index > max_idx)
			max_idx = tmp->index;
		tmp = tmp->next;
	}
	while (max_idx >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

/*radix_sort:
 * Goes through the list and compares each positional bit.
 * 1. Iterate for (1) for every positional bit and (2) every number in stack A.
 * 2. If bit == 1 we keep it in stack A else we push it to stack B.
 * 3. Push back all numbers to stack A and increment the position.
 */
void	radix_sort(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	tmp = *head_a;
	i = 0;
	size = nodes_in_stack(*head_a);
	max_bits = get_max_bits(head_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			tmp = *head_a;
			if (((tmp->index >> i) & 1) == 1)
				ra(head_a);
			else
				pb(head_a, head_b);
		}
		while (nodes_in_stack(*head_b) != 0)
			pa(head_b, head_a);
		i++;
	}
}
