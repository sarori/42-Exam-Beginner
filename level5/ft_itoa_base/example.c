/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:02:33 by sapark            #+#    #+#             */
/*   Updated: 2020/06/26 15:45:35 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t	i;
	size_t	j;
	char	*base;
	unsigned char	*p;

	i = 0;
	base = "0123456789abcdef";
	p = (unsigned char *)addr;
	while (i < size)
	{
		j = 0;
		while (j < 16 && i + j < size)
		{
			ft_putchar(base[(p[i + j] / 16) % 16]);
			ft_putchar(base[p[i + j] % 16]);
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

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}