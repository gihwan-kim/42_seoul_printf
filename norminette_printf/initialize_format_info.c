/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_format_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <gihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 15:07:11 by gihkim            #+#    #+#             */
/*   Updated: 2020/03/14 15:07:11 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// typedef struct ft_format_info
// {
//     va_list item;
//     char *string_to_output;
//     char flags_box[6];
//     char length_box[6];
//     char specifier;
//     int  width_check;
//     int  width;
//     int  precision_check;
//     int  precision;
// } format_info;

void initialize_format_info(format_info *f_info)
{
    f_info->string_to_output = NULL;
    ft_memset(f_info->flags_box, '0', 5);
    f_info->flags_box[5] = '\0';
    f_info->width_check = FALSE;
    f_info->width = 0; // no width value
    f_info->precision_check = FALSE;
    f_info->precision = 0; // no width value
    ft_memset(f_info->length_box, '0', 5);
    f_info->length_box[5] = '\0';
    f_info->specifier = 0;
    f_info->check = 0;
}