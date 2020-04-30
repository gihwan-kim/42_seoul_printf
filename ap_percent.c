/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:22:51 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/25 13:03:11 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ap_percent(format_info *f_info)
{
    // unsigned char item;
    char *item_str;

    if (!(item_str = (char *)malloc(sizeof(char) * 2)))
        return (FT_FORMAT_ERROR);
    item_str[0] = '%';
	item_str[1] = '\0';
    f_info->width = get_width_precision(f_info, f_info->width, f_info->width_check, 'w');
    f_info->precision = 0;
	f_info->precision_check = FALSE;
    f_info->string_to_output = set_string_to_output_type_c_s(item_str, f_info, set_new_item);
    return (FT_FORMAT_SUCCESS);
}