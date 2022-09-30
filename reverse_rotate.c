#include "push_swap.h"

/*reverse_rotate:
 */
void	reverse_rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tmp = *head;
	tail = is_last_node(*head);
	before_tail = is_before_last_node(*head);
	*head = tail;
	(*head)->next = tmp;
	before_tail->next = NULL;
}

/*rra:
 * Rotates *DOWN* stack A
 * prints the move.
 */
void	rra(t_stack **head)
{
	reverse_rotate(head);
	ft_putstr("rra\n");
}

/*rrb:
 * Rotates *DOWN* stack B
 * prints the move
 */
void	rrb(t_stack **head)
{
	reverse_rotate(head);
	ft_putstr("rrb\n");
}

/*rrr:
 * Rotates *DOWN* Stack A and Stack B
 * prints the move.
 */
void	rrr(t_stack **head_a, t_stack **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	ft_putstr("rrr\n");
}
