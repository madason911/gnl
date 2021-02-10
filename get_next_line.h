/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljennife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:48:19 by ljennife          #+#    #+#             */
/*   Updated: 2021/01/29 13:48:23 by ljennife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *src);
void	ft_strclr(char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);
char	*check_rem(char *rem, char **line);
int		ret_answer(int bytes, char *tmp_ptr);

#endif
