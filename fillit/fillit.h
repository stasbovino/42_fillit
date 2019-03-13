#ifndef FILLIT_H
# define FILLIT_H

#define NUM_OF_FIGURES 3

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

t_figure	*read_figure(int fd, int opt);
int			get_figure(char *line, int n, t_figure **place); //////////// UBERI NAHOOI
int			check_line(char *tmp, int opt);
int			find_sharps(char **line, int opt);
int			valid_line(char *line);
int			write_coord(int *x, int *y, char *line, int opt);
#endif
