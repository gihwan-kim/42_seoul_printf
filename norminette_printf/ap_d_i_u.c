/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_d_i_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 10:53:23 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/26 10:55:49 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_str(int *str_len, int sign, char *str)
{
	if (sign)
	{
		if (!(str = (char *)malloc(sizeof(char) * (++*str_len + 1))))
			return (str);
	}
	else
	{
		if (!(str = (char *)malloc(sizeof(char) * (*str_len + 1))))
			return (str);
	}
	return (str);
}

static char	*set_str(unsigned int n, int sign)
{
	unsigned int	temp;
	int				str_len;
	int				i;
	char			*str;

	temp = n;
	i = -1;
	str_len = 1;
	str = NULL;
	while (temp /= 10)
		str_len++;
	if (!(str = make_str(&str_len, sign, str)))
		return (str);
	while (++i < str_len)
	{
		str[str_len - i - 1] = '0' + n % 10;
		if (sign && !(str_len - i - 1))
			str[str_len - i - 1] = '-';
		n = n / 10;
	}
	str[str_len] = '\0';
	return (str);
}

static char	*ft_itoa_u(unsigned int n)
{
	return (set_str(n, 0));
}

int			ap_d_i_u(t_info *f_info)
{
	char *item;

	f_info->width = get_w_p(f_info, f_info->width, f_info->width_check, 'w');
	f_info->preci = get_w_p(f_info, f_info->preci, f_info->preci_check, 'p');
	if (f_info->specifier == 'u')
		item = ft_itoa_u(va_arg(f_info->item, unsigned int));
	else
		item = ft_itoa(va_arg(f_info->item, int));
	f_info->output = set_output_integer(item, f_info);
	return (FT_FORMAT_SUCCESS);
}
