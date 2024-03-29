/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:11:23 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/26 11:11:52 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoa_base(unsigned long nbr, char *base, char *a, size_t *idx)
{
	size_t base_no;

	base_no = ft_strlen(base);
	if (nbr < base_no)
	{
		if (a)
		{
			a[*idx] = base[nbr % base_no];
			(*idx)++;
		}
		else
			(*idx)++;
	}
	else
	{
		ft_itoa_base(nbr / base_no, base, a, idx);
		if (a)
		{
			a[*idx] = base[nbr % base_no];
			(*idx)++;
		}
		else
			(*idx)++;
	}
}
