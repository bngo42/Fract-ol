/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:07:18 by bngo              #+#    #+#             */
/*   Updated: 2015/12/07 16:06:22 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n && s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}