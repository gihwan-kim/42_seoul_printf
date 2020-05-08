/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_output_funs_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 14:35:17 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/27 09:50:12 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	no_minus_flag_p(t_info *f_info, char *new_item, char *output)
{
	size_t	item_len;

	item_len = ft_strlen(new_item);
	if (f_info->flags_box[1] >= '1' && f_info->preci_check == FALSE)
	{
		ft_memcpy(output, new_item, 2);
		ft_memset(output + 2, '0', f_info->width - item_len);
		ft_memcpy(output + 2 + f_info->width - item_len,
			new_item + 2, item_len - 2);
	}
	else
		ft_memcpy(output + f_info->width - item_len, new_item, item_len);
}

char		*set_output_p(char *s, t_info *f_info, char *(*f)(char*, t_info*))
{
	size_t	item_len;
	char	*new_item;
	char	*output_str;
	char	*item;

	item = s;
	new_item = f(item, f_info);
	item_len = ft_strlen(new_item);
	if (f_info->width_check && ((size_t)(f_info->width) > item_len))
	{
		output_str = init_output_str(f_info);
		if (f_info->flags_box[0] >= '1')
			ft_memcpy(output_str, new_item, item_len);
		else
			no_minus_flag_p(f_info, new_item, output_str);
	}
	else
		return (new_item);
	free(new_item);
	return (output_str);
}
