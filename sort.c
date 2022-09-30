#include "push_swap.h"

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
	push_all_save_three(head_a, head_b);
	sort_three(head_a);
	if (get_position(head_a, (*head_b)->index) == 0)
		pb(head_b, head_a);
	else if (get_position(head_a, (*head_b)->index) == 1)
		ra_pb_rra(head_a, head_b);
	else if (get_position(head_a, (*head_b)->index) == 2)
		rra_pb_ra_ra(head_a, head_b);
	else if (get_position(head_a, (*head_b)->index) == 3)
		pb_ra(head_a, head_b);
}

void	sort_five(t_stack **head_a, t_stack **head_b)
{
	sort_four(head_a, head_b);
	if (get_position(head_a, (*head_b)->index) == 0)
		pb(head_b, head_a);
	else if (get_position(head_a, (*head_b)->index) == 1)
		ra_pb_rra(head_a, head_b);
	else if (get_position(head_a, (*head_b)->index) == 2)
	{
		ra(head_a);
		ra_pb_rra(head_a, head_b);
		rra(head_a);
	}
	else if (get_position(head_a, (*head_b)->index) == 3)
		rra_pb_ra_ra(head_a, head_b);
	else if (get_position(head_a, (*head_b)->index) == 4)
		pb_ra(head_a, head_b);
}
