/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:36:43 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/31 14:50:30 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*duplicate;
	int		len;

	len = ft_strlen(src);
	duplicate = (char *)malloc(sizeof(char) * (len + 1));
	if (!duplicate)
		return (0);
	ft_strlcpy(duplicate, src, len + 1);
	return (duplicate);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = malloc(sizeof(char) * (s1_len + s2_len + 1));

	ft_strlcpy(join, s1, s1_len + 1);
	ft_strlcpy(join + s1_len, s2, s2_len + 1);
	return (join);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(src);
	if (len > dstsize && (int) dstsize > 0)
		len = dstsize - 1;
	dest[len] = '\0';
	while (len-- > 0)
		*dest++ = *src++;
	return (len);
}