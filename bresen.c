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

void    ft_line(t_fdflist *head, int x0, int y0, int x1, int y1, int  color)
{
  int dx = abs(x1 - x0);
  int dy = abs(y1 - y0);
  int sx = x1 >= x0 ? 1 : -1;
  int sy = y1 >= y0 ? 1 : -1;
  
  if (dy <= dx)
  {
    int d = (dy << 1) - dx;
    int d1 = dy << 1;
    int d2 = (dy - dx) << 1;
    mlx_pixel_put(head->mlx, head->wind, x0, y0, color);
    for(int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx)
    {
      if (d > 0)
      {
        d += d2;
        y += sy;
      }
      else
        d += d1;
      mlx_pixel_put(head->mlx, head->wind, x, y, color);
    }
  }
  else
  {
    int d = (dx << 1) - dy;
    int d1 = dx << 1;
    int d2 = (dx - dy) << 1;
    mlx_pixel_put(head->mlx, head->wind, x0, y0, color);
    for(int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy)
    {
      if (d > 0)
      {
        d += d2;
        x += sx;
      }
      else
        d += d1;
      mlx_pixel_put(head->mlx, head->wind, x, y, color);
    }
  }
}

int    *transform(t_fdflist *head, t_vector *eddo)
{
  int x0;
  int x1;
  int x2;
  int y0;
  int y1;
  int y2;
  int z0;
  int z1;
  int *arr;

 
  x0 = eddo->x;
  y0 = ((eddo->y - head->height / 2) PY) * cos(head->rotx) + ((eddo->z - head->cz) PZ) * sin(head->rotx) + (head->height / 2) PY + head->plus_h;
  z0 = ((eddo->z - head->cz) PZ) * cos(head->rotx) - ((eddo->y - head->height / 2) PY) * sin(head->rotx) + head->cz PZ;

  x1 = ((x0 - head->width / 2) PX) * cos(head->roty) - (z0 - head->cz) * sin(head->roty) + (head->width / 2) PX + head->plus_w;
  y1 = y0;
  z1 = (z0 - head->cz) * cos(head->roty) + (x0 - head->width / 2) * sin(head->roty) + head->cz;

  x2 = (x1 - head->width / 2) * cos(head->rotz) + (y1 - head->height / 2) * sin(head->rotz) + head->width / 2;
  y2 = (y1 - head->height / 2) * cos(head->rotz) - (x1 - head->width / 2) * sin(head->rotz) + head->height / 2;

  arr = malloc(sizeof((int*)2));
  arr[0] = x2;
  arr[1] = y2;
  return (arr);
}

void    brain(t_fdflist *head, t_vector *eddo, t_vector *hedo)
{
  int *arr;
  int *arr1;

  arr = transform(head, eddo);
  arr1 = transform(head, hedo);
  ft_line(head, arr[0], arr[1], arr1[0], arr1[1], hedo->color);
}












