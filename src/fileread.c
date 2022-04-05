/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:02:54 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/05 17:23:17 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*skip_space(char *str)
{
	while (ft_isspace(*str))
		str++;
	return (str);
}

void read_file(char* filename, t_param *params)
{
	int		fd;
	int		rows;
	int		i;
	int		cols;
	t_dstr	*data;
	char	*buf;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("File reading failed");
		abort(1);
	}
	rows = 0;
	data = (t_dstr *)ft_memalloc(sizeof(t_dstr));
	while(ft_getline(fd, &buf) != -1)
	{

	}
}
