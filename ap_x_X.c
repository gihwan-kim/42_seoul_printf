/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_x_X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <gihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:35:38 by gihkim                #+#    #+#             */
/*   Updated: 2020/03/12 12:35:38 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int                ap_x_X(format_info *f_info)
{
    unsigned int item;
    char *item_str;
    size_t item_len;

    item_len = 0;
    item_str = NULL;
    // if (f_info -> width_check == TRUE)
    // {
    //     if (f_info -> width < 0) // number
    //         f_info -> width = va_arg(f_info -> item, int);
    // }
    // else
    //     f_info -> width = 0;
    // f_info -> precision = get_precision(f_info);
    f_info->width = get_width_precision(f_info, f_info->width, f_info->width_check, 'w');
    f_info->precision = get_width_precision(f_info, f_info->precision, f_info->precision_check, 'p');
    item = va_arg(f_info -> item, unsigned int);
    ft_itoa_base(item, "get item_len", item_str, &item_len);
    if (!(item_str = (char*)ft_calloc(sizeof(char), (item_len + 1))))
        return (FT_PRINTF_ERROR);
    item_len = 0;
    if (f_info -> specifier == 'x')
        ft_itoa_base(item, "0123456789abcdef", item_str, &item_len);
    else
        ft_itoa_base(item, "0123456789ABCDEF", item_str, &item_len);
    f_info -> string_to_output = set_string_to_output(item_str, f_info);
    return (FT_FORMAT_SUCCESS);
}