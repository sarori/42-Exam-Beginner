/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 01:19:55 by sapark            #+#    #+#             */
/*   Updated: 2019/10/10 01:19:59 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
    int i;
    unsigned char bits;

    i = 8;
    while (i--)
    {
        bits = (octet >> i & 1) + '0';
        write(1, &bits, 1);
    }
}
