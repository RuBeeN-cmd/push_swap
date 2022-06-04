/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:55:31 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/31 13:12:06 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*ft_get_stacki(int *lst, int *sorted_lst, int size)
{
	t_stack	*stack;
	t_stack	*next;
	int		i;

	if (!lst)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	next = stack;
	i = 0;
	while (i < size)
	{
		next->value = ft_get_index(lst[i], sorted_lst, size);
		if (i + 1 < size)
		{
			next->next = malloc(sizeof(t_stack));
			next = next->next;
		}
		else
			next->next = NULL;
		i++;
	}
	return (stack);
}

t_stack	*ft_parse_all_args(char **input)
{
	int		*lst;
	int		*sorted_lst;
	t_stack	*stack;
	int		size;

	size = (int) ft_tablen((const void **) input);
	lst = ft_atoi_list(input, size);
	if (!lst)
		return (NULL);
	sorted_lst = ft_get_sorted_lst(lst, size);
	stack = ft_get_stacki(lst, sorted_lst, size);
	free(sorted_lst);
	free(lst);
	return (stack);
}

t_stack	*ft_parse_one_arg(char *arg)
{
	char	**input;
	t_stack	*stack;
	int		i;

	input = ft_split(arg, ' ');
	if (!input[0])
	{
		free(input);
		exit(EXIT_FAILURE);
	}
	stack = ft_parse_all_args(input);
	i = 0;
	while (input[i])
		free(input[i++]);
	free(input);
	return (stack);
}

t_stack	*get_stack_from_args(int argc, char *argv[])
{
	t_stack	*stack;

	if (argc == 1)
		exit(EXIT_FAILURE);
	else if (argc == 2)
		stack = ft_parse_one_arg(argv[1]);
	else
		stack = ft_parse_all_args(&(argv[1]));
	if (!stack)
	{
		ft_putstr_fd("Error\n", 1);
		exit(EXIT_FAILURE);
	}
	return (stack);
}
