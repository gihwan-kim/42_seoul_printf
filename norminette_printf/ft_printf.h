/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <gihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:33:21 by gihkim            #+#    #+#             */
/*   Updated: 2020/03/05 16:33:21 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF
#include "./libft/libft.h"
// #include "stddef.h"
#include <stdarg.h>
#define FT_FORMAT_ERROR 0
#define FT_PRINTF_ERROR -1
#define FT_FORMAT_SUCCESS 1
#define TRUE 1
#define FALSE 0
#define FT_FD 1

typedef struct ft_format_info
{
    va_list item;
    char *string_to_output;
    char flags_box[6];
    char length_box[6];
    char specifier;
    int width_check;
    int width;
    int precision_check;
    int precision;
    int check;
} format_info;

void initialize_format_info(format_info *f_info);
int controller(const char *format, va_list ap);
int model(const char **format, format_info *f_info);
int check_flags(const char ***format, format_info *f_info);
int check_width(const char ***format, format_info *f_info);
int check_length(const char ***format, format_info *f_info);
int check_precision(const char ***format, format_info *f_info);
int check_specifier(const char ***format, format_info *f_info);
// int	get_width(format_info *f_info);
// int  get_precision(format_info *f_info);
int get_width_precision(format_info *f_info, int width_or_preci_value, int check_is_empty, char check);
char *set_new_item(char *item, format_info *f_info);
char *set_string_to_output(char *item, format_info *f_info);
char *set_string_to_output_type_c_s(char *item, format_info *f_info, char *(*f)(char *, format_info *));
char *set_string_to_output_type_p(char *item, format_info *f_info, char *(*f)(char *, format_info *));
void ft_itoa_base(unsigned long nbr, char *base, char *a, size_t *item_len);
int ap_d_i_u(format_info *f_info);
int ap_x_X(format_info *f_info);
int ap_c(format_info *f_info);
int ap_s(format_info *f_info);
int ap_p(format_info *f_info);
int ap_percent(format_info *f_info);

#endif