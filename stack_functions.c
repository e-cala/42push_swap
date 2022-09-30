/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:58:54 by ecabanas          #+#    #+#             */
/*   Updated: 2022/09/20 16:07:08 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*ft_push:
 * Creates a new element and pushes it on top of the stack
 */
void	ft_push(t_stack **head, int value)
{
	t_stack	*new;

	//new = malloc (sizeof * new);
	new = ft_calloc(1, sizeof * new);
	if (!new)
		return ;
	new->value = value;
	if (!head)
		new->next = NULL;
	else
	{
		new->next = *head;
	}
	*head = new;
}

/*print_linkedlist:
 * Runs through the whole list and prints each value
 */
void	print_linkedlist(t_stack *head)
{
	while (head != NULL)
	{
		printf("%i ", head->value);
		head = head->next;
	}
}

/*nodes_in_stack:
 * Counts the number of nodes in the linked list
 * and returns the value
 */
int	nodes_in_stack(t_stack *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

/*min_value:
 * Runs through the whole list and assigns an index to
 * the smallest value in the list which does not yet
 * have an index assigned.
 */
void	min_value(t_stack **head, int index, int tmp)
{
	t_stack	*new;

	new = *head;
	while (new)
	{
		if (tmp > new->value && new->index == 0)
			tmp = new->value;
		new = new->next;
	}
	new = *head;
	while (new)
	{
		if (tmp == new->value)
			new->index = index;
		new = new->next;
	}
}

/*max_index:
 * Searches for the number with highest index and
 * returns it's current position in the stack.
 */
int	max_index(t_stack **head)
{
	int	tmp;
	int	i;
	t_stack *new;

	i = 1;
	new = *head;
	tmp = new->index;
	while (new)
	{
		if (tmp < new->index)
			tmp = new->index;
		new = new->next;
	}
	new = *head;
	while (tmp != new->index)
	{
		i++;
		new = new->next;
	}
	return (i);
}
