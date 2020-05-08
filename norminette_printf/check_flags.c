/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:01:14 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/26 11:01:38 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** check only flags ERROR
*/

#include "ft_printf.h"

int	check_flags(const char ***format, t_info *f_info)
{
	char *flags_options;

	flags_options = "-0 +#";
	while (1)
	{
		if (!ft_strchr(flags_options, (***format)))
			break ;
		if (***format == '-')
			f_info->flags_box[0] += 1;
		else if (***format == '0')
			f_info->flags_box[1] += 1;
		else if (***format == ' ')
			f_info->flags_box[2] += 1;
		else if (***format == '+')
			f_info->flags_box[3] += 1;
		else
			f_info->flags_box[4] += 1;
		(**format)++;
	}
	return (FT_FORMAT_SUCCESS);
}
