/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 10:58:01 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/26 10:59:35 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*set_new_item_type_s(char *item, t_info *f_info)
{
	size_t	item_len;
	char	*new_item;

	item_len = ft_strlen(item);
	new_item = item;
	if (f_info->preci_check && (size_t)(f_info->preci) < item_len)
	{
		new_item = (char *)ft_calloc(sizeof(char), f_info->preci + 1);
		ft_memcpy(new_item, item, f_info->preci);
		free(item);
	}
	return (new_item);
}

int			ap_s(t_info *f_info)
{
	char *item;
	char *temp;

	f_info->width = get_w_p(f_info, f_info->width, f_info->width_check, 'w');
	f_info->preci = get_w_p(f_info, f_info->preci, f_info->preci_check, 'p');
	temp = (char *)va_arg(f_info->item, char *);
	if (!(item = (char *)ft_calloc(sizeof(char), (ft_strlen(temp) + 1))))
		return (FT_FORMAT_ERROR);
	if (!temp)
	{
		if (!(item = (char *)ft_calloc(sizeof(char), 7)))
			return (FT_FORMAT_ERROR);
		ft_strlcpy(item, "(null)", 7);
	}
	else
	{
		if (!(item = (char *)ft_calloc(sizeof(char), (ft_strlen(temp) + 1))))
			return (FT_FORMAT_ERROR);
	}
	if (temp)
		ft_strlcpy(item, temp, ft_strlen(temp) + 1);
	f_info->output = set_output_c_s(item, f_info, set_new_item_type_s);
	return (FT_FORMAT_SUCCESS);
}
