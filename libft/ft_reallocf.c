/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:48:36 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/22 14:49:16 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_reallocf(void *ptr, size_t size)
{
	void	*ptr_cpy;

	if (ptr == NULL)
		return (NULL);
	else if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	ptr_cpy = (void *)malloc(size);
	if (ptr_cpy == NULL)
		return (NULL);
	ft_memmove(ptr_cpy, ptr, size);
	free(ptr);
	return (ptr_cpy);
}
