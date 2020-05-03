/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <gihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:50:23 by gihkim            #+#    #+#             */
/*   Updated: 2020/03/13 16:50:23 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *set_new_item_p(char *item, format_info *f_info)
{
    size_t item_len;
    char *new_item;

    item_len = ft_strlen(item) - 2; // 0x 를 제외한 item 길이
    new_item = item;

    if ((size_t)(f_info->precision) > item_len)
    {
        new_item = (char *)ft_calloc(sizeof(char), f_info->precision + 3);
        ft_memcpy(new_item, item, 2);
        ft_memset(new_item + 2, '0', f_info->precision - item_len);
        ft_memcpy(new_item + 2 + f_info->precision - item_len, item + 2, item_len);
        free(item);
    }
    return (new_item);
}

int ap_p(format_info *f_info)
{
    unsigned long item;
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
    item = va_arg(f_info->item, unsigned long);
    // if (!item)
    // {
    //     f_info->string_to_output = 0;
    //     return (FT_FORMAT_SUCCESS);
    // }
    ft_itoa_base(item, "get item_len", item_str, &item_len);
    if (!(item_str = (char *)ft_calloc(sizeof(char), (item_len + 3))))
        return (FT_PRINTF_ERROR);
    item_len = 0;
    ft_itoa_base(item, "0123456789abcdef", item_str + 2, &item_len);
    item_str[0] = '0';
    item_str[1] = 'x';
    // if (item)
    if ((ft_strlen(item_str) == 3) && (item_str[2] == '0') && !(f_info->precision) && (f_info->precision_check))
        item_str[2] = '\0';
    f_info->string_to_output = set_string_to_output_type_p(item_str, f_info, set_new_item_p);
    // else
    // f_info->string_to_output = item_str;
    return (FT_FORMAT_SUCCESS);
}