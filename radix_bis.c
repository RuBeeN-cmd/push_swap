/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:47:30 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/01 14:32:49 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_log_bin(int nb)
{
	int	i;

	i = 1;
	while (nb >> i)
		i++;
	return (i);
}

int	ft_do_i_swap(t_stack **a)
{
	return (((*a)->value > (*a)->next->value
			&& (*a)->value < (*a)->next->next->value
			&& (*a)->next->value < (*a)->next->next->value)
		|| ((*a)->value > (*a)->next->value
			&& (*a)->value > (*a)->next->next->value
			&& (*a)->next->value > (*a)->next->next->value)
		|| ((*a)->value < (*a)->next->value
			&& (*a)->value < (*a)->next->next->value
			&& (*a)->next->value > (*a)->next->next->value));
}

int	ft_is_stack_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->value != i)
			return (0);
		a = a->next;
		i++;
	}
	return (1);
}

void	rotate_or_push(t_stack **a, t_stack **b, int size, int i)
{
	while (size--)
	{
		if ((*a)->value >> i & 1)
		{
			write(1, "ra\n", 3);
			rotate(a);
		}
		else
		{
			write(1, "pb\n", 3);
			push(a, b);
		}
	}
}
