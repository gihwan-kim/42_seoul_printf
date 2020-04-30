/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <gihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:21:15 by gihkim            #+#    #+#             */
/*   Updated: 2020/03/11 11:21:15 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    check_precision(const char ***format, format_info *f_info) 
{
    char *precision_options;
    char *nbr_str;
    unsigned int nbr_no;

    if (***format != '.')
        return (FT_FORMAT_SUCCESS);
    f_info -> precision_check = TRUE;
    if (*(++(**format)) == '*')
    {
        f_info -> precision = -1;
        (**format)++;
    }
    else
    {
        nbr_no = 0;
        precision_options = "0123456789";
        while (1)
        {
        // nbr 있는지 확인하며 no 증가시킴
            if (***format == '*')
                return (FT_FORMAT_ERROR);
            if (ft_strchr(precision_options, ***format))
                nbr_no++;
            else
                break ;
            (**format)++;
        }
        // nbr 있을 경우 atoi 해서 f_ino 에 넣기
        if (nbr_no)
        {
            if(!(nbr_str = (char*)malloc(sizeof(char) * (nbr_no + 1))))
                return (FT_FORMAT_ERROR);
            ft_strlcpy(nbr_str, **format - nbr_no, nbr_no + 1);
            f_info -> precision = ft_atoi(nbr_str);
            free(nbr_str);
        }
        // nbr_no 0일 경우 . 만있는 경우니 precision 에 0 을 줘서 .0 과 같게한다.
        // else
        //     f_info -> precision = 0;
    }
    return (FT_FORMAT_SUCCESS);
}