/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:30:49 by luchitel          #+#    #+#             */
/*   Updated: 2023/06/02 15:40:07 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *read_till_nl_found(int fd, char *stash, t_read_status *string_data)
{
	char *buf;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	string_data->read_bytes = 1;
	while (string_data->read_bytes != 0 && !(string_data->new_line_pointer))
	{
		string_data->read_bytes = read(fd, buf, BUFFER_SIZE);
		if (string_data->read_bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[string_data->read_bytes] = '\0';
		stash = ft_strjoin(stash, buf);
		string_data->new_line_pointer = ft_strchr(stash, '\n');
	}
	free(buf);
	return (stash);	
}

char *get_line(char *stash)
{
	char *line;
	int	i;
	
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	ft_strlcpy(line, stash, i + 2);
	return (line);
}

char *update_stash(char* stash, t_read_status *string_data)
{
	char 	*new_stash;

	new_stash = NULL;
	if (string_data->new_line_pointer && (ft_strlen(string_data->new_line_pointer) - 1 > 0))
	{
		string_data->new_line_pointer++;
		new_stash = ft_strjoin(new_stash, string_data->new_line_pointer);
	}
	free(stash);
	return(new_stash);
}

char *get_next_line(int fd)
{
	static char* stash[4096];
	char *line;
	t_read_status *string_data;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string_data = (t_read_status *) malloc(sizeof(t_read_status));
	stash[fd] = read_till_nl_found(fd, stash[fd], string_data);
	if (!stash[fd])
	{
		free(string_data);
		free(stash[fd]);
		return (NULL);
	}
	line = get_line(stash[fd]);
	stash[fd] = update_stash(stash[fd], string_data);
	free(string_data);
	return (line);
}