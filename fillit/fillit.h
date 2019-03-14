#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_coordinates
{
	int				x;
	int				y;
}					t_coordinates;

typedef struct		s_typeof_figure
{
	t_coordinates	first;
	t_coordinates	second;
	t_coordinates	third;
	t_coordinates	fourth;
}					t_typeof_figure;

typedef struct		s_figure
{
	char			order;
	t_typeof_figure	fig;
}					t_figure;

t_figure	*read_figure(int fd, int n);
int			read_line(int fd, char **line);
int			get_figure(char *line, int n, t_figure **place); //////////// UBERI NAHOOI
int			check_line(char *tmp);
int			find_sharps(char **line, int i, int opt);
int			valid_line(char *line);
int			write_coord(int *x, int *y, char *line, int opt);
#endif
