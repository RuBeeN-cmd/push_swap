/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:58:20 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/31 16:46:20 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = get_stack_from_args(argc, argv);
	b = NULL;
	sort_stack(&a, &b);
	ft_free_stack(b);
	ft_free_stack(a);
	return (0);
}
