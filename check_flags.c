/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <gihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:18:55 by gihkim            #+#    #+#             */
/*   Updated: 2020/03/11 11:18:55 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** check only flags ERROR
*/

#include "ft_printf.h"

int     check_flags(const char ***format, format_info *f_info)
{
    char *flags_options;

    flags_options = "-0 +#";
    while (1)
    {
        if (!ft_strchr(flags_options, (***format)))
            break ;
        if (***format == '-')
            f_info -> flags_box[0] += 1;
        else if (***format == '0')
            f_info -> flags_box[1] += 1;
        else if (***format == ' ')
            f_info -> flags_box[2] += 1;
        else if (***format == '+')
            f_info -> flags_box[3] += 1;
        else
            f_info -> flags_box[4] += 1;
        // if (ft_strchr(f_info -> flags_box, '2'))
        //     return (FT_FORMAT_ERROR); // 개별 구역 에러
        // if ((f_info -> flags_box[0] == '1') && (f_info -> flags_box[1] == '1'))
        //     return (FT_FORMAT_ERROR);
        (**format)++;
    }
    return (FT_FORMAT_SUCCESS);
}