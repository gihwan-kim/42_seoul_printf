/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <gihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:21:46 by gihkim            #+#    #+#             */
/*   Updated: 2020/03/11 11:21:46 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    check_length(const char ***format, format_info *f_info)
{
    char *length_options;
    char length_double_check[3];

    length_options = "hljzt";
    ft_memset(length_double_check, '0', 2);
    length_double_check[2] = '\0';
    while (1)
    {
        if (!ft_strchr(length_options, *(**format)))
            break ;
        if (***format == 'h')
        {
            f_info -> length_box[0] += 1;
            if (*(**format + 1) == 'h')
                length_double_check[0] += 1;
        }
        else if (***format == 'l')
        {
            f_info -> length_box[1] += 1;
            if (*(**format + 1) == 'l')
                length_double_check[1] += 1;
        }
        else if (***format == 'j')
            f_info -> length_box[2] += 1;
        else if (***format == 'z')
            f_info -> length_box[3] += 1;
        else
            f_info -> length_box[4] += 1;
        if (ft_strchr(f_info -> length_box + 2, '2'))// 개별 구역 에러 (jzt)
            return (FT_FORMAT_ERROR);
        else if (f_info -> length_box[0] == '3' || f_info -> length_box[1] == '3')
            return (FT_FORMAT_ERROR);
        else if ((f_info -> length_box[0] == '2' && length_double_check[0] != '2')
            || (f_info -> length_box[1] == '2' && length_double_check[1] != '2'))
            return (FT_FORMAT_ERROR);
        (**format)++;
    }
    return (FT_FORMAT_SUCCESS);
}