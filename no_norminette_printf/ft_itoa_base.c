/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihkim <gihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:03:40 by gihkim            #+#    #+#             */
/*   Updated: 2020/03/13 22:03:40 by gihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void          ft_itoa_base(unsigned long nbr, char *base, char *a, size_t *item_len)
// {
//     size_t base_no;

//     base_no = strlen(base);
//     if (nbr < base_no)
//     {
//         if (a)
//         {
//             printf("\na : %p\n",a);
// 		    *(a) = base[nbr];
//         }
//         else
//             (*item_len)++;
//     }
//     else
//     {
//         ft_itoa_base(nbr / base_no, base, a, item_len);
//         if (a)
// 		    a++;
//         ft_itoa_base(nbr % base_no, base, a, item_len);
//     }
// }


void          ft_itoa_base(unsigned long nbr, char *base, char *a, size_t *idx)
{
    size_t base_no;

    base_no = ft_strlen(base);
    if (nbr < base_no)
    {
      if (a)
      {
        a[*idx] = base[nbr%base_no];
        (*idx)++;
      }
      else
        (*idx)++;
    }
    else
    {
      ft_itoa_base(nbr / base_no, base, a, idx);
      if (a)
      {
        a[*idx] = base[nbr%base_no];
        (*idx)++;
      }
      else
        (*idx)++;
    }
}