/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <gihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:22:38 by gihkim            #+#    #+#             */
/*   Updated: 2020/03/11 11:22:38 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** cspdiuxX% 만 구현하기!!!
** c : int 값을 unsigned char 로 10 진수
** s : 문자열
** p : 포인터
** d : int 10 진수
** i  : int 10진수
** u : unsigned int 10 진수
** x , X : unsigned int 16진수
*/

#include "ft_printf.h"

int    check_specifier(const char ***format, format_info *f_info)
{
    char *specifier_options;
    specifier_options = "cspdiuxX%";
    if (!ft_strchr(specifier_options, ***format) || !(***format))
        return (FT_FORMAT_ERROR);
    else
        f_info -> specifier = ***format;
    return (FT_FORMAT_SUCCESS);
}