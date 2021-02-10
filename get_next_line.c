/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljennife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 04:04:35 by ljennife          #+#    #+#             */
/*   Updated: 2021/01/29 15:54:32 by ljennife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	char	*ptr;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1;
	strjoin = malloc(sizeof(char) * len);
	if (strjoin == NULL)
		return (NULL);
	ptr = strjoin;
	while (*s1 != '\0')
	{
		*strjoin = *s1;
		strjoin++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*strjoin = *s2;
		strjoin++;
		s2++;
	}
	*strjoin = '\0';
	return (ptr);
}

char	*check_rem(char *rem, char **line)
{
	char	*tmp_ptr;

	tmp_ptr = NULL;
	if (rem)
	{
		if ((tmp_ptr = ft_strchr(rem, '\n')))
		{
			*tmp_ptr = '\0';
			*line = ft_strdup(rem);
			ft_strcpy(rem, ++tmp_ptr);
		}
		else
		{
			*line = ft_strdup(rem);
			ft_strclr(rem);
		}
	}
	else
	{
		*line = ft_strnew(0);
	}
	return (tmp_ptr);
}

int		ret_answer(int bytes, char *tmp_ptr)
{
	if (bytes < 0)
		return (-1);
	else if (bytes || tmp_ptr)
		return (1);
	else
		return (0);
}

int		get_next_line(int fd, char **line)
{
	int				bytes;
	char			buf[BUFFER_SIZE + 1];
	char			*tmp_ptr;
	static	char	*rem = NULL;
	char			*leak;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0))
		return (-1);
	tmp_ptr = check_rem(rem, line);
	while (!tmp_ptr && (bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		if ((tmp_ptr = ft_strchr(buf, '\n')))
		{
			*tmp_ptr = '\0';
			leak = rem;
			rem = ft_strdup(++tmp_ptr);
			free(leak);
		}
		leak = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		free(leak);
	}
	return (ret_answer(bytes, tmp_ptr));
}
