/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bis_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:43:40 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/31 10:49:15 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_get_index(int el, int *lst, int size)
{
	while (size--)
	{
		if (lst[size] == el)
			return (size);
	}
	return (-1);
}

int	ft_get_min(int *lst, int size)
{
	int	min;
	int	i;

	min = 0;
	i = 1;
	while (i < size)
	{
		if (lst[i] < lst[min])
			min = i;
		i++;
	}
	return (min);
}

void	ft_sort_lst(int *lst, int size)
{
	int	tmp;
	int	min;

	if (size)
	{
		min = ft_get_min(lst, size);
		tmp = lst[min];
		lst[min] = lst[0];
		lst[0] = tmp;
		ft_sort_lst(lst + 1, size - 1);
	}
}

int	*ft_get_sorted_lst(int *lst, int size)
{
	int	*new;
	int	i;

	new = malloc(sizeof(int) * (size));
	i = 0;
	while (i < size)
	{
		new[i] = lst[i];
		i++;
	}
	ft_sort_lst(new, size);
	return (new);
}
