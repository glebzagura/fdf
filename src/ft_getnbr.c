/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:01:26 by gzagura           #+#    #+#             */
/*   Updated: 2018/06/27 15:01:29 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_getnbr(t_fdflist *head, char *str)
{
	int		i;
	int		j;
	int		result;

	result = 0;
	i = 0;
	j = 6;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' && str[i + 1] != '\0' && str[i + 1] == '0')
		j = magic(head, str, &i, j);
	if (j < 6)
	{
		head->tmp = ft_special(head->tmp, &str[i - j + 3], j - 1);
	}
	if (str[0] == '-')
		result = result * (-1);
	return (result);
}

int		magic(t_fdflist *head, char *str, int *i, int j)
{
	if (str[*i + 2] != '\0' && str[*i + 2] == 'x')
	{
		j = 0;
		while (str[*i + 2] != '\0')
		{
			head->tmp[j] = str[*i + 3];
			j++;
			(*i)++;
		}
	}
	return (j);
}

char	*ft_special(char *dst, char *src, int len)
{
	char	*new;
	int		i;
	int		j;
	int		tru;

	new = ft_strnew(6);
	i = 0;
	tru = 6 - len;
	while (tru)
	{
		new[i] = '0';
		i++;
		tru--;
	}
	j = 0;
	while (src[j] != '\0')
	{
		new[i] = src[j];
		j++;
		i++;
	}
	free(dst);
	return (new);
}
