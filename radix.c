#include "push_swap.h"

int	get_max_bits(t_stack **head)
{
	int		max;
	int		max_bits;
	t_stack		*tmp;

	tmp = *head;
	max = tmp->index;
	max_bits = 0;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while (max >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;
	int	i;
	int	j;
	int	size;
	int	max_bits;

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
