/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_funs_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 14:42:15 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/26 14:43:56 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*init_output_str(t_info *f_info)
{
	char *output_str;

	output_str = (char *)ft_calloc(sizeof(char), (f_info->width) + 1);
	ft_memset(output_str, ' ', f_info->width);
	return (output_str);
}

int		get_w_p(t_info *f_info, int val, int f_check, char check)
{
	int ret;

	ret = 0;
	if (f_check == TRUE)
	{
		if (val >= 0)
			ret = val;
		else
		{
			ret = va_arg(f_info->item, int);
			if (ret < 0)
			{
				if (check == 'w')
					f_info->flags_box[0] += 1;
				else
					f_info->preci_check = FALSE;
				ret = (check == 'w') ? ret * -1 : 0;
			}
		}
	}
	return (ret);
}
