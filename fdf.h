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
# define RAD	0.001

# include "minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct 			s_vector
{
	int					x;
	int					y;
	int					z;
	struct s_vector		*next;
}						t_vector;

typedef struct 			s_fdflist
{
	void 				*wind;
	void 				*mlx;
	char				*filename;
	int					**data;
	int					height;
	int					width;
	int					w_height;
	int					w_width;
	int					gap;
	t_vector			*vector;
	t_vector			*curr;
	struct s_fdflist 	*next;
}						t_fdflist;

int 	ft_write_data(t_fdflist *head);
int		get_next_line(const int fd, char **line);
int		ft_getnbr(char *str);
void 	ft_ai(t_fdflist *head);
t_vector	*ft_add_new(t_vector *head);
#endif