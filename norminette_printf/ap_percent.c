/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:22:51 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/26 10:57:40 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ap_percent(t_info *f_info)
{
	char *item_str;

	if (!(item_str = (char *)malloc(sizeof(char) * 2)))
		return (FT_FORMAT_ERROR);
	item_str[0] = '%';
	item_str[1] = '\0';
	f_info->width = get_w_p(f_info, f_info->width, f_info->width_check, 'w');
	f_info->preci = 0;
	f_info->preci_check = FALSE;
	f_info->output = set_output_c_s(item_str, f_info, set_new_item);
	return (FT_FORMAT_SUCCESS);
}
