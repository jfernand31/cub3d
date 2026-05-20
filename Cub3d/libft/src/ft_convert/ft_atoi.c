/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:11:26 by jfernand          #+#    #+#             */
/*   Updated: 2025/10/27 14:20:38 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_safe_atoi(const char *str, int *out)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((result > (LONG_MAX - (*str - '0')) / 10))
			return (1);
		result = result * 10 + (*str - '0');
		str++;
	}
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		return (1);
	*out = (int)result;
	return (0);
}
