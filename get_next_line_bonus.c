/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:04:00 by dmesseng          #+#    #+#             */
/*   Updated: 2021/11/12 18:13:17 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

int	is_new_line(char	*str, int	*pos)
{
	int	i;

	i = 0;
	*pos = -1;
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == '\n')
		{
			*pos = i;
			return (1);
		}
		i++;
		str++;
	}
	return (0);
}

char	*correct_free(char *ptr)
{
	free(ptr);
	return (NULL);
}

char	*is_safe(int fd)
{
	int		written;
	char	*buf;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	written = read(fd, buf, 0);
	if (written == -1)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

char	*get_result(char **history, int nl_pos)
{
	char	*result;

	if (*history == NULL)
		return (NULL);
	if (nl_pos == -2)
	{
		result = get_part(*history, ft_strlen(*history));
		if (result[0] == '\0')
		{
			free(result);
			*history = correct_free(*history);
			return (NULL);
		}
		*history = correct_free(*history);
		return (result);
	}
	result = get_part(*history, nl_pos + 1);
	pop_front(history, nl_pos);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*history[OPEN_MAX];
	int			nl_pos;
	char		*buf;
	int			written;
	char		*res;

	buf = is_safe(fd);
	if (!buf)
		return (NULL);
	while (!is_new_line(history[fd], &nl_pos))
	{
		written = read(fd, buf, BUFFER_SIZE);
		if (written == 0)
		{
			nl_pos = -2;
			break ;
		}
		buf[written] = '\0';
		history[fd] = ft_strjoin(history[fd], buf);
	}
	res = get_result(&history[fd], nl_pos);
	free(buf);
	return (res);
}
