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

#endif
