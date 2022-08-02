/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:06:24 by aceralin          #+#    #+#             */
/*   Updated: 2022/08/02 18:32:21 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

// Buffer
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

// Main
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Get_next_line
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

// Useful fonctions

char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif