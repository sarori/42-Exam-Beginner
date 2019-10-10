/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 01:16:58 by sapark            #+#    #+#             */
/*   Updated: 2019/10/10 01:17:19 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

void	print_memory(const void *addr, size_t size)
{
    size_t  i;
    size_t  j;
    char    *base;
    unsigned char *p;

    i = 0;
    base = "0123456789abcdef";
    p = (unsigned char *)addr;
    while (i < size)
    {
        j = 0;
        while (j < 16 && i + j < size)
        {
            ft_putchar(base[(p[i+j] / 16) % 16]);
            ft_putchar(base[p[i+j] % 16]);   
            j++ %2 ? ft_putchar(' ') : 0;
        }
        while (j < 16)
        {
            ft_putstr("  ");
            j++ %2 ? ft_putchar(' ') : 0;
        }
        j = 0;
        while (j < 16 && i + j < size)
        {
            if (p[i + j] >= 32 && p[i + j] < 127)
                ft_putchar(p[i + j]);
            else
                ft_putchar('.');
            j++;
        }
        ft_putchar('\n');
        i += 16;
    }
}