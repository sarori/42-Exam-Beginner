/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:07:57 by sapark            #+#    #+#             */
/*   Updated: 2020/06/26 14:27:17 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int open_bracket(char c)
{
    return (c == '(' || c == '{' || c == '[');
}

int close_bracket(char c)
{
    return (c == ')' || c == '}' || c == ']');
}

int valid_pair(char open, char close)
{
    if (open == '(' && close == ')')
        return (1);
    else if (open == '{' && close == '}')
        return (1);
    else if (open == '[' && close == ']')
        return (1);
    return (0);
}


int ft_brackets(char *str)
{
    int i;
    int o_i;
    int is_open;

    i = 0;
    o_i = 0;
    is_open = 0;
    while (str[i])
    {
        if (open_bracket(str[i]))
        {
            o_i = i;
            is_open = 1;
        }
        if (close_bracket(str[i]) && valid_pair(str[o_i], str[i]))
        {
            str[o_i] = '0';
            str[i] = '0';
            i = 0;
            o_i = 0;
            is_open = 0;
        }
        if (close_bracket(str[i]) && !valid_pair(str[o_i], str[i]))
            return (0);
        i++;
    }
    return (is_open ? 0 : 1);
}

int main (int ac, char *av[])
{
    if (ac >= 2)
    {
        while (*++av)
        {
            if (ft_brackets(*av))
                write(1, "OK\n", 3);
            else
                write(1, "Error\n", 6);
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}