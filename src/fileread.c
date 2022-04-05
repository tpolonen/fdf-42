/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:02:54 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/05 12:22:38 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void read_file(char* filename, t_param2 *params)
{
	int		fd;
	int		rows = 0;
	int		cols = 0;
	char 	*line;
	
	printf("filename was %s\n", filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		perror("File reading failed");
		exit(6);
	}
	ft_getline(fd, &line);
	perror("Here's what happened with getline");
	printf("%s\n", line);
	char *endptr = line;
	printf("reading vals from file\n");
	while (*endptr != '\0') {
		long val = strtol(line, &endptr, 10);
		line = endptr;
		printf("%p: %ld\n", endptr, val);
	}
	params->map = NULL;
	params->nodecount = 0;
}


