/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 13:03:15 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/26 13:28:32 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_preci(const char ***format, t_info *f_info)
{
	unsigned int	nbr_no;
	char			*nbr_str;

	nbr_no = 0;
	while (1)
	{
		if (***format == '*')
			return (FT_FORMAT_ERROR);
		if (ft_strchr(PRECISION_OPTION, ***format))
			nbr_no++;
		else
			break ;
		(**format)++;
	}
	if (nbr_no)
	{
		if (!(nbr_str = (char*)malloc(sizeof(char) * (nbr_no + 1))))
			return (FT_FORMAT_ERROR);
		ft_strlcpy(nbr_str, **format - nbr_no, nbr_no + 1);
		f_info->preci = ft_atoi(nbr_str);
		free(nbr_str);
	}
	return (FT_FORMAT_SUCCESS);
}

int			check_precision(const char ***format, t_info *f_info)
{
	if (***format != '.')
		return (FT_FORMAT_SUCCESS);
	f_info->preci_check = TRUE;
	if (*(++(**format)) == '*')
	{
		f_info->preci = -1;
		(**format)++;
	}
	else
		return (set_preci(format, f_info));
	return (FT_FORMAT_SUCCESS);
}
