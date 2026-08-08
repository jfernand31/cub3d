*This project has been created as part of the 42 curriculum by jfernand, mda-enca.*

# Cub3D

## Description

Cub3D is a raycasting engine inspired by the classic first-person shooter *Wolfenstein 3D*. The project's goal is to render a pseudo-3D view of a maze-like map from a 2D array of data, using the raycasting technique to simulate a 3D perspective on a 2D grid.

The program reads a `.cub` configuration file describing the map layout, wall textures (north, south, east, west), floor and ceiling colors, and the player's starting position and orientation. It then opens a window in which the player can move and look around the map in real time, with walls rendered using the appropriate textures depending on which side is being viewed.

This project introduces core concepts of raycasting, vector math, and working with a graphics library (MiniLibX) to handle rendering, window management, and keyboard/mouse input, all built on top of a norm-compliant C codebase.

## Instructions

### Compilation

Clone the repository and compile the project using `make`:

```bash
git clone <repository-url>
cd cub3d
make
```

This produces an executable named `cub3D` at the root of the project.

Other available Makefile rules:

```bash
make clean   # remove object files
make fclean  # remove object files and the executable
make re      # fclean + full rebuild
```

### Execution

Run the program with a valid `.cub` map file as an argument:

```bash
./cub3D maps/example.cub
```

### Controls

| Key | Action |
|---|---|
| `W` / `A` / `S` / `D` | Move forward / left / backward / right |
| `←` / `→` | Rotate the camera left / right |
| `ESC` | Close the window and exit |
| Window close button | Close the window and exit |

## Resources

- [Lode's Computer Graphics Tutorial – Raycasting](https://lodev.org/cgtutor/raycasting.html) — the classic reference for understanding the raycasting algorithm used in this project
- [MiniLibX documentation (42 Paris)](https://github.com/42Paris/minilibx-linux) — official MiniLibX source and usage reference
- [Wolfenstein 3D source code](https://github.com/id-Software/wolf3d) — historical reference for the original raycasting engine that inspired this project
- [42 Cub3D subject PDF] — official project subject, distributed via the school's intranet

### AI usage

AI (ChatGPT/Claude) was used during this project strictly as a **debugging and learning aid**:
- Explaining compiler errors and segmentation faults, and helping interpret `valgrind`/`gdb` output
- Clarifying raycasting math concepts (DDA algorithm, ray-wall intersection distance correction) in plain language
- Explaining MiniLibX function behavior and event-loop mechanics when documentation was unclear

AI was **not** used to generate project code or algorithm logic directly; all implementation was written and understood by the authors.
