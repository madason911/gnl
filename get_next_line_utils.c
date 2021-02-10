/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljennife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:48:25 by ljennife          #+#    #+#             */
/*   Updated: 2021/01/29 14:22:58 by ljennife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char *temp;

	temp = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (temp);
}

char	*ft_strdup(const char *src)
{
	char *dest;

	dest = malloc(sizeof(char) * (ft_strlen(src)) + 1);
	if (NULL == dest)
		return (NULL);
	return (ft_strcpy(dest, src));
}

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (const char)c)
			return ((char*)s);
		s++;
	}
	if ((const char)c == '\0')
		return ((char*)s);
	return (NULL);
}
