/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 01:21:38 by sapark            #+#    #+#             */
/*   Updated: 2019/10/10 01:24:59 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    lcm(unsigned int a, unsigned int b)
{
    if (!a || !b)
        return (0);
    int r_a;
    int r_b;
    int hcf;
    unsigned int    lcm;

    r_a = a;
    r_b = b;
    hcf = 1;
    lcm = 0;
    if (r_a >= r_b)
    {
        while (r_b >= 1)
        {
            if (a % r_b == 0 && b % r_b == 0)
            {
                hcf = r_b;
                break;
            }
            r_b--;
        }
    }
    else
    {
        while (r_a >= 1)
        {
            if (a % r_a == 0 && b % r_a == 0)
            {
                hcf = r_a;
                break;
            }
            r_a--;
        }
    }
    lcm = a * b / hcf;
    return (lcm);
}
