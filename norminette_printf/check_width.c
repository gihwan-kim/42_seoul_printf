/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:21:01 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/26 13:38:05 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 0~9, * 같이 있으면 안됨 하나만 있어야됨
** %1234d o %12*d x
*/

#include "ft_printf.h"

static int	set_width(const char ***format, t_info *f_info, int star, int nbr)
{
	char *nbr_str;

	if (star && !nbr)
	{
		f_info->width = -1;
		f_info->width_check = TRUE;
		return (FT_FORMAT_SUCCESS);
	}
	else if (!star && nbr)
	{
		if (!(nbr_str = (char *)malloc(sizeof(char) * (nbr + 1))))
			return (FT_FORMAT_ERROR);
		ft_strlcpy(nbr_str, **format - nbr, nbr + 1);
		f_info->width = ft_atoi(nbr_str);
		f_info->width_check = TRUE;
		free(nbr_str);
		return (FT_FORMAT_SUCCESS);
	}
	else if (!nbr && !star)
		return (FT_FORMAT_SUCCESS);
	return (FT_FORMAT_ERROR);
}

int			check_width(const char ***format, t_info *f_info)
{
	unsigned int	nbr_no;
	unsigned int	star_no;
	char			*width_options;

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
	return (set_width(format, f_info, star_no, nbr_no));
}
