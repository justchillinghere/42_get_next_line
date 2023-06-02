/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:14:33 by luchitel          #+#    #+#             */
/*   Updated: 2023/06/02 12:36:54 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		ft_strjoin(new_stash, string_data->new_line_pointer);
	}
	free(stash);
	return(new_stash);
}

char *get_next_line(int fd)
{
	static char* stash;
	char *line;
	t_read_status *string_data;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string_data = (t_read_status *) malloc(sizeof(t_read_status));
	stash = read_till_nl_found(fd, stash, string_data);
	if (!stash)
	{
		free(string_data);
		free(stash);
		return (NULL);
	}
	line = get_line(stash);
	stash = update_stash(stash, string_data);
	free(string_data);
	return (line);
}

// int main()
// {
// 	// int fd;
// 	// char *line;
// 	// int i;

// 	// fd = open("tests/41_no_nl", O_RDONLY);
// 	// i = 0;
// 	// while (i++ < 7)
// 	// {
// 	// 	line = get_next_line(fd);
// 	// 	printf("%s", line);
// 	// }
// 	printf("%s", get_next_line(1000));
// 	return (0);
// }