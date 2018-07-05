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

void    ft_line(t_fdflist *head, int x0, int y0, int x1, int y1)
{
  x0 = x0 PX;
  x1 = x1 PX;
  y0 = y0 PY;
  y1 = y1 PY;
  int dx = abs(x1 - x0);
  int dy = abs(y1 - y0);
  int sx = x1 >= x0 ? 1 : -1;
  int sy = y1 >= y0 ? 1 : -1;
  
  if (dy <= dx)
  {
    int d = (dy << 1) - dx;
    int d1 = dy << 1;
    int d2 = (dy - dx) << 1;
    mlx_pixel_put(head->mlx, head->wind, x0, y0, COLOR);
    for(int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx)
    {
      if (d > 0)
      {
        d += d2;
        y += sy;
      }
      else
        d += d1;
      mlx_pixel_put(head->mlx, head->wind, x, y, COLOR);
    }
  }
  else
  {
    int d = (dx << 1) - dy;
    int d1 = dx << 1;
    int d2 = (dx - dy) << 1;
    mlx_pixel_put(head->mlx, head->wind, x0, y0, COLOR);
    for(int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy)
    {
      if (d > 0)
      {
        d += d2;
        x += sx;
      }
      else
        d += d1;
      mlx_pixel_put(head->mlx, head->wind, x, y, COLOR);
    }
  }
}
