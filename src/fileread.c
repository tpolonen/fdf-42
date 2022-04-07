/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:02:54 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/07 08:25:23 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "dintarr.h"

static void	print_intarr(int *arr, int len)
{
	int	i;
	
	i = -1;
	while(i++ < len)
	{
		ft_putnbr(arr[i]);
		ft_putstr(" ");
	}
	ft_putendl("");
}

static int	**read_cols(char *nptr, int *col_arr, int rows)
{
	t_dintarr	*darr;
	char		*endptr;
	int			**map;
	int			i;
	int			cols;

	map = (int **)ft_memalloc(sizeof(int *) * rows);
	i = 0;
	darr = NULL;
	endptr = nptr;
	while(i < rows)
	{
		cols = 0;
		while (*endptr != '\0')
		{
			dintarr_add(&darr, ft_strtol(nptr, &endptr));
			cols++;
			if (*endptr == '\0' || *endptr == '\n')
			{
				*map[i] = dintarr_close(&darr, &(map[i]));
				col_arr[i] = cols;
			}
			nptr = endptr;
		}
		i++;
	}
	return (map);
}

static int	read_rows(int fd, t_dstr **data)
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
		ft_putendl("buf:");
		ft_putendl(buf);
		ft_dstrbuild(data, buf, len);
		ft_dstrbuild(data, "\n", 1);
		ft_putendl("data->str:");
		ft_putendl((*data)->str);
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
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("File reading failed");
		exit(1);
	}
	rows = 0;
	cols = NULL;
	data = NULL;
	rows = read_rows(fd, &data);
	ft_putendl("this is data:");
	ft_putendl(data->str);
	ft_putendl("");
	map = read_cols(data->str, cols, rows);
	ft_putendl("contents of col array:");
	print_intarr(cols, rows);
	ft_putendl("contents of map arr:");
	for (int i=0; i<rows; i++) print_intarr(map[i], cols[i]);
}
