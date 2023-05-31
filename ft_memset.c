/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:05:55 by luchitel          #+#    #+#             */
/*   Updated: 2023/03/03 12:28:19 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = b;
	while (len-- > 0)
	{
		*str++ = c;
	}
	return (b);
}
