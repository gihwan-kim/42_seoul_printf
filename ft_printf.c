/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <gihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:00:26 by gihkim            #+#    #+#             */
/*   Updated: 2020/03/05 15:00:26 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>

int     ft_printf(const char *format, ...)
 {
	int return_val;

    va_list ap; // 매개변수 리스트를 가리키는 포인터임
	va_start(ap, format);
    return_val =  controller(format, ap);
    va_end(ap);
	return (return_val);
}

int     controller(const char *format, va_list ap)
{
    int printf_return_val;
    // char format_c;
    format_info f_info;

    va_copy(f_info.item, ap);
    printf_return_val = 0;
    while (1)
    {
        // format_c = *format;
        initialize_format_info(&f_info);
        if (!*format) // (!format_c)
            break ;
        if (*format != '%') // not format specifier(format_c != '%')
        {
            printf_return_val++;
            ft_putchar_fd(*format, FT_FD); // ft_putchar_fd(format_c, FT_FD);
        }
        // else if (*(format + 1) == '%') // not format specifier %%
        // {
        //     ft_putchar_fd(*format, FT_FD); //ft_putchar_fd(format_c, FT_FD);
        //     printf_return_val++;
        //     format ++;
        // }
        else
        {
            if (model(&format, &f_info)) // format specifier return = 0 : ERROR
            {
                if (f_info.check ||((f_info.specifier == 'c') && !(f_info.width) && !ft_strlen(f_info.string_to_output)))
                {
                    printf_return_val += ft_strlen(f_info.string_to_output) + 1;
                    if (f_info.flags_box[0] >= '1')
                        write(1, "\0", 1);
                    ft_putstr_fd(f_info.string_to_output, FT_FD);
                    if (f_info.flags_box[0] == '0')
                        write(1, "\0", 1);
                }
                else
                {
                    printf_return_val += ft_strlen(f_info.string_to_output);
                    ft_putstr_fd(f_info.string_to_output, FT_FD);
                }
                free(f_info.string_to_output);
            }
            else
                return (FT_PRINTF_ERROR);
        }
        // printf_return_val++;
        format++;
    }
    return (printf_return_val);
}
// %[flags][width][.precision][length][specifier]
// format 에서 %가 나오면 ap 출력한뒤 다시 controller 로돌아와야함 format 은 이동된 상태여야
int     model(const char **format, format_info *f_info)
{
    ++(*format);
    // 개별 비교
    if (check_flags(&format, f_info) && check_width(&format, f_info)
        && check_precision(&format, f_info) && check_length(&format, f_info)
        && check_specifier(&format, f_info))
    {
        // printf("flag           : %s\n", f_info ->flags_box); printf("width          : %d\n", f_info -> width);
        // printf("precision_check: %d\n", f_info -> precision_check); printf("width_check    :% d\n", f_info -> width_check);
        // printf("precision      : %d\n", f_info -> precision); printf("length         : %s\n", f_info -> length_box); printf("sepcifier      : %c\n", f_info -> specifier);

        /* 서로비교 */
        // if (f_info -> flags_box[1] == '1') // 0있을 경우
        // {
        //     if (f_info -> precision_check == TRUE && ft_strchr("diuxX", f_info -> specifier))
        //         return (FT_FORMAT_ERROR);
        //     if (f_info -> flags_box[0] == '1' || ft_strchr("psc", f_info -> specifier))
        //         return (FT_FORMAT_ERROR);
        // }
        // if (f_info -> precision_check == TRUE && ft_strchr("cp", f_info -> precision))
        //         return (FT_FORMAT_ERROR);
        if (ft_strchr("diu", f_info -> specifier))
            return (ap_d_i_u(f_info));
        if (ft_strchr("xX", f_info -> specifier))
            return (ap_x_X(f_info));
        if (f_info -> specifier == 'c')
            return (ap_c(f_info));
        if (f_info -> specifier == 's')
            return (ap_s(f_info));
        if (f_info -> specifier == 'p')
            return (ap_p(f_info));
        if (f_info -> specifier == '%')
            return (ap_percent(f_info));
        // write(1,"sfdf", 4);
        return (FT_FORMAT_ERROR);
    }
    else
        return (FT_FORMAT_ERROR);
    return (FT_FORMAT_SUCCESS);
}


// int main(void)
// {
//     int		a = 4;
// 	int		b = 0;
// 	char	c = 'a';
// 	int		d = 2147483647;
// 	int		e = -2147483648;
// 	int		f = 42;
// 	int		g = 25;
// 	int		h = 4200;
// 	int		i = 8;
// 	int		j = -12;
// 	int		k = 123456789;
// 	int		l = 0;
// 	int		m = -12345678;
// 	char	*n = "abcdefghijklmnop";
// 	char	*o = "-a";
// 	char	*p = "-12";
// 	char	*q = "0";
// 	char	*r = "%%";
// 	char	*s = "-2147483648";
// 	char	*t = "0x12345678";
// 	char	*u = "-0";

//     // printf(" --- Return : %d\n", printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
//     // ft_printf(" --- Return : %d\n", ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
//     // printf(" --- Return : %d\n", printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
//     // ft_printf(" --- Return : %d\n", ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
//     // printf(" --- Return : %d\n", printf("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0));
//     // ft_printf(" --- Return : %d\n", ft_printf("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0));
//     // printf(" --- Return : %d\n", printf("|%c|, |%-c|, |%12c|, |%-3c|, |%-1c|, |%1c|, |%-2c|, |%-4c|, |%5c|, |%3c|, |%-*c|, |%-*c|, |%*c|, |%*c|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
//     // ft_printf(" --- Return : %d\n", ft_printf("|%c|, |%-c|, |%12c|, |%-3c|, |%-1c|, |%1c|, |%-2c|, |%-4c|, |%5c|, |%3c|, |%-*c|, |%-*c|, |%*c|, |%*c|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
//     printf(" --- Return : %d\n", printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
//     ft_printf(" --- Return : %d\n", ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));

//     // ft_printf("ft_printf: %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
//     // printf("printf   : %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
//     // ft_printf("ft_printf: %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);

//     // ft_printf("hi\n");
//     printf(" --- Return : %d\n", printf("|%c|",0));
//     printf(" --- Return : %d\n", printf("|%-c|",0));
//     printf(" --- Return : %d\n", printf("|%12c|",0));
//     printf(" --- Return : %d\n", printf("|%-3c|",0));
//     printf(" --- Return : %d\n", printf("|%-1c|",0));
//     printf(" --- Return : %d\n", printf("|%1c|",0));
//     printf(" --- Return : %d\n", printf("|%-2c|",0));
//     printf(" --- Return : %d\n", printf("|%-4c|",0));
//     printf(" --- Return : %d\n", printf("|%5c|",0));
//     printf(" --- Return : %d\n", printf("|%3c|",0));
//     printf(" --- Return : %d\n", printf("|%-*c|",-1, 0));
//     printf(" --- Return : %d\n", printf("|%-*c|", 0, 0));
//     printf(" --- Return : %d\n", printf("|%*c|", 0, 0));
//     printf(" --- Return : %d\n", printf("|%*c|", 0, 0));
//     printf("------------------------------------------------\n");
//     ft_printf(" hi--- Return : %d\n", ft_printf("|%c|",0));
//     ft_printf(" --- Return : %d\n", ft_printf("|%-c|",0));
//     ft_printf(" --- Return : %d\n", ft_printf("|%12c|",0));
//     ft_printf(" --- Return : %d\n", ft_printf("|%-3c|",0));
//     ft_printf(" --- Return : %d\n", ft_printf("|%-1c|",0));
//     ft_printf(" --- Return : %d\n", ft_printf("|%1c|",0));
//     ft_printf(" --- Return : %d\n", ft_printf("|%-2c|",0));
//     ft_printf(" --- Return : %d\n", ft_printf("|%-4c|",0));
//     ft_printf(" --- Return : %d\n", ft_printf("|%5c|",0));
//     ft_printf(" --- Return : %d\n", ft_printf("|%3c|",0));
//     ft_printf(" --- Return : %d\n", ft_printf("|%-*c|",-1, 0));
//     ft_printf(" --- Return : %d\n", ft_printf("|%-*c|", 0, 0));
//     ft_printf(" --- Return : %d\n", ft_printf("|%*c|", 0, 0));
//     ft_printf(" --- Return : %d\n", ft_printf("|%*c|", 0, 0));

//     // printf("\n%c\n", 0);
//     // printf(" --- Return : %d\n", printf("%c",0));
//     // printf(" --- Return : %d\n", printf("%-c",0));
//     // printf(" --- Return : %d\n", printf("%12c",0));
//     // printf(" --- Return : %d\n", printf("%-3c",0));
//     // printf(" --- Return : %d\n", printf("%-1c",0));
//     // printf(" --- Return : %d\n", printf("%1c",0));
//     // printf(" --- Return : %d\n", printf("%-2c",0));
//     // printf(" --- Return : %d\n", printf("%-4c",0));
//     // printf(" --- Return : %d\n", printf("%5c",0));
//     // printf(" --- Return : %d\n", printf("%3c",0));
//     // printf(" --- Return : %d\n", printf("%-*c",-1, 0));
//     // printf(" --- Return : %d\n", printf("%-*c", 0, 0));
//     // printf(" --- Return : %d\n", printf("%*c", 0, 0));
//     // printf(" --- Return : %d\n", printf("%*c", 0, 0));
//     // printf("------------------------------------------------\n");
//     // ft_printf(" --- Return : %d\n", ft_printf("%c",0));
//     // ft_printf(" --- Return : %d\n", ft_printf("%-c",0));
//     // ft_printf(" --- Return : %d\n", ft_printf("%12c",0));
//     // ft_printf(" --- Return : %d\n", ft_printf("%-3c",0));
//     // ft_printf(" --- Return : %d\n", ft_printf("%-1c",0));
//     // ft_printf(" --- Return : %d\n", ft_printf("%1c",0));
//     // ft_printf(" --- Return : %d\n", ft_printf("%-2c",0));
//     // ft_printf(" --- Return : %d\n", ft_printf("%-4c",0));
//     // ft_printf(" --- Return : %d\n", ft_printf("%5c",0));
//     // ft_printf(" --- Return : %d\n", ft_printf("%3c",0));
//     // ft_printf(" --- Return : %d\n", ft_printf("%-*c",-1, 0));
//     // ft_printf(" --- Return : %d\n", ft_printf("%-*c", 0, 0));
//     // ft_printf(" --- Return : %d\n", ft_printf("%*c", 0, 0));
//     // ft_printf(" --- Return : %d\n", ft_printf("%*c", 0, 0));
//     // printf("\n|%0.d|\n", 0);
//     // printf("\n|%.d|\n", 0);
//     // printf("\n|%10.d|\n", 0);
//     // printf("\n|%10.d|\n", 33);
// }

// int main(void)
// {
//     // printf("|%05c|\n", 'c');
//     // ft_printf("|%05c|\n", 'c');
//     // printf("printf|5*%|",10);
//     ft_printf(" --- Return : %d\n", ft_printf("|%5%|"));
//     ft_printf(" --- Return : %d\n", ft_printf("|%-5%|"));
//     ft_printf(" --- Return : %d\n", ft_printf("|%05%|"));
//     ft_printf(" --- Return : %d\n", ft_printf("|%-05%|"));
//     printf(" --- Return : %d\n", printf("|%5%|"));
//     printf(" --- Return : %d\n", printf("|%-5%|"));
//     printf(" --- Return : %d\n", printf("|%05%|"));
//     printf(" --- Return : %d\n", printf("|%-05%|"));
//     // printf("|%09s|\n", "hi low");
//     // ft_printf("|%09s|\n", "hi low");
//     // printf("|%-09s|\n", "hi low");
//     // ft_printf("|%-09s|\n", "hi low");
//     // printf("|%9s|\n", "hi low");
//     // ft_printf("|%9s|\n", "hi low");
// }

// int main(void)
// {
//     ft_printf("hello|%d|\n", 2147483648);
//     ft_printf("hello|%4.3i|\n", -123);
//     ft_printf("hello|%4.4i|\n", -123); //>?
//     ft_printf("hello|%4.5i|\n", -123);
//     ft_printf("hello|%08.5i|\n", -123); //>?

//     ft_printf("hello|%x|\n", 123);
//     ft_printf("hello|%4.3x|\n", 123);
//     ft_printf("hello|%4.4x|\n", 123);
//     ft_printf("hello|%4.5x|\n", 123);
//     ft_printf("hello|%08.5x|\n", 123);
//     ft_printf("character : |%020c| \n", 'c');
//     ft_printf("character : |%-2c| \n", 'c');
//     ft_printf("character : |%2c| \n", 'c');
//     ft_printf("character : |%*c| \n", 30, 'c');
//     ft_printf("character : |%*c| \n", 30, 'c');
//     ft_printf("character : |%.*c| \n", 30, 'c');
//     ft_printf("character : |%.30c| \n", 'c');
//     ft_printf("character : |%c| \n", 'c');

//   ft_printf("string : |%s| \n", "hello");
//   ft_printf("string : |%-s| \n", "hello");
//   ft_printf("string : |%20s| \n", "hello");
//   ft_printf("string : |%-20s| \n", "hello");
//   ft_printf("string : |%5s| \n", "hello");;
//   ft_printf("string : |%05s| \n", "hello");
//   ft_printf("string : |%6s| \n", "hello");
//   ft_printf("string : |%-6s| \n", "hello");
//   ft_printf("string : |%-6s| \n", "hello");
//   ft_printf("presicion\n");
//   ft_printf("string : |%.3s| \n", "hello");
//   ft_printf("string : |%.3s| \n", "hello1");
//   ft_printf("string : |%.3s| \n", "hello2");
//   ft_printf("string : |%.3s| \n", "hello3");
//   ft_printf("string : |%.3s| \n", "hello");
//   ft_printf("string : |%.3s| \n", "hello");
//   ft_printf("string : |%.3s| \n", "hello");
//   ft_printf("string : |%.3s| \n", "hello");
//   ft_printf("string : |%.5s| \n", "hello");
//   ft_printf("string : |%.6s| \n", "hello");
//   ft_printf("string : |%.20s| \n", "hello");
//   ft_printf("string : |%0.5s| \n", "hello");
//   ft_printf("string : |%0.6s| \n", "hello");
//   ft_printf("string : |%0.20s| \n", "hello");
//   ft_printf("string : |%.3s| \n", "hello");


//   int a = 123;
//   int *ptr1 = &a;
//   ft_printf("pointer addr : %p \n", ptr1);
//   int a = 123;
//   int *ptr1 = &a;
//   ft_printf("pointer addr : |%20p|\n", ptr1);
//   ft_printf("pointer addr : |%-20p|\n", ptr1);
//   ft_printf("pointer addr : |%020p|\n\n", ptr1);


//   printf("pointer addr : |%20p|\n", ptr1);
//   printf("pointer addr : |%-20p|\n", ptr1);
//   printf("pointer addr : |%020p|\n\n", ptr1);

//   ft_printf("pointer addr : |%12p|\n", ptr1);
//   ft_printf("pointer addr : |%-12p|\n", ptr1);
//   ft_printf("pointer addr : |%012p|\n\n", ptr1);

//   printf("pointer addr : |%12p|\n", ptr1);
//   printf("pointer addr : |%-12p|\n", ptr1);
//   printf("pointer addr : |%012p|\n\n", ptr1);

//   ft_printf("pointer addr : |%14p|\n", ptr1);
//   ft_printf("pointer addr : |%-14p|\n", ptr1);
//   ft_printf("pointer addr : |%014p|\n\n", ptr1);

//   printf("pointer addr : |%14p|\n", ptr1);
//   printf("pointer addr : |%-14p|\n", ptr1);
//   printf("pointer addr : |%014p|\n\n", ptr1);

//   ft_printf("pointer addr : |%.15p|\n", ptr1);
//   ft_printf("pointer addr : |%.20p|\n\n", ptr1);

//   printf("pointer addr : |%.15p|\n", ptr1);
//   printf("pointer addr : |%.20p|\n\n", ptr1);




//   return 0;
// }
