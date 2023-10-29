<h1 align="center">
	FDF
</h1>
<h2 align="center">
	<b><i>Computer graphics project</i></b><br>
</h2>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/psimarro-g/fdf?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/psimarro-g/fdf?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/psimarro-g/fdf?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/psimarro-g/fdf?color=green" />
</p>

<p align="center">
	Mac OS X 10.15.7 (Darwin Kernel Version 19.6.0)<br>
</p>


## The project
FDF is short for "fil de fer" in French which means "wireframe model".
This project is about creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges).

The program uses a simple graphic library developped in 42 école to manage windows, images and events called minilibx.

The coordinates of the landscape are stored in a .fdf file passed as a parameter to
the program.

Each number represents a point in space:

- The horizontal position corresponds to its axis.

- The vertical position corresponds to its ordinate.

- The value corresponds to its altitude.
<p align="center">
<img src="https://github.com/psimarro-g/fdf/blob/main/images/array.png">
</p>

Executing the program as:
```console
$>./fdf 42.fdf
```

and using the example file shown above "42.fdf" should render a landscape similar to:

<p align="center">
<img src="https://github.com/psimarro-g/fdf/blob/main/images/grid.png">
</p>

## Additional features

The z value or altitude stored in the grid can also contain a hex colour for that point separated by a comma (1,0xff). The parser that reads the maps stores this value and defaults to a specified colour when absent. It also checks for any errors in the format.

When tracing lines between points with different colours the implemented  line algorithm gradually blends them.

The map representation can be transformed in real time with rotation, translation, zoom (always centered on the viewing point) and offers both parallel and isometric views of the map in a builtin menu.

Anti aliasing in the line segments that connect the grid dots was mitigated by imlplementing [Wu's line algorithm](https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm).

<br>
<p align="center">
<img src="https://github.com/psimarro-g/fdf/blob/main/images/Screen Shot 2023-10-29 at 9.09.51 PM.png">
</p>
