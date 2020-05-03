/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_d_i_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <gihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:51:29 by gihkim            #+#    #+#             */
/*   Updated: 2020/03/11 14:51:29 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *make_str(int *str_len, int sign, char *str)
{
    if (sign)
    {
        if (!(str = (char *)malloc(sizeof(char) * (++*str_len + 1))))
            return (str);
    }
    else
    {
        if (!(str = (char *)malloc(sizeof(char) * (*str_len + 1))))
            return (str);
    }
    return (str);
}

static char *set_str(unsigned int n, int sign)
{
    int str_len;
    int i;
    unsigned int temp;
    char *str;

    temp = n;
    i = -1;
    str_len = 1;
    str = NULL;
    while (temp /= 10)
        str_len++;
    if (!(str = make_str(&str_len, sign, str)))
        return (str);
    while (++i < str_len)
    {
        str[str_len - i - 1] = '0' + n % 10;
        if (sign && !(str_len - i - 1))
            str[str_len - i - 1] = '-';
        n = n / 10;
    }
    str[str_len] = '\0';
    return (str);
}

static char *ft_itoa_u(unsigned int n)
{
    return (set_str(n, 0));
}

int ap_d_i_u(format_info *f_info)
{
    char *item;

    // if (f_info->width_check == TRUE)
    // {
    //     if (f_info->width < 0) // number
    //         f_info->width = va_arg(f_info->item, int);
    // }
    // else
    //     f_info->width = 0;
    f_info->width = get_width_precision(f_info, f_info->width, f_info->width_check, 'w');
    f_info->precision = get_width_precision(f_info, f_info->precision, f_info->precision_check, 'p');
    // printf("new precision:%d\n",f_info->precision);
    if (f_info->specifier == 'u')
        item = ft_itoa_u(va_arg(f_info->item, unsigned int));
    else
        item = ft_itoa(va_arg(f_info->item, int));
    f_info->string_to_output = set_string_to_output(item, f_info);
    return (FT_FORMAT_SUCCESS);
}