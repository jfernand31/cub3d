/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:33:20 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/17 14:55:17 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>


void	*ft_calloc(size_t n_elem, size_t el_size)
{
	char	*ptr;

	if (el_size != 0 && n_elem > (__SIZE_MAX__ / el_size))
		return (NULL);
	ptr = (char *)malloc(n_elem * el_size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_memset(ptr, 0, (n_elem * el_size));
	return (ptr);
}

