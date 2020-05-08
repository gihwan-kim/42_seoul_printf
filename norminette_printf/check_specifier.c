/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:09:31 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/26 11:09:47 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_specifier(const char ***format, t_info *f_info)
{
	char *specifier_options;

	specifier_options = "cspdiuxX%";
	if (!ft_strchr(specifier_options, ***format) || !(***format))
		return (FT_FORMAT_ERROR);
	else
		f_info->specifier = ***format;
	return (FT_FORMAT_SUCCESS);
}
