/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:39:48 by gzagura           #+#    #+#             */
/*   Updated: 2018/06/19 18:39:50 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define COLOR 0x00d8ff

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct 			s_fdflist
{
	void 				*wind;
	void 				*mlx;
	int					len_y:
	int					len_x:
	int					x0;
	int					y0;
	int					x1;
	int					y1;
	int					z0;
	int					z1;
	struct s_fdflist 	*next;
}						t_fdflist;

int 	ft_open(t_fdflist *head, char *str);
int		get_next_line(const int fd, char **line);
void 	ft_ai(t_fdflist *head);
#endif