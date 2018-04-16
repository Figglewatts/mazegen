# mazegen
Maze generation in C for a uni project -- Was used for maze game in Embedded Systems module.

Implements a recursive backtracking maze generation algorithm.

Generates mazes like this:

```
#############################################
#.....#...............#.#.#.........#.......#
#.#.#####.#.#.#.#.###.#.#.#.###.#.###.###.###
#.#.....#.#.#.#.#.#...........#.#...#.#.#...#
###.#.#####.#########.#####.#####.#####.#.###
#.#.#.....#.#.#.#.#...#.#.#.#.#.....#.......#
#.###.#.#####.#.#.###.#.#.###.###.#####.###.#
#...#.#.....#.......#.......#.......#.#...#.#
###.###.#.###.###.###.###.#######.###.#.###.#
#.#...#.#...#...#...#.#...#.#.#.#.........#.#
#.#.#####.###.###.###.###.#.#.#.###.#######.#
#...#.......#...#...#.#...........#.#.#.#.#.#
#.#####.#.###.###.#########.###.#####.#.#.###
#.#.#...#.#.#...#...#.#.#...#.....#.......#.#
#.#.###.###.#.###.###.#.#######.#####.###.#.#
#...#...........#.........#.#...#.....#.....#
###.###.#.#.#.###.#.#.#.###.###.###.#.#####.#
#.#.#.#.#.#.#.#.#.#.#.#.......#.#...#...#.#.#
#.#.#.#########.#######.#.#.###.###.#####.#.#
#.....#.#.............#.#.#...#.......#.....#
#.#####.###.###.###.#.#####.#######.#####.###
#.#.#.......#.....#.#...#.......#.....#.#...#
#.#.###.#.#####.#####.#.###.#.#####.###.#.###
#.......#.#.#.#...#.#.#...#.#...#...#.#.....#
#.#########.#.#.###.###.#####.#######.#.###.#
#.#.#.#.#.........#.#...#.......#.#.#.....#.#
###.#.#.###.###.###.###.###.#.###.#.#.#####.#
#.#.......#.#.#.#.......#...#.#.#.......#...#
#.#.###.###.#.#####.#######.###.#.#########.#
#.....#...#...#.#...#.#.......#...#.#.#.....#
#.#####.#####.#.#####.###.#.#####.#.#.###.#.#
#.#.#.......#.....#.......#.#.#.........#.#.#
#.#.#####.#####.#####.#.#.###.###.###.###.###
#...#.#.#.....#.#.....#.#.#.......#.#...#...#
###.#.#.###.###.###.#.#######.#.###.#.#######
#.........#...#.#...#.#...#...#.#.....#.#.#.#
###.###.###.###.###.#####.###.#####.###.#.#.#
#...#...#.#.....#.......#.......#...#.......#
###.###.#.###.#####.#.#####.#.#.###.###.###.#
#...#.......#.....#.#...#.#.#.#.#.......#...#
#.#.#####.###########.###.#################.#
#.#.#.#...#.#.#.#...........#.#.#.#.#.#.#.#.#
#.###.###.#.#.#.###.#.#.#.###.#.#.#.#.#.#.#.#
#.....#.............#.#.#...................#
#############################################
```

Implementation based on [this article](http://www.migapro.com/depth-first-search/) with stack implementation from [this article](http://datagenetics.com/blog/november22015/index.html).
