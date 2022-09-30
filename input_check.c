/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:57:39 by ecabanas          #+#    #+#             */
/*   Updated: 2022/09/15 12:10:28 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*is_duplicate:
 * Checks the entire linked list for duplicate numbers
 * Returns the number of duplicated values
 */
int	is_duplicate(t_stack *head)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	while (head->next != NULL)
	{
		ptr = head->next;
		while (ptr != NULL)
		{
			if (head->value == ptr->value)
			{
				i++;
				break ;
			}
			ptr = ptr->next;
		}
		head = head->next;
	}
	return (i);
}

/*ft_atoi:
 * Checks if chars are numbers in which case it modifies the value
 * passed by reference to int.
 * Returns 1 if the parameter is a number and 0 in case of error.
 */
int	ft_atoi(const char *s, int *value)
{
	int	num;
	int	i;
	int	sign;

	num = 0;
	i = 0;
	sign = 1;
	if (!s && (s[i] != '-' || is_digit(s[i])))
		return (0);
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (!is_digit(s[i]))
			return (0);
		num = (num * 10) + s[i] - '0';
		i++;
	}
	if ((sign * num) > INT_MAX || (sign * num) <= INT_MIN)
		return (0);
	*value = sign * num;
	return (1);
}

/*check_input:
 * 1. Checks if all parameters are numbers, 2. pushes numbers
 * into the stack and 3. checks if the list has no duplicates
 * Returns 0 if there is any error or 1 if parameters are ok.
 */
int	check_input(int argc, char **argv, t_stack **head)
{
	int	value;
	int	i;
	int	tmp;

	value = 0;
	i = 1;
	while (i < argc)
	{
		if (!ft_atoi(argv[argc - i], &value))
			return (0);
		ft_push(head, value);
		i++;
	}
	if (is_duplicate(*head))
		return (0);
	i = 0;
	while (i++ < argc)
	{
		tmp = INT_MAX;
		min_value(head, i, tmp);
	}
	return (1);
}
