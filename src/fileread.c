/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:02:54 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/07 15:53:23 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "dintarr.h"

static int	isskippable(char c)
{
	return (c != '\0' && c != '\n' && c != '-' && c != '+' && !ft_isdigit(c));
}

static void	print_intarr(int *arr, int len)
{
	int	i;
	
	i = 0;
	while(i < len)
	{
		ft_putnbr(arr[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putendl("");
}

static int	**read_cols(char *nptr, int *col_arr, int rows)
{
	t_dintarr	*darr;
	int			**map;
	int			i;
	int			cols;

	map = (int **)ft_memalloc(sizeof(int *) * rows);
	i = 0;
	darr = NULL;
	while(i < rows)
	{
		cols = 0;
		while (*nptr != '\n' && *nptr != '\0')
		{
			dintarr_add(&darr, (int)ft_strtol(nptr, &nptr));
			cols++;
			while(isskippable(*nptr)) nptr++;
			if (*nptr == '\n' || *nptr == '\0')
				dintarr_close(&darr, &(map[i]));
		}
		col_arr[i] = cols;
		i++;
		nptr++;;
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
		ft_dstrbuild(data, buf, len);
		ft_dstrbuild(data, "\n", 1);
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
	data = NULL;
	rows = read_rows(fd, &data);
	cols = (int *)ft_memalloc(sizeof(int) * rows);
	map = read_cols(data->str, cols, rows);
	ft_dstrclose(&data, NULL);
	ft_putendl("contents of col array:");
	print_intarr(cols, rows);
	ft_putendl("contents of map arr:");
	for (int i=0; i<rows; i++) print_intarr(map[i], cols[i]);
}
