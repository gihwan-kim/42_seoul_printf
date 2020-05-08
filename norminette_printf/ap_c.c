/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 23:19:33 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/26 11:08:52 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ap_c(t_info *f_info)
{
	unsigned char	item;
	char			*item_str;

	if (!(item_str = (char *)malloc(sizeof(char) * 2)))
		return (FT_FORMAT_ERROR);
	ft_bzero(item_str, 2);
	f_info->width = get_w_p(f_info, f_info->width, f_info->width_check, 'w');
	f_info->preci = 0;
	item = (unsigned char)va_arg(f_info->item, int);
	if (item)
	{
		item_str[0] = item;
		f_info->output = set_output_c_s(item_str, f_info, set_new_item);
	}
	else
		f_info->output = set_output_c_s(item_str, f_info, set_new_item);
	return (FT_FORMAT_SUCCESS);
}
