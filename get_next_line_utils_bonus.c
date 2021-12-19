/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:23:09 by dmesseng          #+#    #+#             */
/*   Updated: 2021/11/12 17:19:59 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		len_src;
	size_t	i;
	int		return_val;

	i = 0;
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	while (dst[i] != '\0')
	{
		if (i == size - 1)
			return (size + len_src);
		i++;
	}
	return_val = i + len_src;
	while (*src != '\0' && i < size)
	{
		if (i == size - 1)
			break ;
		dst[i++] = *src;
		src++;
	}
	dst[i] = '\0';
	return (return_val);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*concat;

	if (s1 == NULL)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	concat = (char *)malloc(len_s1 + len_s2 + 1);
	if (concat == NULL)
		return (concat);
	concat[0] = '\0';
	ft_strlcat(concat, s1, len_s1 + len_s2 + 1);
	ft_strlcat(concat, s2, len_s2 + len_s1 + 1);
	free(s1);
	return (concat);
}

char	*get_part(char *str, int pos)
{
	char	*part;
	int		i;

	i = 0;
	if (pos == -1)
		pos = 0;
	part = malloc(pos + 1);
	if (!part)
		return (NULL);
	while (i < pos)
	{
		part[i] = str[i];
		i++;
	}
	part[i] = '\0';
	return (part);
}

void	pop_front(char **str, int pos)
{
	char	*after;

	after = get_part(*str + pos + 1, ft_strlen(*str + pos + 1));
	free(*str);
	*str = after;
}
