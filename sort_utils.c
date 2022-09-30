#include "push_swap.h"

int	get_position(t_stack **head_a, int val)
{
	t_stack	*tmp;
	int	i;

	tmp = *head_a;
	i = 0;
	while (tmp)
	{
		if (val < tmp->index)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

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

void	ra_pb_rra(t_stack **head_a, t_stack **head_b)
{
	ra(head_a);
	pb(head_b, head_a);
	rra(head_a);
}

void	rra_pb_ra_ra(t_stack **head_a, t_stack **head_b)
{
	rra(head_a);
	pb(head_b, head_a);
	ra(head_a);
	ra(head_a);
}

void	pb_ra(t_stack **head_a, t_stack **head_b)
{
	pb(head_b, head_a);
	ra(head_a);
}
