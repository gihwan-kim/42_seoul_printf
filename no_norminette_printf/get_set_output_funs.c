/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_output_funs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <gihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:41:38 by gihkim            #+#    #+#             */
/*   Updated: 2020/03/13 16:41:38 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** //get_precision() :
** return : precision 값 얻는 함수, 0 : presicion 값 없음
**
** set_new_item() :
** 음수일 경우 아닐 경우 나눠서 presicion 조건에 맞게 item 을 수정
** 음수일 경우 :
**     width       : - 기호, item 까지 포함한 길이로만 비교한다.
**     precision   : - 기호를 제외한 item 의 길이로만 비교한다.
**                     new_item 생성시 - idx 를 제외하고 복사해야함
**
** set_string_to_output() :
** set_new_item() 으로 먼저 new_item 생성
** width 값과 new_item 을 비교하여 출력할 문자열 생성
*/

/*
** static unsigned int check_digit(const char *item)
** { 문자열이 숫자로 이러어져있는지 검사하는 함수
**     int i = 0;
**     while (item[i])
**     {
**         if (!ft_isdigit(item[i]))
**             return (0);
**         i++;
**     }
**     return (1);
** }
*/

#include "ft_printf.h"

int get_width_precision(format_info *f_info, int width_or_preci_value, int check_is_empty, char check)
{
	int ret;
	ret = 0;
	if (check_is_empty == TRUE)
	{
		if (width_or_preci_value >= 0)
			ret = width_or_preci_value;
		else
		{
			ret = va_arg(f_info->item, int);
			if (ret >= 0)
				return (ret);
			else
			{
				if (check == 'w')
				{
					f_info->flags_box[0] += 1;
					return (ret * -1);
				}
				else
				{
					f_info->precision_check = FALSE;
					ret = 0;
				}
			}
		}
	}
	return (ret);
}

char *set_new_item(char *item, format_info *f_info)
{
	size_t item_len;
	char *new_item;

	item_len = ft_strlen(item);
	new_item = item;
	// printf("new_item:|%s|\titem_len:|%ld|\tprecision:%d\n", new_item, item_len, f_info->precision);
	if (*item == '-')
	{
		if ((size_t)(f_info->precision) > item_len - 1)
		{
			// printf("hihihihihi");
			new_item = (char *)ft_calloc(sizeof(char), f_info->precision + 2);
			new_item[0] = '-';
			ft_memset(new_item + 1, '0', f_info->precision - (item_len - 1));
			ft_memcpy(new_item + 1 + f_info->precision - (item_len - 1), item + 1, item_len - 1);
			free(item);
		}
		// else if ( (size_t)(f_info->width) > item_len)
		// {
		// 	printf("hihihihihi");
		// 	new_item = (char *)ft_calloc(sizeof(char), f_info->width + 1);
		// 	new_item[0] = '-';
		// 	ft_memset(new_item + 1, '0', f_info->width - (item_len - 1));
		// 	ft_memcpy(new_item + 1 + f_info->width - (item_len - 1), item + 1, item_len - 1);
		// 	free(item);
		// }
	}
	else
	{
		if ((size_t)(f_info->precision) > item_len)
		{
			new_item = (char *)ft_calloc(sizeof(char), f_info->precision + 2);
			ft_memset(new_item, '0', f_info->precision - item_len);
			ft_memcpy(new_item + f_info->precision - item_len, item, item_len);
			free(item);
		}
		if ((f_info->precision_check == TRUE) && !(f_info->precision) && item_len == 1 && *item == '0')
		{
			new_item = (char *)ft_calloc(sizeof(char), 1);
			free(item);
		}
	}
	return (new_item);
}

char *set_string_to_output(char *item, format_info *f_info)
{
	char *new_item;
	char *output_str;
	size_t n_item_len;

	new_item = set_new_item(item, f_info);
	n_item_len = ft_strlen(new_item);
	// output_str = NULL;
	if ((size_t)(f_info->width) > ft_strlen(new_item)) // 남은 공간을 0 또는 ' ' 으로 채운다.
	{
		output_str = (char *)ft_calloc(sizeof(char), (f_info->width) + 1);
		// ft_memset(output_str, ' ', (f_info -> width) - n_item_len);
		ft_memset(output_str, ' ', f_info->width);
		if (f_info->flags_box[0] >= '1') // - : O | 왼쪽 출력
			ft_memcpy(output_str, new_item, n_item_len);
		else //  - : X | 오른쪽 출력
		{
			// if (f_info->flags_box[1] == '1' && f_info->precision_check == FALSE) // flags 0
			// 	ft_memset(output_str, '0', f_info->width - n_item_len);
			// ft_memcpy(output_str + f_info->width - n_item_len, new_item, n_item_len);
			if (f_info->flags_box[1] >= '1' && f_info->precision_check == FALSE) // flags 0
			{
				if (*new_item == '-')
				{
					*output_str = '-';
					ft_memset(output_str + 1, '0', f_info->width - n_item_len);
					ft_memcpy(output_str + 1 + f_info->width - n_item_len, new_item + 1, n_item_len - 1);
				}
				else
				{
					ft_memset(output_str, '0', f_info->width - n_item_len);
					ft_memcpy(output_str + f_info->width - n_item_len, new_item, n_item_len);
				}
			}
			else
				ft_memcpy(output_str + f_info->width - n_item_len, new_item, n_item_len);
		}
	}
	else // 아이템만 출력
		return (new_item);
	free(new_item);
	return (output_str);
}

char *set_string_to_output_type_c_s(char *item, format_info *f_info, char *(*f)(char *, format_info *))
{
	char *new_item;
	char *output_str;
	size_t n_item_len;

	new_item = f(item, f_info);
	n_item_len = ft_strlen(new_item);
	output_str = NULL;
	// printf("width %d \t new_item_len :%ld\n", f_info->width, ft_strlen(new_item));
	if ((size_t)(f_info->width) > ft_strlen(new_item)) // 남은 공간을  ' ' 으로 채운다.
	{
		if ((f_info->specifier == 'c') && !ft_strlen(new_item) && !(*new_item))
		{
			// write(1, "hihi", 4);
			f_info->check = 1;
			output_str = (char *)ft_calloc(sizeof(char), f_info->width);
			ft_memset(output_str, ' ', f_info->width - 1);
			// output_str[f_info->width - 2] = '\0';
			if (f_info->flags_box[0] >= '1') // - : O | 왼쪽 출력
				ft_memcpy(output_str, new_item, n_item_len);
			else //  - : X | 오른쪽 출력
				ft_memcpy(output_str + f_info->width - 1 - n_item_len, new_item, n_item_len);
		}
		else
		{
			output_str = (char *)ft_calloc(sizeof(char), f_info->width + 1);
			ft_memset(output_str, ' ', f_info->width);
			if (f_info->flags_box[0] >= '1') // - : O | 왼쪽 출력
				ft_memcpy(output_str, new_item, n_item_len);
			else //  - : X | 오른쪽 출력
				// ft_memcpy(output_str + f_info->width - n_item_len, new_item, n_item_len);
			{
				if (f_info->flags_box[1] >= '1' && f_info->precision_check == FALSE) // flags 0
				{
					ft_memset(output_str, '0', f_info->width);
					ft_memcpy(output_str + f_info->width - n_item_len, new_item, n_item_len);
				}
				else
					ft_memcpy(output_str + f_info->width - n_item_len, new_item, n_item_len);
			}
		}
	}
	else // 아이템만 출력
		return (new_item);
	free(new_item);
	//free(item); 두번 해제해버림
	return (output_str);
}

char *set_string_to_output_type_p(char *item, format_info *f_info, char *(*f)(char *, format_info *))
{
	char *new_item;
	char *output_str;
	size_t n_item_len;

	new_item = f(item, f_info);
	output_str = NULL;
	n_item_len = ft_strlen(new_item);										  // 0x 까지 포함된 길이
	if (f_info->width_check && (size_t)(f_info->width) > ft_strlen(new_item)) // 남은 공간을 0 또는 ' ' 으로 채운다.
	{
		output_str = (char *)ft_calloc(sizeof(char), f_info->width + 1);
		// ft_memset(output_str, ' ', (f_info -> width) - n_item_len);
		ft_memset(output_str, ' ', f_info->width);
		if (f_info->flags_box[0] == '1') // - : O | 왼쪽 출력
			ft_memcpy(output_str, new_item, n_item_len);
		else //  - : X | 오른쪽 출력
		{
			if (f_info->flags_box[1] == '1' && f_info->precision_check == FALSE) // flags 0
			{
				ft_memcpy(output_str, new_item, 2);
				ft_memset(output_str + 2, '0', f_info->width - n_item_len);
				ft_memcpy(output_str + 2 + f_info->width - n_item_len, new_item + 2, n_item_len - 2);
			}
			else
				ft_memcpy(output_str + f_info->width - n_item_len, new_item, n_item_len);
		}
	}
	else // 아이템만 출력
		return (new_item);
	free(new_item);
	return (output_str);
}