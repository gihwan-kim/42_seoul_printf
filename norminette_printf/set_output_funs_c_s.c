/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_output_funs_c_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 14:31:19 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/27 09:49:31 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_output_c_s(t_info *f_info, char *new_item, int idx)
{
	size_t	item_len;
	char	*output;

	item_len = ft_strlen(new_item);
	if (idx)
	{
		f_info->check = 1;
		output = (char *)ft_calloc(sizeof(char), f_info->width);
	}
	else
		output = (char *)ft_calloc(sizeof(char), f_info->width + 1);
	ft_memset(output, ' ', f_info->width - idx);
	if (f_info->flags_box[0] >= '1')
		ft_memcpy(output, new_item, item_len);
	else
	{
		if (!idx)
		{
			if (f_info->flags_box[1] >= '1' && f_info->preci_check == FALSE)
				ft_memset(output, '0', f_info->width);
		}
		ft_memcpy(output + f_info->width - idx - item_len, new_item, item_len);
	}
	return (output);
}

char		*set_output_c_s(char *s, t_info *info, char *(*f)(char*, t_info*))
{
	char *new_item;
	char *output_str;
	char *item;

	item = s;
	new_item = f(item, info);
	if ((size_t)(info->width) > ft_strlen(new_item))
	{
		if ((info->specifier == 'c') && !ft_strlen(new_item) && !(*new_item))
			output_str = make_output_c_s(info, new_item, 1);
		else
			output_str = make_output_c_s(info, new_item, 0);
	}
	else
		return (new_item);
	free(new_item);
	return (output_str);
}
