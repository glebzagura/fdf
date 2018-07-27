/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:31:51 by gzagura           #+#    #+#             */
/*   Updated: 2018/06/28 15:31:53 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_net(t_fdflist *head)
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
				brain(head, eddo, hedo);
				break ;
			}
			eddo = eddo->next;
		}
		hedo = hedo->next;
	}
}

void	ft_esc(t_fdflist *head)
{
	mlx_destroy_window(head->mlx, head->wind);
	write(1, "Bye-Bye\n", 8);
	exit(1);
}
