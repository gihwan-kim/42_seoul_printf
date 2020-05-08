/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 10:56:23 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/26 10:57:00 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*set_new_item_p(char *item, t_info *f_info)
{
	size_t	item_len;
	char	*new_item;

	item_len = ft_strlen(item) - 2;
	new_item = item;
	if ((size_t)(f_info->preci) > item_len)
	{
		new_item = (char *)ft_calloc(sizeof(char), f_info->preci + 3);
		ft_memcpy(new_item, item, 2);
		ft_memset(new_item + 2, '0', f_info->preci - item_len);
		ft_memcpy(new_item + 2 + f_info->preci - item_len, item + 2, item_len);
		free(item);
	}
	return (new_item);
}

int			ap_p(t_info *f_info)
{
	unsigned long	item;
	char			*item_str;
	size_t			item_len;

	item_len = 0;
	item_str = NULL;
	f_info->width = get_w_p(f_info, f_info->width, f_info->width_check, 'w');
	f_info->preci = get_w_p(f_info, f_info->preci, f_info->preci_check, 'p');
	item = va_arg(f_info->item, unsigned long);
	ft_itoa_base(item, "get item_len", item_str, &item_len);
	if (!(item_str = (char *)ft_calloc(sizeof(char), (item_len + 3))))
		return (FT_PRINTF_ERROR);
	item_len = 0;
	ft_itoa_base(item, "0123456789abcdef", item_str + 2, &item_len);
	item_str[0] = '0';
	item_str[1] = 'x';
	if ((ft_strlen(item_str) == 3) && (item_str[2] == '0')
		&& !(f_info->preci) && (f_info->preci_check))
		item_str[2] = '\0';
	f_info->output = set_output_p(item_str, f_info, set_new_item_p);
	return (FT_FORMAT_SUCCESS);
}
