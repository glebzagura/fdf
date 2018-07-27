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

typedef struct 			s_vector
{
	int					x;
	int					y;
	int					z;
	int					r;
	int					g;
	int					b;
	int					color;
	struct s_vector		*next;
}						t_vector;

typedef struct 			s_fdflist
{
	int					x;
	int					y;
	int					d1;
	int					d2;
	int					sx;
	int					sy;
	void 				*wind;
	void 				*mlx;
	int					cz;
	int					r;
	int					g;
	int					b;
	int					rgb;
	float				plus_h;
	float				plus_w;
	float				rotx;
	float				roty;
	float				rotz;
	float				kof;
	t_vector			*vector;
	t_vector			*curr;
	int					height;
	int					width;
	int					w_width;
	int					w_height;
	char				*tmp;
	char				*filename;
}						t_fdflist;

int 		ft_write_data(t_fdflist *head);
int			magic(t_fdflist *head, char *str, int *i, int j);
void		tips(t_fdflist *head);
int			get_next_line(const int fd, char **line);
int			ft_getnbr(t_fdflist *head, char *str);
char		*ft_strwork(char const *s, unsigned int start, size_t len);
void 		ft_ai(t_fdflist *head);
void		drawlala(t_fdflist *head, int *arr, t_vector *eddo, t_vector *hedo);
char		*ft_special(char *dst, char *src, int len);
void    	brain(t_fdflist *head ,t_vector *eddo, t_vector *hedo);
t_vector	*ft_add_new(t_vector *head);
int			ft_atoi_base(char *nb, int base);
void    	ft_draw_net(t_fdflist *head);
#endif