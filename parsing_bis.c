/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:14:01 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/01 14:30:11 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_check_overflow(char *str, int nb, int is_pos)
{
	if (is_pos)
	{
		if (nb > nb * 10 + (*str - '0') - 1)
			return (1);
	}
	else
	{
		if (nb > nb * 10 + (*str - '0') - 2)
			return (1);
	}
	return (0);
}

int	ft_is_overflow(const char *nptr)
{
	int		nb;
	char	*str;
	int		coef;

	nb = 0;
	str = (char *) nptr;
	while (*str == ' ' || (*str <= '\r' && *str >= '\t'))
		str++;
	coef = 1;
	if (*str == '-')
	{
		coef = 0;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (nb || *str != '0')
			if (ft_check_overflow(str, nb, coef))
				return (1);
		nb *= 10;
		nb += *str++ - '0';
	}
	return (0);
}

int	*ft_atoi_list(char **lst, int size)
{
	int		*new;
	int		nb;
	int		i;

	new = NULL;
	if (lst)
	{
		new = malloc(sizeof(int *) * size);
		i = 0;
		while (lst[i])
		{
			nb = ft_atoi(lst[i]);
			if (ft_check_arg(lst[i])
				|| ft_is_in_list(new, nb, i) || ft_is_overflow(lst[i]))
			{
				free(new);
				return (NULL);
			}
			new[i] = nb;
			i++;
		}
	}
	return (new);
}

int	ft_check_arg(char *str)
{
	while (*str)
	{
		if (*str != '-' && *str != '+' && !(*str <= '\r' && *str >= '\t')
			&& *str != ' ' && !(*str <= '9' && *str >= '0'))
			return (1);
		str++;
	}
	return (0);
}

int	ft_is_in_list(int *lst, int nb, int size_max)
{
	while (size_max--)
		if (lst[size_max] == nb)
			return (1);
	return (0);
}
