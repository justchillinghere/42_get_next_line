/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:46:26 by luchitel          #+#    #+#             */
/*   Updated: 2023/03/05 21:27:56 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Like memset, but for strings
*/
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ch;
	unsigned const char	*cch;

	ch = dst;
	cch = src;
	while (n-- > 0)
		*ch++ = *cch++;
	return (dst);
}
