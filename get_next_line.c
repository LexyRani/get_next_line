/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:34:45 by aceralin          #+#    #+#             */
/*   Updated: 2022/08/30 19:05:26 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffer_after_new_line(char *buffer, int to_nl)
{
	size_t	i;
	size_t	len_after_nl;

	i = 0;
	len_after_nl = ft_strlen(&buffer[to_nl]);
	if (len_after_nl != 0)
		ft_memcpy(buffer, &buffer[to_nl], len_after_nl);
	while ((i + len_after_nl) < BUFFER_SIZE && buffer[i + len_after_nl])
	{
		buffer[i + len_after_nl] = '\0';
		i++;
	}
	return (buffer);
}

char	*ft_copy_and_stick(char *buffer, char *line_read)
{
	size_t		i;
	size_t		len_line_read;
	char		*stock;

	len_line_read = ft_strlen(line_read);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	stock = malloc(sizeof(stock) * (len_line_read + i + 1));
	if (!stock)
		return (NULL);
	stock[len_line_read + i] = '\0';
	ft_memcpy(stock, line_read, len_line_read);
	ft_memcpy(&stock[len_line_read], buffer, i);
	buffer_after_new_line(buffer, i);
	if (line_read)
		free(line_read);
	line_read = NULL;
	return (stock);
}

int	found_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line_read;
	int			count;

	if ((fd < 0) || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	count = 1;
	line_read = NULL;
	while (found_new_line(line_read) != 1 && count != 0)
	{
		if (!buffer[0])
		{
			count = read (fd, buffer, BUFFER_SIZE);
			buffer[count] = '\0';
		}
		line_read = ft_copy_and_stick(buffer, line_read);
		if (!line_read)
			break ;
	}
	if (!line_read || !line_read[0])
	{
		free(line_read);
		return (NULL);
	}
	return (line_read);
}
/*

int main(int argc, char **argv)
{
    int     fd;
	int		i;
    char    *extract;

    (void)argc;
    (void)argv;
	i = 0;
    extract = "";
    fd = open("jojo", O_RDONLY);
    if (fd == -1)
    {
        printf("\n[error open()\n]");
        return (1);
    }
	printf("\nopen()\n");
    while (extract != NULL)
	{
		extract = get_next_line(fd);
		printf("gnl -> %s\n", extract);
		free(extract);
		i++;
	}
	printf("i   -> %d\n", i);
    if (close(fd) == -1)
    {
        printf("\n[error close()]\n");
        return (2);
    }
	printf("\nclose()\n");
    return(0);
}*/
