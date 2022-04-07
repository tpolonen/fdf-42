/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:02:54 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/07 10:42:22 by tpolonen         ###   ########.fr       */
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
	ft_putstr("starting from ");
	ft_putchar(*nptr);
	ft_putendl("");
	while(i < rows)
	{
		cols = 0;
		while (*endptr != '\n' && *endptr != '\0' && cols<500)
		{
			ft_putstr("should be ");
			ft_putnbr((int)ft_strtol(nptr, NULL));
			ft_putstr(" accually is ");
			dintarr_add(&darr, (int)ft_strtol(nptr, &endptr));
			ft_putstr("[");
			ft_putnbr(cols);
			ft_putstr("]");
			ft_putnbr(darr->arr[cols]);
			ft_putstr("\n");
			while(isskippable(*endptr)) endptr++;
			if (*endptr == '\n' || *endptr == '\0')
			{
				dintarr_close(&darr, &(map[i]));
				col_arr[i] = ++cols;
				ft_putstr("map[");
				ft_putnbr(i);
				ft_putendl("] contents:");
				print_intarr(map[i], col_arr[i]);
			}
			else
			{
				cols++;
				nptr = endptr;
			}
		}
		i++;
		nptr = ++endptr;
		ft_putnbr(i);
		ft_putstr("/");
		ft_putnbr(rows);
		ft_putendl(" rows done");
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
		{
			ft_putstr("got this many rows: ");
			ft_putnbr(rows);
			ft_putendl("");
			return (rows);
		}
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
	data = NULL;
	rows = read_rows(fd, &data);
	ft_putendl("this is data:");
	ft_putendl(data->str);
	ft_putendl("");
	cols = (int *)ft_memalloc(sizeof(int) * rows);
	map = read_cols(data->str, cols, rows);
	ft_putendl("contents of col array:");
	print_intarr(cols, rows);
	ft_putendl("contents of map arr:");
	for (int i=0; i<rows; i++) print_intarr(map[i], cols[i]);
}
