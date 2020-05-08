/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 09:33:47 by gihkim            #+#    #+#             */
/*   Updated: 2020/04/27 09:50:21 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include "ft_format_info.h"
# define FT_FORMAT_ERROR 0
# define FT_PRINTF_ERROR -1
# define FT_FORMAT_SUCCESS 1
# define TRUE 1
# define FALSE 0
# define FT_FD 1

int		ap_c(t_info *info);
int		ap_s(t_info *info);
int		ap_p(t_info *info);
int		ap_x_big_x(t_info *info);
int		ap_d_i_u(t_info *info);
int		ap_percent(t_info *info);
int		check_flags(const char ***format, t_info *info);
int		check_width(const char ***format, t_info *info);
int		check_length(const char ***format, t_info *info);
int		check_precision(const char ***format, t_info *info);
int		check_specifier(const char ***format, t_info *info);
int		get_w_p(t_info *info, int val, int f_check, char check);
char	*init_output_str(t_info *f_info);
char	*set_new_item(char *item, t_info *info);
char	*set_output_integer(char *item, t_info *info);
char	*set_output_p(char *s, t_info *info, char *(*f)(char *, t_info *));
char	*set_output_c_s(char *s, t_info *info, char *(*f)(char *, t_info *));
void	ft_itoa_base(unsigned long nbr, char *base, char *a, size_t *item_len);
void	initialize_t_info(t_info *info);

#endif
