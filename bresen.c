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

void    drawLine()
{
    int dx;
    int dy;
    int sx;
    int sy;



// if (rgb != color)
//     {
//        if (hedo->r > r)
//           r = r + 1;
//       if (hedo->g > g)
//           g = g + 1;
//       if (hedo->b > b)
//           b = b + 1;
//       if (hedo->r < r && r > 1)
//           r = r - 1;
//       if (hedo->g < g && g > 1)
//           g = g - 1;
//       if (hedo->b < b && b > 1)
//           b = b - 1;
//         printf("r = %f g = %f b = %f\n", r , g ,b);
//       rgb = (int)r * 1000000 + (int)g * 1000 + (int)b;
//     }
   
}

void    ft_line(t_fdflist *head, int *arr, int  color, int rgb, t_vector *eddo, t_vector *hedo)
{
  int dx = abs(arr[2] - arr[0]);
  int dy = abs(arr[3] - arr[1]);
  int sx = arr[2] >= arr[0] ? 1 : -1;
  int sy = arr[3] >= arr[1] ? 1 : -1;

int r = eddo->r;
int g = eddo->g;
int b = eddo->b;
  if (dy <= dx)
  {
    int d = (dy << 1) - dx;
    int d1 = dy << 1;
    int d2 = (dy - dx) << 1;
    mlx_pixel_put(head->mlx, head->wind, arr[0], arr[1], rgb);
    for(int x = arr[0] + sx, y = arr[1], i = 1; i <= dx; i++, x += sx)
    {
      if (d > 0)
      {
        d += d2;
        y += sy;
      }
      else
        d += d1;
      if (hedo->r > r)
          r = r + 1;
      if (hedo->g > g)
          g = g + 1;
      if (hedo->b > b)
          b = b + 1;
      if (hedo->r < r && r > 0)
          r = r - 1;
      if (hedo->g < g && g > 0)
          g = g - 1;
      if (hedo->b < b && b > 0)
          b = b - 1;
      if (color != rgb)
      {
        rgb = 0;
        rgb += (r & 255) << 16;
        rgb += (g & 255) << 8;
        rgb += (b & 255);
      }
      mlx_pixel_put(head->mlx, head->wind, x, y, rgb);
    }
  }
  else
  {
    int d = (dx << 1) - dy;
    int d1 = dx << 1;
    int d2 = (dx - dy) << 1;
    mlx_pixel_put(head->mlx, head->wind, arr[0], arr[1], rgb);
    for(int y = arr[1] + sy, x = arr[0], i = 1; i <= dy; i++, y += sy)
    {
      if (d > 0)
      {
        d += d2;
        x += sx;
      }
      else
        d += d1;
      if (hedo->r > r)
          r = r + 1;
      if (hedo->g > g)
          g = g + 1;
      if (hedo->b > b)
          b = b + 1;
      if (hedo->r < r && r > 0)
          r = r - 5;
      if (hedo->g < g && g > 0)
          g = g - 5;
      if (hedo->b < b && b > 0)
          b = b - 5;
      if (color != rgb)
      {
        rgb = 0;
        rgb += (r & 255) << 16;
        rgb += (g & 255) << 8;
        rgb += (b & 255);
      }
      mlx_pixel_put(head->mlx, head->wind, x, y, rgb);
    }
  }
}


// int    *transform(t_fdflist *head, t_vector *eddo, t_vector *hedo)
// {
//   int x1;
//   int y0;
//   int z0;
//   int z1;
//   int *arr;

//   arr = malloc(sizeof((int*)4));
//   y0 = ((eddo->y - head->height / 2) PY) * cos(head->rotx) + ((eddo->z - head->cz) PZ) * sin(head->rotx) + (head->height / 2) PY + head->plus_h;
//   z0 = ((eddo->z - head->cz) PZ) * cos(head->rotx) - ((eddo->y - head->height / 2) PY) * sin(head->rotx) + head->cz PZ;
//   x1 = ((eddo->x - head->width / 2) PX) * cos(head->roty) - (z0 - head->cz) * sin(head->roty) + (head->width / 2) PX + head->plus_w;
//   z1 = (z0 - head->cz) * cos(head->roty) + (eddo->x - head->width / 2) * sin(head->roty) + head->cz;
//   arr[0] = (x1 - head->width / 2) * cos(head->rotz) + (y0 - head->height / 2) * sin(head->rotz) + head->width / 2;
//   arr[1] = (y0 - head->height / 2) * cos(head->rotz) - (x1 - head->width / 2) * sin(head->rotz) + head->height / 2;
//   y0 = ((hedo->y - head->height / 2) PY) * cos(head->rotx) + ((hedo->z - head->cz) PZ) * sin(head->rotx) + (head->height / 2) PY + head->plus_h;
//   z0 = ((hedo->z - head->cz) PZ) * cos(head->rotx) - ((hedo->y - head->height / 2) PY) * sin(head->rotx) + head->cz PZ;
//   x1 = ((hedo->x - head->width / 2) PX) * cos(head->roty) - (z0 - head->cz) * sin(head->roty) + (head->width / 2) PX + head->plus_w;
//   z1 = (z0 - head->cz) * cos(head->roty) + (hedo->x - head->width / 2) * sin(head->roty) + head->cz;
//   arr[2] = (x1 - head->width / 2) * cos(head->rotz) + (y0 - head->height / 2) * sin(head->rotz) + head->width / 2;
//   arr[3] = (y0 - head->height / 2) * cos(head->rotz) - (x1 - head->width / 2) * sin(head->rotz) + head->height / 2;
//   return (arr);
// }



void    color_brain(t_fdflist *head, t_vector *eddo, t_vector *hedo)
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

  // arr = transform(head, eddo, hedo);
  ft_line(head, arr, eddo->color, hedo->color, eddo, hedo);
  free(arr);
}



void    ft_color_bresen(t_fdflist *head)
{
    t_vector *hedo;
    t_vector *eddo;

    hedo = VEC;
    while (hedo->next)
    {
        if (hedo->next->next && hedo->x != (head->width))
            color_brain(head, hedo, hedo->next);
        eddo = hedo->next;
        while (eddo)
        {
            if (eddo->x == hedo->x)
            {
                color_brain(head, hedo, eddo);
                break ;
            }
            eddo = eddo->next;
        }
        hedo = hedo->next;
    }
}










