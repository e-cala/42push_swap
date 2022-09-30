#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int		value;
	int		index;
	struct s_stack	*next;
}			t_stack;

/*	stack_functions.c	*/
void	ft_push(t_stack **head, int value);
void	print_linkedlist(t_stack *head);
int	nodes_in_stack(t_stack *head);
void	min_value(t_stack **head, int index, int tmp);
int	max_index(t_stack **head);

/*	stack_utils.c		*/
t_stack	*is_last_node(t_stack *head);
t_stack	*is_before_last_node(t_stack *head);
void	push_all_save_three(t_stack **head_a, t_stack **head_b);

/*	sort.c			*/
int	sort(t_stack **head_a, t_stack **head_b);
void	sort_three(t_stack **head);
void	sort_four(t_stack **head_a, t_stack **head_b);
void	sort_five(t_stack **head_a, t_stack **head_b);

/*	sort_utils.c		*/
int	get_position(t_stack **head, int val);
int	stack_is_sorted(t_stack *head);
void	rra_pb_ra_ra(t_stack **head_a, t_stack **head_b);
void	ra_pb_rra(t_stack **head_a, t_stack **head_b);
void	pb_ra(t_stack **head_a, t_stack **head_b);

/*	radix.c			*/
void	radix_sort(t_stack **head_a, t_stack **head_b);
int	get_max_bits(t_stack **head);

/*	input_check.c	*/
int	is_duplicate(t_stack *head);
int	ft_atoi(const char *s, int *value);
int	check_input(int argc, char **argv, t_stack **head);

/*	utils.c			*/
void	err_message(void);
int	is_digit(char c);
void	ft_putstr(char *s);
void	*ft_calloc(size_t count, size_t size);
void	free_stack(t_stack **head);

/*	push.c			*/
void	push(t_stack **src, t_stack **dst);
void	pa(t_stack **src, t_stack **dst);
void	pb(t_stack **src, t_stack **dst);

/*	swap.c			*/
void	swap(t_stack **head);
void	sa(t_stack **head);
void	sb(t_stack **head);

/*	rotate.c		*/
void	rotate(t_stack **head);
void	ra(t_stack **head);
void	rb(t_stack **head);
void	rr(t_stack **head_a, t_stack **head_b);

/*	reverse_rotate.c	*/
void	reverse_rotate(t_stack **head);
void	rra(t_stack **head);
void	rrb(t_stack **head);
void	rrr(t_stack **head_a, t_stack **head_b);

#endif
