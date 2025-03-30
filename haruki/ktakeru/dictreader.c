
#include "header.h"

char	**ft_dictread(char *dict)
{
	int		fd;
	int		n;
	int		i;
	char	buf[10000];

	i = 0;
	fd = open(dict, O_RDONLY);
	n = read(fd, buf, 10000);
	close(fd);
	return (ft_split(buf, "\n"));
}
