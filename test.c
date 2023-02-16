#include "so_long.h"

char	**convert_map(char *file)
{
	int		fd;
	int		lines;
	char 	*gnl;
	char	**map;
	
	fd = open(file, O_RDONLY);
	map = 0;
	if (fd < 0)
		return (map);
	lines = 0;
	gnl = get_next_line(fd);
	while (gnl)
	{
		gnl = get_next_line(fd);
		lines++;
	}
	close(fd);
	ft_printf("%i", lines);
	return (map);
}

int	main()
{
	char **map;

	map = convert_map("maps/map1.ber");
}
