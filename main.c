/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:39:48 by gzagura           #+#    #+#             */
/*   Updated: 2018/06/19 18:39:50 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_esc(t_fdflist *head)
{
	mlx_destroy_window(head->mlx, head->wind);
	write(1, "Bye-Bye\n", 8);
	exit(1);
}

int 	ft_z_work(t_fdflist *head)
{
	return (0);
}

void	ft_draw_square(t_fdflist *head, int x, int y)
{
	int i = 0;

	while (i < 100)
	{
		if (i < 50)
		{
			mlx_pixel_put(head->mlx, head->wind, x, y, 0xff00fa);
			y = y + 1;
		}
		else
		{
			mlx_pixel_put(head->mlx, head->wind, x, y, 0x00d8ff);
			x = x + 1;
		}
		i++;
	}
	i = 0;
	while (i < 100)
	{
		if (i < 50)
		{
			mlx_pixel_put(head->mlx, head->wind, x, y, 0xff00fa);
			y = y - 1;
		}
		else
		{
			mlx_pixel_put(head->mlx, head->wind, x, y, 0x00d8ff);
			x = x - 1;
		}
		i++;
	}
}

int 	ft_work(int key, t_fdflist *head)
{
	int i = 0;
	int j = 0;
	int x = 250;
	int y = 250;

	if (key == 53)
		ft_esc(head);
	while (i++ < 10)
	{
		ft_draw_square(head, x, y);
		while (j++ < 10)
		{
			ft_draw_square(head, x, y);
			x = x + 50;
		}
		x = 250;
		y = y + 50;
		j = 0;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdflist	*head;

	head = malloc(sizeof(t_fdflist));

	if (!(head->mlx = mlx_init()))
		return (0);
	head->wind = mlx_new_window(head->mlx, 1000, 1000, "gzagura");
	mlx_pixel_put(head->mlx, head->wind, 244, 66, 0xf44242);
	mlx_hook(head->wind, 2, 0, ft_work, head);
	mlx_loop(head->mlx);
	return (0);
}