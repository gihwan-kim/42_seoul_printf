/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <gihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 23:19:33 by gihkim            #+#    #+#             */
/*   Updated: 2020/03/12 23:19:33 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ap_c(format_info *f_info)
{
    unsigned char item;
    char *item_str;

    if (!(item_str = (char *)malloc(sizeof(char) * 2)))
        return (FT_FORMAT_ERROR);
    ft_bzero(item_str, 2);
    f_info->width = get_width_precision(f_info, f_info->width, f_info->width_check, 'w');
    f_info->precision = 0;
    item = (unsigned char)va_arg(f_info->item, int);
    if (item)
    {
        item_str[0] = item;
        f_info->string_to_output = set_string_to_output_type_c_s(item_str, f_info, set_new_item);
    }
    else
        f_info->string_to_output = set_string_to_output_type_c_s(item_str, f_info, set_new_item);
    return (FT_FORMAT_SUCCESS);
}
