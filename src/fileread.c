/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:02:54 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/06 14:24:58 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "dintarr.h"

void read_file(char* filename, t_param *params)
{
	int			fd;
	int			rows;
	int			i;
	int			cols;
	int			offset;
	int			len;
	int			**map;
	t_dstr		*data;
	t_dintarr	*row;
	char		*buf;
	
	(void) params;
	(void) cols;
	(void) row;
	(void) offset;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("File reading failed");
		exit(1);
	}
	rows = 0;
	data = (t_dstr *)ft_memalloc(sizeof(t_dstr));
	while(1)
	{
		len = ft_getline(fd, &buf);
		if (len <= 0)
			break;
		ft_dstrbuild(&data, buf, len);
		rows++;
	}
	map = (int **)ft_memalloc(sizeof(int *) * rows);
	i = 0;
	while(i < rows)
	{
		i++;
	}
}
