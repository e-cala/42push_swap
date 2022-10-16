/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:59:09 by ecabanas          #+#    #+#             */
/*   Updated: 2022/10/16 17:56:42 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/*err_message:
 */
void	err_message(void)
{
	write(2, "Error\n", 6);
}

/*is_digit:
 */
int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*ft_putstr
 */
void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

/*free_stack:
 */
void	free_stack(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !(*head))
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
}

/*ft_calloc
 */
void	*ft_calloc(size_t count, size_t size)
{
	void			*r;
	unsigned char	*p;

	r = malloc(count * size);
	p = (unsigned char *)r;
	while (size--)
	{
		*p = '\0';
		p++;
	}
	return (r);
}
