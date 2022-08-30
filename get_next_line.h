/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:34:39 by aceralin          #+#    #+#             */
/*   Updated: 2022/08/30 19:08:34 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* BUFFER*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* MAIN */

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

/* GET_NEXT_LINE*/

# include <stdlib.h>
# include <unistd.h>

char	*ft_copy_and_stick(char *buffer, char *line_read);
char	*get_next_line(int fd);
int		found_new_line(char *str);
char	*buffer_after_new_line(char *buffer, int len_line_read);

/*USEFUL FUNCTIONS*/

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
#endif
