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

int 	ft_work(int key, t_fdflist *head)
{
	int i = 800;
	int x = 0;
	int y = 0;

	if (key == 53)
		ft_esc(head);
	while (i--)
	{
		mlx_pixel_put(head->mlx, head->wind, x, y, 0x2f442);
		y = y + 1;
		x = x + 1;
	}
	while (i < 900)
	{
		if (i < 500)
		{
			mlx_pixel_put(head->mlx, head->wind, x, y, 0xff00fa);
			y = y - 1;
			x = x - 1;
		}
		else
		{
			mlx_pixel_put(head->mlx, head->wind, x, y, 0x00d8ff);
			x = x + 1;
		}
		i++;
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