/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:35:08 by sapark            #+#    #+#             */
/*   Updated: 2020/06/26 15:00:00 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char    *update(char *src, int way)
{
    int s;

    s = 0;
    while (1)
    {
        if (*src == '[')
            s++;
        else if (*src == ']')
            s--;
        if (s == 0)
            return (src);
        src += way;
    }
    return (NULL);
}

void    brainfuck(char *src, char *buf)
{
    while (*src != '\0')
    {
        if (*src == '>')
            buf++;
        else if (*src == '<')
            buf--;
        else if (*src == '+')
            (*buf)++;
        else if (*src == '-')
            (*buf)--;
        else if (*src == '.')
            write(1, buf, 1);
        else if (*src == '[' && !(*buf))
            src = update(src, 1);
        else if (*src == ']' && (*buf))
            src = update(src, -1);
        src++;
    }
}

int main(int ac, char *av[])
{
    char    buf[2048];
    int i;
    if (ac > 1)
    {
        i = 0;
        while (i < 2048)
            buf[i++] = 0;
        brainfuck(av[1], buf);
    }
    else
        write(1, "\n", 1);
    return (0);
}