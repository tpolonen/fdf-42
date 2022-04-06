/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:02:54 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/06 15:29:34 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "dintarr.h"

static int	read_cols(char *strtptr)
{
	(void) strtptr;
	return (1);
}

static int	read_rows(int fd, t_dstr *data)
{
	int		rows;
	int		len;
	char	*buf;

	rows = 0;
	while (1)
	{
		len = ft_getline(fd, &buf);
		if (len <= 0)
			return (rows);
		ft_dstrbuild(&data, buf, len);
		ft_dstrbuild(&data, "\n", 1);
		rows++;
	}
}

void		read_file(char* filename, t_param *params)
{
	int		fd;
	int		rows;
	int		**map;
	int		*cols;
	t_dstr	*data;
	
	(void) params;
	(void) cols;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("File reading failed");
		exit(1);
	}
	rows = 0;
	data = (t_dstr *)ft_memalloc(sizeof(t_dstr));
	rows = read_rows(fd, data);
	map = (int **)ft_memalloc(sizeof(int *) * rows);
	while (1)
	{
		read_cols(data->str);
		break ;
	}
}
