/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:12:20 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/26 13:51:02 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	model(const char **format, t_info *f_info)
{
	++(*format);
	if (check_flags(&format, f_info) && check_width(&format, f_info)
		&& check_precision(&format, f_info) && check_specifier(&format, f_info))
	{
		if (ft_strchr("diu", f_info->specifier))
			return (ap_d_i_u(f_info));
		if (ft_strchr("xX", f_info->specifier))
			return (ap_x_big_x(f_info));
		if (f_info->specifier == 'c')
			return (ap_c(f_info));
		if (f_info->specifier == 's')
			return (ap_s(f_info));
		if (f_info->specifier == 'p')
			return (ap_p(f_info));
		if (f_info->specifier == '%')
			return (ap_percent(f_info));
		return (FT_FORMAT_ERROR);
	}
	else
		return (FT_FORMAT_ERROR);
	return (FT_FORMAT_SUCCESS);
}

static int	print_output(t_info *f_info, int param_printf)
{
	int printf_return_val;

	printf_return_val = param_printf;
	if (f_info->check || ((f_info->specifier == 'c') && !(f_info->width)
		&& !ft_strlen(f_info->output)))
	{
		printf_return_val += ft_strlen(f_info->output) + 1;
		if (f_info->flags_box[0] >= '1')
			write(1, "\0", 1);
		ft_putstr_fd(f_info->output, FT_FD);
		if (f_info->flags_box[0] == '0')
			write(1, "\0", 1);
	}
	else
	{
		printf_return_val += ft_strlen(f_info->output);
		ft_putstr_fd(f_info->output, FT_FD);
	}
	free(f_info->output);
	return (printf_return_val);
}

static int	controller(const char *format, va_list ap)
{
	t_info		f_info;
	int			printf_return_val;

	va_copy(f_info.item, ap);
	printf_return_val = 0;
	while (1)
	{
		initialize_t_info(&f_info);
		if (!*format)
			break ;
		if (*format != '%')
		{
			printf_return_val++;
			ft_putchar_fd(*format, FT_FD);
		}
		else
		{
			if (model(&format, &f_info))
				printf_return_val = print_output(&f_info, printf_return_val);
			else
				return (FT_PRINTF_ERROR);
		}
		format++;
	}
	return (printf_return_val);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			return_val;

	va_start(ap, format);
	return_val = controller(format, ap);
	va_end(ap);
	return (return_val);
}
