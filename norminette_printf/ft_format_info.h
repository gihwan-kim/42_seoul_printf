/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_info.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 09:56:50 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/27 09:53:27 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_INFO_H
# define FT_FORMAT_INFO_H
# include <stdarg.h>
# define PRECISION_OPTION "0123456789"

typedef struct	s_format_info
{
	va_list	item;
	char	*output;
	char	flags_box[6];
	char	length_box[6];
	char	specifier;
	int		width_check;
	int		width;
	int		preci_check;
	int		preci;
	int		check;
}				t_info;

#endif
