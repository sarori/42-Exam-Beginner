/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:16:02 by sapark            #+#    #+#             */
/*   Updated: 2020/06/26 15:35:17 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//
#include <stdio.h>

char	*ft_itoa_base(int value, int base)
{
    int len;
    long nbr;
    char    *res;
    char    *base_str;

    if (value == 0)
        return ("0");
    len = 0;
    base_str = "0123456789ABCDEF";
    nbr = value;
    while (nbr)
    {
        nbr /= base;
        len++;
    }
    nbr = value;
    if (value < 0)
    {
        if (base == 10)
            len++;
        nbr *= -1;
    }
    if (!(res = (char *)malloc(sizeof(char) * len + 1)))
        return (NULL);
    res[len] = '\0';
    while (nbr)
    {
        res[--len] = base_str[nbr % base];
        nbr /= base;
    }
    if (value < 0 && base == 10)
        res[0] = '-';
    return (res);
}

int main()
{
    printf("%s", ft_itoa_base(255, 16));
    
    return (0);
}