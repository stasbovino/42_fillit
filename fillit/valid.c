//include "libft.h"
//include "fillit.h"

int		check_line(char *tmp, int opt)
{
	int	i;

	i = 0;
	if (opt == 1)
	{
		if ((tmp[i] == '\n') && !(tmp[i + 1]))
			return (1);
		else
			return (-1);
	}
	while (tmp[i])
	{
		if (((tmp[i] == '#') || (tmp[i] == '.')) && (i < 4))
			i++;
		else if (i == 4)
		{
			if ((tmp[i] == '\n') && (!(tmp[i + 1])))
				return (1);
			else
				return (-1);
		}
		else
			return (-1);
	}
}

int		valid_line(char *line)
{
	int i;
	int	k;

	i = 0;
	if (ft_countchars(line, '#') != 4)
		return (-1);
	while (line[i++])
		if (line[i] == '#')
			break;
	k = 1;
}

int		r_e_s_h_e_t_k_a_2_0(char **line) //	pereimenui
{

}

int		get_figure(char *line, int n)
{
	t_figure *figure;

	figure = (t_figure*)malloc(sizeof(t_figure));
	figure->order = 65 + n; // !!!!!!!! Poprav'!!!!!!!1
	printf("order char is %c\n", figure->order);

}

int		read_figure(fd)
{
	char	*tmp;
	char	*line;
	int		i;
	static	n;

	n = 0;
	i = 0;
	if (!(line = ft_strnew(0)))
		return (0);
	while (i < 5)
	{
		get_next_line(fd, &tmp);
		(i == 4) ? check_line(tmp, 1) : check_line(tmp, 0);
		line = ft_strrejoin(line, tmp);
		free(tmp);
		i++;
	}
	valid_line(line);
	get_figure(line);
}
