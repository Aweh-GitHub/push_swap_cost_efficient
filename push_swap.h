/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:02:43 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/02 09:16:40 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0

# include <sys/types.h>
# include <stddef.h>

typedef struct s_stack
{
	char			*name;
	size_t			size;
	struct s_elem	*top;
	struct s_elem	*bot;
}	t_stack;

typedef struct s_elem
{
	int				value;
	int				rank;
	struct s_elem	*up;
	struct s_elem	*down;
}	t_elem;

char	**ft_split(char const *s, char c);
int		ft_atoi(char const *nptr);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *str);
int		ft_isnb(char *s);
size_t	ft_splitlen(char const **split);
t_elem	*ft_strtoelems(char **values);

t_stack	*init_args_to_stack(char *stack_name, \
	size_t argc, char **argv);

void	sort_radix(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four_five(t_stack *a, t_stack *b);
void	handle_sorting(t_stack *a, t_stack *b);

t_elem	*t_elem__new(int value, int rank, t_elem *next, t_elem *prev);
void	t_elem__add_last(t_elem *elem, t_elem *to_add);
t_elem	*t_elem__unlink(t_elem *elem);
t_elem	*t_elem__last(t_elem *start);

t_stack	*t_stack__new(char *name, t_elem *head, t_elem *tail);
t_stack	*t_stack__addtail(t_stack *stack, t_elem *elem);
t_stack	*t_stack__addhead(t_stack *stack, t_elem *elem);
void	t_stack__free_all(t_stack *stack);

void	push_x(t_stack *dst, t_stack *src);
void	rotate_x(t_stack *stack, int print);
void	rotate_rotate(t_stack *a, t_stack *b);
void	rev_rotate_x(t_stack *stack, int print);
void	rev_rotate_rotate(t_stack *a, t_stack *b);
void	swap_x(t_stack *stack, int print);
void	swap_swap(t_stack *a, t_stack *b);

#endif