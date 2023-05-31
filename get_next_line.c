/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:14:33 by luchitel          #+#    #+#             */
/*   Updated: 2023/05/31 23:07:07 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_till_nl_found(int fd, char *stash, t_read_status *string_data) // write new data from file till newline symbol is found in written chunk
{
	char *temp;
	char *buf[BUFFER_SIZE + 1];

	string_data->read_bytes = 1;
	while (string_data->read_bytes != 0 && !(string_data->new_line_pointer = ft_strchr(temp, '\n')))
	{
		string_data->read_bytes = read(fd, buf, BUFFER_SIZE);
		if (string_data->read_bytes < 0)
			return (NULL);
		buf[string_data->read_bytes + 1] = '\0';
		temp = ft_strjoin(stash, buf);
	}
	return (temp);	
}

char *get_line(char *stash, t_read_status *string_data)
{
	char *line;
	int	i;
	
	if (!string_data->new_line_pointer)
		return (NULL);
	while (stash && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	ft_strlcpy(line, stash, i + 1);
	return (line);
}

char *update_stash(char* stash, t_read_status *string_data) // нужно записать часть stash после знака новой линии в новую строку и оставить ее в стеше
{

}

char *get_next_line(int fd) //  разобрать кейс с тем, когда файл был прочитан, текст записан в одну строку без символов переноса строки
{
	static char* stash;
	char *line;
	char *nl_pointer;
	t_read_status string_data;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash)
		check_stash_nl(stash); // check if there are any nl signs left
	stash = read_till_nl_found(fd, stash, &string_data);
	if (!stash)
		return (NULL);
	line = get_line(stash, &string_data);
	stash = update_stash(stash, &string_data);
}