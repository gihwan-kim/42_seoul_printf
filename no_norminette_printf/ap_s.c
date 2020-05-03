/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <gihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 13:16:46 by gihkim            #+#    #+#             */
/*   Updated: 2020/03/13 13:16:46 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *set_new_item_type_s(char *item, format_info *f_info)
{
    size_t item_len;
    char *new_item;

    item_len = ft_strlen(item);
    new_item = item;
    if (f_info -> precision_check && (size_t)(f_info -> precision) < item_len)
    {
        new_item = (char*)ft_calloc(sizeof(char), f_info -> precision + 1);
        // ft_bzero(new_item, f_info -> precision + 1); //calloc 안에 bzero 함수 있음
        ft_memcpy(new_item, item, f_info -> precision);
        free(item);
    }
    return (new_item);
}

// static char *set_string_to_output_type_s(char *item, format_info *f_info)
// {
//     char *new_item;
//     char *output_str;
//     size_t n_item_len;

//     new_item = set_new_item_type_s(item, f_info);
//     n_item_len = ft_strlen(new_item);
//     if ((size_t)(f_info -> width) > ft_strlen(new_item))// 남은 공간을  ' ' 으로 채운다.
//     {
//         output_str = (char*)ft_calloc(sizeof(char), f_info -> width + 1);
//         ft_memset(output_str, ' ', f_info -> width);
//         if (f_info -> flags_box[0] == '1')      // - : O | 왼쪽 출력
//             ft_memcpy(output_str, new_item, n_item_len);
//         else                                    //  - : X | 오른쪽 출력
//             ft_memcpy(output_str + f_info -> width - n_item_len, new_item, n_item_len);
//     }
//     else                                        // 아이템만 출력
//         return (new_item);
//     free(new_item);
//     free(item);
//     return (output_str);
// }

int         ap_s(format_info *f_info)
{
    char    *item;
    char    *temp;

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
    temp = (char*)va_arg(f_info -> item, char*);
    if(!(item = (char*)ft_calloc(sizeof(char), (ft_strlen(temp) + 1))))
        return (FT_FORMAT_ERROR);
    if (!temp)
	{
		if (!(item = (char *)ft_calloc(sizeof(char), 7)))
			return (FT_FORMAT_ERROR);
		ft_strlcpy(item, "(null)", 7);
	}
	else
	{
		if (!(item = (char *)ft_calloc(sizeof(char), (ft_strlen(temp) + 1))))
			return (FT_FORMAT_ERROR);
	}
    if (temp)
		ft_strlcpy(item, temp, ft_strlen(temp) + 1);
    f_info -> string_to_output = set_string_to_output_type_c_s(item, f_info, set_new_item_type_s);
    return (FT_FORMAT_SUCCESS);
}