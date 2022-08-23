/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:24:26 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/22 14:50:37 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vector_init(t_vector *vector)
{
	vector->len = 0;
	vector->temp_len = 0;
	vector->output = (char *)malloc(sizeof(char) * 1);
}

void	ft_vector_push_back(t_vector *vector, char c, int n)
{
	if (vector->temp_len + n >= vector->len)
	{
		vector->len += n + 100;
		vector->output = ft_reallocf(vector->output, vector->len);
	}
	while (n > 0)
	{
		vector->output[vector->temp_len] = c;
		vector->temp_len++;
		n--;
	}
}
