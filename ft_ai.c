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

void ft_ai(t_fdflist *head)
{
  // int dx = abs(head->x1 - head->x0);
  // int dy = abs(head->y1 - head->y0);
  // int sx = head->x1 >= head->x0 ? 1 : -1;
  // int sy = head->y1 >= head->y0 ? 1 : -1;
  
  // if (dy <= dx)
  // {
  //   int d = (dy << 1) - dx;
  //   int d1 = dy << 1;
  //   int d2 = (dy - dx) << 1;
  //   mlx_pixel_put(head->mlx, head->wind, head->x0, head->y0, COLOR);
  //   for(int x = head->x0 + sx, y = head->y0, i = 1; i <= dx; i++, x += sx)
  //   {
  //     if ( d >0)
  //     {
  //       d += d2;
  //       y += sy;
  //     }
  //     else
  //       d += d1;
  //     mlx_pixel_put(head->mlx, head->wind, x, y, COLOR);
  //   }
  // }
  // else
  // {
  //   int d = (dx << 1) - dy;
  //   int d1 = dx << 1;
  //   int d2 = (dx - dy) << 1;
  //   mlx_pixel_put(head->mlx, head->wind, head->x0, head->y0, COLOR);
  //   for(int y = head->y0 + sy, x = head->x0, i = 1; i <= dy; i++, y += sy)
  //   {
  //     if ( d >0)
  //     {
  //       d += d2;
  //       x += sx;
  //     }
  //     else
  //       d += d1;
  //     mlx_pixel_put(head->mlx, head->wind, x, y, COLOR);
  //   }
  // }
}