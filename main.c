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

int 	le_hook(int key, t_fdflist *head)
{
	int i = 0;
	int j = 0;
	int x = 250;
	int y = 250;

	mlx_string_put(head->mlx, head->wind, 50, 50, COLOR, "Hello");
	if (key == 53)
		ft_esc(head);
	// if (key == 123)
	// 	ft_rotation_left(head);
	return (0);
}

// void	first_draw(t_fdflist *head)
// {
// 	ft_bresen(head);
// }

void	ft_bresen(t_fdflist *head)
{
	t_vector *hedo;
	t_vector *eddo;

	hedo = VEC;
	while (hedo->next)
	{
		eddo = hedo->next;
		while (eddo)
		{
			if (eddo->x == hedo->x)
				ft_line(head, hedo->x, hedo->y, eddo->x, eddo->y);
			eddo = eddo->next;
		}
		hedo = hedo->next;
	}
	hedo = VEC;
	while (hedo->next)
	{
		if (hedo->next->next && hedo->x != (head->width - 1))
			ft_line(head, hedo->x, hedo->y, hedo->next->x, hedo->next->y);
		hedo = hedo->next;
	}
}

int		main(int argc, char **argv)
{
	t_fdflist	*head;

	head = malloc(sizeof(t_fdflist));
	head->filename = ft_strdup(argv[1]);
	ft_write_data(head);
	if (!(head->mlx = mlx_init()))
		return (0);
	head->wind = mlx_new_window(head->mlx, 1000, 1000, "gzagura");
	ft_bresen(head);
	mlx_hook(head->wind, 2, 0, le_hook, head);
	mlx_loop(head->mlx);
	return (0);
}