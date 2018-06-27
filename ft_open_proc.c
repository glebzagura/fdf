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
	int len_y;
	int len_x;
	int i;

	i = 0;
	len_x = 0;
	len_y = 0;
	while (str[i] != '\n')
	{
		while (str[i] != '\n' && str[i] == ' ')
			i++;
		len_x++;
		while (str[i] != '\n' && str[i] != ' ')
			i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			len_y++;
		i++;
	}
	head->len_y = len_y;
	head->len_x = len_x;
}

void	ft_str_nospace(char *str, t_fdflist *head, int **arr_int)
{
	int		i;
	int		j;
	int 	coco;
	char	*lolo;

	arr_int = (int**)malloc(sizeof(int*) * (head->len_y));
	i = 0;
	j = 0;
	coco = 0;
	arr_int[coco] = (int*)malloc(sizeof(int) * (head->len_x));
	coco = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			arr_int[coco] = (int*)malloc(sizeof(int) * (head->len_x));
			coco++:
		}
		if (str[i] != ' ')
		{
			while (str[i] != '\0' && str[i] != ' ')
			{
				arr[coco][j] = str[i];
				j++;
			}
		}
		i++;
	}
	arr_int[j] = NULL;
	return (arr_int);
}

void	ft_workness(char **data, t_fdflist *head)
{
	int i;
	int j;
	int plus;

	i = 0;
	plus = 50;
	while (data[i])
	{
		j = 0;
		while(data[i][j])
		{
			if (data[i][j] != '\0' && data[i][j + 1] != '\0')
			{
				if (data[i][j] > '0')
				{
					head->x0 = 0;
					head->y0 = 0;
				}
				if (data[i][j + 1] > '0')
				{
					head->x1 = ft_atoi(data[i][j]) + plus;
					head->y1 = ft_atoi(data[i][j]) + plus;
				}
				ft_ai(head);
			}
			j++;
		}
		i++;
	}

}

int 	ft_open(t_fdflist *head, char *str)
{
	int 	fd;
	int		**data;
	char	*buffer;
	char	*tmp;
	int 	i;

	i = 0;
	fd = open(str, O_RDONLY);
	buffer = NULL;
	tmp = ft_strnew(1);
	while (get_next_line(fd, &buffer) > 0)
	{
		tmp = ft_strjoin(tmp, buffer);
		tmp = ft_strjoin(tmp, "\n");
		free(buffer);
	}
	ft_strlen_spec(tmp, head);
	tmp = ft_str_nospace(tmp);
	data = 
	ft_workness(data, head);
	return (0);
}
