/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:56:38 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/01 14:33:22 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include"libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
}				t_stack;

// parsing.c
t_stack	*ft_get_stacki(int *lst, int *sorted_lst, int size);
t_stack	*ft_parse_all_args(char **input);
t_stack	*ft_parse_one_arg(char *arg);
t_stack	*get_stack_from_args(int argc, char *argv[]);

// parsing_bis.c
int		ft_is_overflow(const char *nptr);
int		ft_check_overflow(char *str, int nb, int is_pos);
int		*ft_atoi_list(char **lst, int size);
int		ft_check_arg(char *str);
int		ft_is_in_list(int *lst, int nb, int size_max);

// parsing_bis_bis.c
int		ft_get_index(int el, int *lst, int size);
int		ft_get_min(int *lst, int size);
void	ft_sort_lst(int *lst, int size);
int		*ft_get_sorted_lst(int *lst, int size);

// instruction.c
void	ft_free_stack(t_stack *stack);
void	swap(t_stack **stack);
void	push(t_stack **from, t_stack **to);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);

// stack_utils.c
void	ft_free_stack(t_stack *stack);
int		ft_stacksize(t_stack *stack);

// radix.c
void	radix_sort(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);

// radix_bis.c
int		ft_log_bin(int nb);
int		ft_is_stack_sorted(t_stack *a);
int		ft_do_i_swap(t_stack **a);
void	rotate_or_push(t_stack **a, t_stack **b, int size, int i);

#endif
