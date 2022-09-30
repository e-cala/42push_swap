#include "push_swap.h"

t_stack	*is_last_node(t_stack *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}

t_stack	*is_before_last_node(t_stack *head)
{
	while (head && head->next && head->next->next)
		head = head->next;
	return (head);
}

void	push_all_save_three(t_stack **head_a, t_stack **head_b)
{
	int	i;
	int	pushed;
	int	size_a;

	i = 0;
	pushed = 0;
	size_a = nodes_in_stack(*head_a);
	while (i < size_a - 3)
	{
		if ((*head_a)->value <= size_a / 2)
		{
			pb(head_a, head_b);
			pushed++;
		}
		else
			ra(head_a);
		i++;
	}
	while (size_a - pushed > 3)
	{
		pb(head_a, head_b);
		pushed++;
	}
}
