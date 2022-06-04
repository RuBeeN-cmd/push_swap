/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:02:41 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/01 14:34:57 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size_a;
	int	size;
	int	n;
	int	i;

	size_a = ft_stacksize(*a);
	n = ft_log_bin(size_a - 1);
	i = 0;
	while (i < n)
	{
		rotate_or_push(a, b, size_a, i);
		i++;
		size = ft_stacksize(*b);
		while (size--)
		{
			write(1, "pa\n", 3);
			push(b, a);
		}
	}
}

void	sort_three(t_stack **a)
{
	if (ft_do_i_swap(a))
	{
		write(1, "sa\n", 3);
		swap(a);
	}
	if ((*a)->value < (*a)->next->value
		&& (*a)->value > (*a)->next->next->value
		&& (*a)->next->value > (*a)->next->next->value)
	{
		write(1, "rra\n", 4);
		rrotate(a);
	}
	else if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value
		&& (*a)->next->value < (*a)->next->next->value)
	{
		write(1, "ra\n", 3);
		rotate(a);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (ft_stacksize(*b) != 2)
	{
		if ((*a)->value == 1 || (*a)->value == 0)
		{
			write(1, "pb\n", 3);
			push(a, b);
		}
		else
		{
			write(1, "ra\n", 3);
			rotate(a);
		}
	}
	sort_three(a);
	if ((*b)->value == 0)
	{
		write(1, "sb\n", 3);
		swap(b);
	}
	write(1, "pa\npa\n", 6);
	push(b, a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	while (ft_stacksize(*b) != 1)
	{
		if ((*a)->value == 0)
		{
			write(1, "pb\n", 3);
			push(a, b);
		}
		else
		{
			write(1, "ra\n", 3);
			rotate(a);
		}
	}
	sort_three(a);
	if ((*b)->value == 0)
	{
		write(1, "sb\n", 3);
		swap(b);
	}
	write(1, "pa\npa\n", 6);
	push(b, a);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (ft_is_stack_sorted(*a))
		return ;
	else if (ft_stacksize(*a) == 2)
	{
		write(1, "sa\n", 3);
		swap(a);
	}
	else if (ft_stacksize(*a) == 3)
		sort_three(a);
	else if (ft_stacksize(*a) == 4)
		sort_four(a, b);
	else if (ft_stacksize(*a) == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}
