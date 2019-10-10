/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 01:15:51 by sapark            #+#    #+#             */
/*   Updated: 2019/10/10 01:16:06 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int     count_lst(t_list* lst)
{
    t_list *tmp;
    int     cnt;

    cnt = 0;
    tmp = lst;
    while (tmp)
    {
        cnt++;
        tmp = tmp->next;
    }
    return (cnt);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list  *tmp;
    int     swap;

    int a = count_lst(lst);

    while (a--)
    {
        tmp = lst;
        swap = 0;
        while (tmp->next)
        {
            if (cmp(tmp->data, (tmp->next)->data) == 0)
            {
                swap = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = swap;
            }
            tmp = tmp->next;
        }
    }
    return (lst);
}
