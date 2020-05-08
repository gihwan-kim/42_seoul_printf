/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_x_big_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 10:16:25 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/26 11:00:29 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ap_x_big_x(t_info *f_info)
{
	unsigned int	item;
	char			*item_str;
	size_t			item_len;

	item_len = 0;
	item_str = NULL;
	f_info->width = get_w_p(f_info, f_info->width, f_info->width_check, 'w');
	f_info->preci = get_w_p(f_info, f_info->preci, f_info->preci_check, 'p');
	item = va_arg(f_info->item, unsigned int);
	ft_itoa_base(item, "get item_len", item_str, &item_len);
	if (!(item_str = (char *)ft_calloc(sizeof(char), (item_len + 1))))
		return (FT_PRINTF_ERROR);
	item_len = 0;
	if (f_info->specifier == 'x')
		ft_itoa_base(item, "0123456789abcdef", item_str, &item_len);
	else
		ft_itoa_base(item, "0123456789ABCDEF", item_str, &item_len);
	f_info->output = set_output_integer(item_str, f_info);
	return (FT_FORMAT_SUCCESS);
}
