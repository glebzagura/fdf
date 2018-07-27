/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ai.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 18:08:24 by gzagura           #+#    #+#             */
/*   Updated: 2018/06/21 18:08:25 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rgb(t_fdflist *head, t_vector *eddo, t_vector *hedo)
{
	if (hedo->r > head->r)
		head->r = head->r + 2;
	if (hedo->g > head->g)
		head->g = head->g + 2;
	if (hedo->b > head->b)
		head->b = head->b + 2;
	if (hedo->r < head->r && head->r > 2)
		head->r = head->r - 2;
	if (hedo->g < head->g && head->g > 2)
		head->g = head->g - 2;
	if (hedo->b < head->b && head->b > 2)
		head->b = head->b - 2;
	if (eddo->color != hedo->color)
	{
		head->rgb = 0;
		head->rgb += (head->r & 255) << 16;
		head->rgb += (head->g & 255) << 8;
		head->rgb += (head->b & 255);
	}
}
void	ft_line1(t_fdflist *head, int *arr, t_vector *eddo, t_vector *hedo)
{
	int i;
	int d;

	head->sx = arr[2] >= arr[0] ? 1 : -1;
	head->sy = arr[3] >= arr[1] ? 1 : -1;
	d = (abs(arr[3] - arr[1]) << 1) - abs(arr[2] - arr[0]);
	head->d1 = abs(arr[3] - arr[1]) << 1;
	head->d2 = (abs(arr[3] - arr[1]) - abs(arr[2] - arr[0])) << 1;
	mlx_pixel_put(head->mlx, head->wind, arr[0], arr[1], eddo->color);
	head->x = arr[0] + head->sx;
	head->y = arr[1];
	i = 0;
	while (++i <= abs(arr[2] - arr[0]))
	{
		if (d > 0)
		{
			d += head->d2;
			head->y += head->sy;
		}
		else
			d += head->d1;
		ft_rgb(head, eddo, hedo);
		mlx_pixel_put(head->mlx, head->wind, head->x, head->y, head->rgb);
		head->x += head->sx;
	}
}

void	ft_line2(t_fdflist *head, int *arr, t_vector *eddo, t_vector *hedo)
{
	int i;
	int d;

	head->sx = arr[2] >= arr[0] ? 1 : -1;
	head->sy = arr[3] >= arr[1] ? 1 : -1;
	d = (abs(arr[2] - arr[0]) << 1) - abs(arr[3] - arr[1]);
	head->d1 = abs(arr[2] - arr[0]) << 1;
	head->d2 = (abs(arr[2] - arr[0]) - abs(arr[3] - arr[1])) << 1;
	mlx_pixel_put(head->mlx, head->wind, arr[0], arr[1], eddo->color);
	head->x = arr[0];
	head->y = arr[1] + head->sy;
	i = 0;
	while (++i <= abs(arr[3] - arr[1]))
	{
		if (d > 0)
		{
			d += head->d2;
			head->x += head->sx;
		}
		else
			d += head->d1;
		ft_rgb(head, eddo, hedo);
		mlx_pixel_put(head->mlx, head->wind, head->x, head->y, head->rgb);
		head->y += head->sy;
	}
}



void	drawlala(t_fdflist *head, int *arr, t_vector *eddo, t_vector *hedo)
{
	int dx;
	int dy;
	int sx;
	int sy;

	dx = abs(arr[2] - arr[0]);
	dy = abs(arr[3] - arr[1]);
	sx = arr[2] >= arr[0] ? 1 : -1;
	sy = arr[3] >= arr[1] ? 1 : -1;
	head->r = eddo->r;
 	head->g = eddo->g;
	head->b = eddo->b;
	head->rgb = hedo->color;
	if (dy <= dx)
		ft_line1(head, arr, eddo, hedo);
	else
		ft_line2(head, arr, eddo, hedo);
}

void    brain(t_fdflist *head, t_vector *eddo, t_vector *hedo)
{
	int x1;
	int y0;
	int z0;
	int z1;
	int *arr;

	arr = malloc(sizeof((int*)4));
	y0 = ((eddo->y - head->height / 2) PY) * cos(head->rotx) + ((eddo->z - head->cz) PZ) * sin(head->rotx) + (head->height / 2) PY + head->plus_h;
	z0 = ((eddo->z - head->cz) PZ) * cos(head->rotx) - ((eddo->y - head->height / 2) PY) * sin(head->rotx) + head->cz PZ;
	x1 = ((eddo->x - head->width / 2) PX) * cos(head->roty) - (z0 - head->cz) * sin(head->roty) + (head->width / 2) PX + head->plus_w;
	z1 = (z0 - head->cz) * cos(head->roty) + (eddo->x - head->width / 2) * sin(head->roty) + head->cz;
	arr[0] = (x1 - head->width / 2) * cos(head->rotz) + (y0 - head->height / 2) * sin(head->rotz) + head->width / 2;
	arr[1] = (y0 - head->height / 2) * cos(head->rotz) - (x1 - head->width / 2) * sin(head->rotz) + head->height / 2;
	y0 = ((hedo->y - head->height / 2) PY) * cos(head->rotx) + ((hedo->z - head->cz) PZ) * sin(head->rotx) + (head->height / 2) PY + head->plus_h;
	z0 = ((hedo->z - head->cz) PZ) * cos(head->rotx) - ((hedo->y - head->height / 2) PY) * sin(head->rotx) + head->cz PZ;
	x1 = ((hedo->x - head->width / 2) PX) * cos(head->roty) - (z0 - head->cz) * sin(head->roty) + (head->width / 2) PX + head->plus_w;
	z1 = (z0 - head->cz) * cos(head->roty) + (hedo->x - head->width / 2) * sin(head->roty) + head->cz;
	arr[2] = (x1 - head->width / 2) * cos(head->rotz) + (y0 - head->height / 2) * sin(head->rotz) + head->width / 2;
	arr[3] = (y0 - head->height / 2) * cos(head->rotz) - (x1 - head->width / 2) * sin(head->rotz) + head->height / 2;
	drawlala(head, arr, eddo, hedo);
	free(arr);
}

void    ft_draw_net(t_fdflist *head)
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
