#include "push_swap.h"

/*Push:
 * Pushes the first element from stack src into stack dst.
 */
void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

/*pa:
 * Pushes the first element from stack A into stack B
 * and prints 'pa'.
 */
void	pa(t_stack **src, t_stack **dst)
{
	push(src, dst);
	ft_putstr("pa\n");
}

/*pb:
 * Pushes the first element from stack B into stack A
 * andp rints 'pb'.
 */
void	pb(t_stack **src, t_stack **dst)
{
	push(src, dst);
	ft_putstr("pb\n");
}
