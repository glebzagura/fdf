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

void	ft_bresen(t_fdflist *head)
{
	t_vector *hedo;
	t_vector *eddo;

	hedo = VEC;
	while (hedo->next)
	{
		if (hedo->next->next && hedo->x != (head->width))
			brain(head, hedo, hedo->next);
		eddo = hedo->next;
		while (eddo)
		{
			if (eddo->x == hedo->x)
			{
				brain(head, hedo, eddo);
				break ;
			}
			eddo = eddo->next;
		}
		hedo = hedo->next;
	}
}

int 	le_hook(int key, t_fdflist *head)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 250;

	mlx_string_put(head->mlx, head->wind, 50, 50, COLOR, "Hello");
	if (key == 53)
		ft_esc(head);
	if (key == 125)
	{
		mlx_clear_window (head->mlx, head->wind);
		head->rotx = head->rotx + 0.08;
		ft_bresen(head);
	}
	if (key == 126)
	{
		mlx_clear_window (head->mlx, head->wind);
		head->rotx = head->rotx - 0.08;
		ft_bresen(head);
	}
	if (key == 123)
	{
		mlx_clear_window (head->mlx, head->wind);
		head->roty = head->roty + 0.08;
		ft_bresen(head);
	}
	if (key == 124)
	{
		mlx_clear_window (head->mlx, head->wind);
		head->roty = head->roty - 0.08;
		ft_bresen(head);
	}
	if (key == 24)
	{
		mlx_clear_window (head->mlx, head->wind);
		head->kof = head->kof + 0.1;
		ft_bresen(head);
	}
	if ( key == 27)
	{
		mlx_clear_window (head->mlx, head->wind);
		head->kof = head->kof - 0.1;
		ft_bresen(head);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdflist	*head;

	head = malloc(sizeof(t_fdflist));
	head->filename = ft_strdup(argv[1]);
	ft_write_data(head);
	if (!(head->mlx = mlx_init()))
		return (0);
	head->w_width = 1440;
	head->w_height = 1080;
	head->wind = mlx_new_window(head->mlx, 1440, 1080, "gzagura");
	head->roty = 0.3;
 	head->rotz = 0;
 	head->rotx = -0.3;
 	head->kof = 1;
 	head->plus_h = (head->w_height - (head->height PY)) * 0.5;
 	head->plus_w = (head->w_width - (head->width PX)) * 0.5;
	mlx_hook(head->wind, 2, 0, le_hook, head);
	mlx_loop(head->mlx);
	return (0);
}