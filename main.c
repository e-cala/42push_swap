/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:58:01 by ecabanas          #+#    #+#             */
/*   Updated: 2022/09/20 15:08:09 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*main:
 * Checks if the input is correct, in wihch case it initializes stacks a and b,
 * assigns each value indexes and sorts the stacks. When sorting is done, frees
 * the stacks and exits.
 */
int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!check_input(argc, argv, &stack_a))
	{
		err_message();
		return (0);
	}
	//print_linkedlist(stack_a);
	sort(&stack_a, &stack_b);
	/*printf("\n2.Stack A: ");
	print_linkedlist(stack_a);
	printf("\n");
	printf("2.Stack B: ");
	printf("\n");*/
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
