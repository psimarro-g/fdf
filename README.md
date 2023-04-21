# fdf
FDF is short for ’fil de fer’ in French which means ’wireframe model’.
This project is about creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges).

The coordinates of the landscape are stored in a .fdf file passed as a parameter to
the program.

Each number represents a point in space:

• The horizontal position corresponds to its axis.

• The vertical position corresponds to its ordinate.

• The value corresponds to its altitude.

![alt text](https://github.com/psimarro-g/fdf/blob/main/images/array.png)

Executing the program as:
```console
$>./fdf 42.fdf
$>
```

using the example file shown above (42.fdf) should render a landscape similar to:

![alt text](https://github.com/psimarro-g/fdf/blob/main/images/grid.png)
