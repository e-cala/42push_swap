#include "push_swap.h"

/*Swap:
 * Swaps the first 2 elements at the top of the stack,
 * does nothing if there is less than 2 elements.
 */
void	swap(t_stack **head)
{
	t_stack	*tmp;

	if (nodes_in_stack(*head) < 2)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
}

/*sa:
 * Swaps the first 2 elements at stack A
 * and prints 'sa'.
 */
void	sa(t_stack **head)
{
	swap(head);
	ft_putstr("sa\n");
}

/*sb:
 * Swaps the first 2 elements at stack B
 * and prints 'sb'.
 */
void	sb(t_stack **head)
{
	swap(head);
	ft_putstr("sb\n");
}
