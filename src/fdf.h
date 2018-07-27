/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:39:48 by gzagura           #+#    #+#             */
/*   Updated: 2018/07/28 00:11:27 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define COLOR	0xff006e
# define PX		* (30 * head->kof)
# define PY		* (30 * head->kof)
# define PZ		* (30 * head->kof)
# define VEC head->vector
# define MLX    head->mlx
# define WIN    head->wind

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct			s_vector
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

typedef struct			s_fdflist
{
	int					x;
	int					y;
	int					d1;
	int					d2;
	int					sx;
	int					sy;
	void				*wind;
	void				*mlx;
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

void					ft_rgb(t_fdflist *head, t_vector *eddo, t_vector *hedo);
void					ft_line1(t_fdflist *head,
	int *arr, t_vector *eddo, t_vector *hedo);
void					ft_line2(t_fdflist *head,
	int *arr, t_vector *eddo, t_vector *hedo);
void					drawlala(t_fdflist *head,
	int *arr, t_vector *eddo, t_vector *hedo);
void					brain(t_fdflist *head, t_vector *eddo, t_vector *hedo);
int						convert_and_check_nb(char c, int base);
int						length_number(char *str, int base);
int						ft_atoi_base(char *nb, int base);
void					ft_draw_net(t_fdflist *head);
void					ft_esc(t_fdflist *head);
int						ft_getnbr(t_fdflist *head, char *str);
int						magic(t_fdflist *head, char *str, int *i, int j);
char					*ft_special(char *dst, char *src, int len);
void					ft_strlen_spec(char *str, t_fdflist *head);
void					ft_num(t_fdflist *head, int x, int y, int number);
int						ft_space(char *str, int i, char **line);
void					ft_str_nospace(char *str, t_fdflist *head);
int						ft_write_data(t_fdflist *head);
char					*ft_strwork(char const *s,
	unsigned int start, size_t len);
t_vector				*ft_add_new(t_vector *head);
void					hello_hook(t_fdflist *head, int key);
int						le_hook(int key, t_fdflist *head);
void					tips(t_fdflist *head);
int						scale(t_fdflist *head);
int						main(int argc, char **argv);

#endif
