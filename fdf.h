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

# define COLOR	0xff006e
# define PX		* (30 * head->kof)
# define PY		* (30 * head->kof)
# define PZ		* (30 * head->kof)
# define VEC head->vector

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
	int					color;
	struct s_vector		*next;
}						t_vector;

typedef struct 			s_fdflist
{
	void 				*wind;
	void 				*mlx;
	char				*filename;
	char				*tmp;
	int					height;
	int					width;
	int					w_width;
	int					w_height;
	int					cz;
	float				plus_h;
	float				plus_w;
	float				rotx;
	float				roty;
	float				rotz;
	float				kof;
	t_vector			*vector;
	t_vector			*curr;
	struct s_fdflist 	*next;
}						t_fdflist;

int 	ft_write_data(t_fdflist *head);
int		get_next_line(const int fd, char **line);
int		ft_getnbr(t_fdflist *head, char *str);
void 	ft_ai(t_fdflist *head);
void    brain(t_fdflist *head ,t_vector *eddo, t_vector *hedo);
t_vector	*ft_add_new(t_vector *head);
int			ft_atoi_base(char *nb, int base);
#endif