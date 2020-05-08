/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_output_funs_integer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 13:53:23 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/27 09:46:00 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_new_item(char *item, size_t len, size_t idx, t_info *f_info)
{
	size_t	len_idx;
	char	*new_item;

	len_idx = len - idx;
	new_item = (char*)ft_calloc(sizeof(char), f_info->preci + 2);
	if (idx)
		new_item[0] = '-';
	ft_memset(new_item + idx, '0', f_info->preci - len_idx);
	ft_memcpy(new_item + idx + f_info->preci - len_idx, item + idx, len_idx);
	free(item);
	return (new_item);
}

static void	no_minus_flag(char *output, t_info *f_info, char *item)
{
	size_t	item_len;
	int		idx;

	item_len = ft_strlen(item);
	idx = 0;
	if (f_info->flags_box[1] >= '1' && f_info->preci_check == FALSE)
	{
		if (*item == '-')
		{
			*output = '-';
			idx = 1;
		}
		ft_memset(output + idx, '0', f_info->width - item_len);
	}
	ft_memcpy(output + idx + f_info->width - item_len,
		item + idx, item_len - idx);
}

char		*set_new_item(char *item, t_info *f_info)
{
	size_t	item_len;
	char	*new_item;

	item_len = ft_strlen(item);
	new_item = item;
	if (*item == '-')
	{
		if ((size_t)(f_info->preci) > item_len - 1)
			new_item = make_new_item(item, item_len, 1, f_info);
	}
	else
	{
		if ((size_t)(f_info->preci) > item_len)
			new_item = make_new_item(item, item_len, 0, f_info);
		if ((f_info->preci_check == TRUE) && !(f_info->preci)
			&& item_len == 1 && *item == '0')
		{
			new_item = (char *)ft_calloc(sizeof(char), 1);
			free(item);
		}
	}
	return (new_item);
}

char		*set_output_integer(char *item, t_info *f_info)
{
	size_t	item_len;
	char	*new_item;
	char	*output_str;

	new_item = set_new_item(item, f_info);
	item_len = ft_strlen(new_item);
	if ((size_t)(f_info->width) > ft_strlen(new_item))
	{
		output_str = init_output_str(f_info);
		if (f_info->flags_box[0] >= '1')
			ft_memcpy(output_str, new_item, item_len);
		else
			no_minus_flag(output_str, f_info, new_item);
	}
	else
		return (new_item);
	free(new_item);
	return (output_str);
}
