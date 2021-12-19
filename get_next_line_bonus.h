/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:16:58 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/27 17:41:41 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*get_part(char *str, int pos);
int		ft_strlen(const char *str);
void	pop_front(char **str, int pos);
#endif
