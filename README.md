# 42_fillit

Fillit is a project that let you discover and/or familiarize yourself with a recurring
problematic in programming: searching the optimal solution among a huge set of possibilities, in a respectable timing. In this particular project, you will have to find a way to
assemble a given Tetriminos set altogether in the smallest possible square.
A Tetriminos is a 4-blocks geometric figure you probably already heard of, thanks to
the popular game Tetris.  

<p align="center">
  <img src="https://i.imgur.com/8gceU69.jpg" width="350" title="hover text">
</p>  

The program gets as argument a file, format as list of tetriminos as at the picture.
In folder `/test` you can find invalid and valid test-files, for example valid file `4f`:
 \
.... \
.##. \
##.. \
.... \
 \
.... \
.##. \
..## \
.... \
 \
.... \
.##. \
.##. \
.... \
 \
...# \
...# \
...# \
...# \
 \
The result will be the optimal place of all figures in minimal square with priority on order of appearing in file:
 \
.AA.D \
AACCD \
BBCCD \
.BB.D \
.....


#### Usage:
`make`\
`./fillit [file]`\
examples of start with files:\
`./fillit test/4f`\
`./fillit test/13feq+`\
