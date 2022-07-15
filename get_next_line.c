/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:07:11 by aceralin          #+#    #+#             */
/*   Updated: 2022/07/15 14:25:53 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <limits.h>


int	found_new_line (char *buffer)
{
	int	i;
	
	i = 0;
	while(buffer[i])
	{
		if(buffer[i] == '\n')
			return(1);
		i ++;
	}
	return(0);
}

/*qui va chercher dans le buffer si il y a un \n

return 1 si il trouve et 0 si il ne trouve pas
*/
char	*ft_copy_and_stick(char *buffer, char *line_read)
{	

	static char *tmp;
	if(line_read == NULL )
		line_read = ft_strdup(buffer);
	tmp = ft_strdup(buffer);	
	line_read = ft_strjoin(line_read, tmp);
	return (line_read); 
}
char	*get_next_line (int fd)
{
	char	*line_read;
	void  	*buffer;
	size_t	count;
	
	if( (fd < 0) || BUFFER_SIZE <= 0)
		return(NULL);
	buffer = malloc(sizeof(char)* (BUFFER_SIZE + 1));
	if (!buffer)
		return(0);
	line_read = NULL; 
	while (found_new_line(buffer) == 0)
	{
		// si absence de \n
		read (fd, buffer, BUFFER_SIZE);//lire puis stocker dans le buffer
		line_read = ft_copy_and_stick(buffer, line_read);//fonction qui va copier ce quil y a dans buffer strdup + strjoin
		
		// sinon separer la ligne et retourner la string
		// apres \n  on recommence le processus
	}
	return(line_read);
}

int	main()
{
	char fd;
	fd = open("text.txt", O_RDONLY);
	printf("%d\n", FOPEN_MAX);
	while (1)
	{
		get_next_line(fd);
		if(get_next_line(fd) == NULL)
			return(0);
		printf("%s",get_next_line(fd));
		free(get_next_line(fd));
	}	
	return(0);
}
