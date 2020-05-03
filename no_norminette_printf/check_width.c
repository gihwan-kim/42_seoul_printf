/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <gihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:20:01 by gihkim            #+#    #+#             */
/*   Updated: 2020/03/11 11:20:01 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 0~9, * 같이 있으면 안됨 하나만 있어야됨
** %1234d o %12*d x
*/

#include "ft_printf.h"

int    check_width(const char ***format, format_info *f_info)
{
    char *width_options;
    char *nbr_str;
    unsigned int nbr_no;
    unsigned int star_no;

    nbr_no = 0;
    star_no = 0;
    width_options = "*0123456789";
    while (ft_strchr(width_options, ***format))
    {
        if (ft_strchr(width_options + 1, ***format))
            nbr_no++;
        if (ft_strchr("*", ***format))
            star_no++;
        if (nbr_no && star_no && star_no >= 2)
            return (FT_FORMAT_ERROR);
        (**format)++;
    }
    // * 만 있을 경우 함수 끝, -1을 *로 지정하기
    if (star_no && !nbr_no)
    {
        f_info -> width = -1;
        f_info -> width_check = TRUE;
        return (FT_FORMAT_SUCCESS);
    }
    // nbr 만 있을 경우 atoi 해서 f_info 에 넣기
    else if (!star_no && nbr_no)
    {
        if(!(nbr_str = (char*)malloc(sizeof(char) * (nbr_no + 1))))
            return (FT_FORMAT_ERROR);
        ft_strlcpy(nbr_str, **format - nbr_no, nbr_no + 1);
        f_info -> width = ft_atoi(nbr_str);
        f_info -> width_check = TRUE;
        free(nbr_str);
        return (FT_FORMAT_SUCCESS);
    }
    // width 옵션이 없을 경우
    else if (!nbr_no && !star_no)
        return (FT_FORMAT_SUCCESS);
    return (FT_FORMAT_ERROR);   
}