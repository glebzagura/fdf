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
	mlx_string_put(head->mlx, head->wind, 50, 50, COLOR, "THIZ IZ MI FDF, by le gZAGURA");
	if (key == 53)
		ft_esc(head);
	if (key == 125)
		head->rotx = head->rotx + 0.08;
	if (key == 126)
		head->rotx = head->rotx - 0.08;
	if (key == 123)
		head->roty = head->roty + 0.08;
	if (key == 124)
		head->roty = head->roty - 0.08;
	if (key == 24)
		head->kof = head->kof + 0.05;
	if (key == 27)
		head->kof = head->kof - 0.05;
	if (key == 86)
		head->plus_w += 50;
	if (key == 88)
		head->plus_w -= 50;
	if (key == 91)
		head->plus_h += 50;
	if (key == 84)
		head->plus_h -= 50;
	mlx_clear_window (head->mlx, head->wind);
	ft_bresen(head);
	return (0);
}

int 	scale(t_fdflist *head)
{
	if (head->height PY > head->w_height || head->width PX > head->w_width)
	{
		while(head->height PY > (head->w_height * 0.9) || head->width PX > (head->w_width * 0.9))
			head->kof -= 0.05;
	}
	head->plus_h = (head->w_height - (head->height PY)) * 0.5;
	head->plus_w = (head->w_width - (head->width PX)) * 0.5;
 	return (0);
}

int		main(int argc, char **argv)
{
	t_fdflist	*head;

	head = malloc(sizeof(t_fdflist));
	head->filename = ft_strdup(argv[1]);
	head->tmp = ft_strnew(5);
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
 	scale(head);
	mlx_hook(head->wind, 2, 0, le_hook, head);
	mlx_loop(head->mlx);
	return (0);
}