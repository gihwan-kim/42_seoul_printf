/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_t_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:16:59 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/26 11:17:36 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_t_info(t_info *f_info)
{
	f_info->output = NULL;
	ft_memset(f_info->flags_box, '0', 5);
	f_info->flags_box[5] = '\0';
	f_info->width_check = FALSE;
	f_info->width = 0;
	f_info->preci_check = FALSE;
	f_info->preci = 0;
	ft_memset(f_info->length_box, '0', 5);
	f_info->length_box[5] = '\0';
	f_info->specifier = 0;
	f_info->check = 0;
}
