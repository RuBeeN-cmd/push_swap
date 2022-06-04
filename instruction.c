/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:19:58 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/31 10:50:39 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (ft_stacksize(*stack) < 2)
		return ;
	tmp = *stack;
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!(*from))
		return ;
	tmp = *to;
	*to = *from;
	*from = (*from)->next;
	(*to)->next = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	*stack = (*stack)->next;
	tmp->next->next = NULL;
}

void	rrotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
}
