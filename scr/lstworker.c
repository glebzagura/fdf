/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstworker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:51:07 by gzagura           #+#    #+#             */
/*   Updated: 2018/06/19 18:51:09 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	*ft_add_new(t_vector *head)
{
	t_vector *new;

	new = (t_vector *)malloc(sizeof(t_vector));
	new->next = NULL;
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
	return (new);
}
