/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open&proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:36:27 by gzagura           #+#    #+#             */
/*   Updated: 2018/06/20 15:36:29 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_strlen_spec(char *str, t_fdflist *head)
{
	int height;
	int width;
	int i;

	i = 0;
	width = 0;
	height = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		while (str[i] != '\n' && str[i] == ' ')
			i++;
		width++;
		while (str[i] != '\n' && str[i] != ' ')
			i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			height++;
		i++;
	}
	head->height = height ;
	head->width = width ;
}

void	ft_num(t_fdflist *head, int x, int y, int number)
{
	head->curr->z = number;
	head->curr->x = x;
	head->curr->y = y;
	if (head->tmp[0] != '\0')
	{
		head->curr->color = ft_atoi_base(head->tmp, 16);
		ft_bzero(head->tmp, 5);
	}
	else
		head->curr->color = ft_atoi_base("ffffff", 16);
	head->curr = ft_add_new(head->vector);
}

int		ft_space(char *str, int i, char **line)
{
	int		start;
	int		end;

	start = i;
	*line = NULL;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\n')
		i++;
	end = i;
	*line = ft_strsub(str, start, end);
	//remake libft and remake strsub for me, cause this shit hoes wrong! 
	return (end);
}

void	ft_str_nospace(char *str, t_fdflist *head)
{
	char	*num;
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 1;
	x = 1;
	num = NULL;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			i = ft_space(str, i, &num);
			ft_num(head, x, y, ft_getnbr(head, num));
			free(num);
			x++;
		}
		if (str[i] == '\n')
		{
			y++;
			x = 1;
		}
		if (str[i])
			i++;
	}
}

int		ft_write_data(t_fdflist *head)
{
	char	*buffer;
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	head->vector = ft_add_new(NULL);
	head->curr = head->vector;
	fd = open(head->filename, O_RDONLY);
	buffer = NULL;
	tmp = ft_strnew(1);
	while (get_next_line(fd, &buffer) > 0)
	{
		tmp = ft_strjoin(tmp, buffer);
		tmp = ft_strjoin(tmp, "\n");
		free(buffer);
	}
	ft_strlen_spec(tmp, head);
	ft_str_nospace(tmp, head);
	while (head->curr->next && i != (head->width + head->height) / 2)
	{
		head->curr = head->curr->next;
		i++;
	}
	head->cz = head->curr->z;
	return (0);
}
