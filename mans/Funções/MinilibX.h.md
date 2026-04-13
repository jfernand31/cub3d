# MiniLibX (mlx.h)

#graphics/minilibx

## Overview

MiniLibX is a **very small graphics library** used in 42 projects (like `so_long`, `cub3D`).

It allows you to:

- create a window
    
- draw pixels / images
    
- handle keyboard & mouse events
    
- manage a simple render loop
    

---

## Core Concepts

- **mlx_ptr** → connection to the display system
    
- **win_ptr** → window instance
    
- **img_ptr** → image buffer (used for drawing)
    

---

# Initialization

## mlx_init

```c
void *mlx_init(void);
```

### Description

Initializes connection to the graphical system.

### Return

- pointer to MLX instance
    
- `NULL` on failure
    

---

# Window

## mlx_new_window

```c
void *mlx_new_window(void *mlx, int width, int height, char *title);
```

### Description

Creates a new window.

### Parameters

- `mlx` → mlx pointer
    
- `width` → window width
    
- `height` → window height
    
- `title` → window title
    

### Return

- window pointer
    

---

## mlx_destroy_window

```c
int mlx_destroy_window(void *mlx, void *win);
```

### Description

Closes and frees a window.

---

# Images (VERY IMPORTANT for cub3D)

## mlx_new_image

```c
void *mlx_new_image(void *mlx, int width, int height);
```

Creates an image buffer you can draw into.

---

## mlx_get_data_addr

```c
char *mlx_get_data_addr(void *img, int *bpp, int *size_line, int *endian);
```

### Description

Gives access to raw pixel memory.

### Parameters filled:

- `bpp` → bits per pixel
    
- `size_line` → bytes per row
    
- `endian` → pixel format order
    

### Return

- pointer to pixel buffer
    

---

## mlx_put_image_to_window

```c
int mlx_put_image_to_window(void *mlx, void *win, void *img, int x, int y);
```

### Description

Draws an image to the window.

---

## mlx_destroy_image

```c
int mlx_destroy_image(void *mlx, void *img);
```

---

# Drawing

## mlx_pixel_put

```c
int mlx_pixel_put(void *mlx, void *win, int x, int y, int color);
```

### Description

Draws a single pixel (slow → avoid in cub3D loop).

👉 Use image buffers instead.

---

# Events (VERY IMPORTANT)

## mlx_loop

```c
int mlx_loop(void *mlx);
```

### Description

Starts the event loop (keeps window open).

---

## mlx_hook

```c
int mlx_hook(void *win, int event, int mask, int (*f)(), void *param);
```

### Description

Registers event callbacks.

### Common events:

- `2` → key press
    
- `3` → key release
    
- `17` → window close (red X)
    

---

## mlx_key_hook

```c
int mlx_key_hook(void *win, int (*f)(), void *param);
```

Simplified key handler.

---

## mlx_loop_hook

```c
int mlx_loop_hook(void *mlx, int (*f)(), void *param);
```

### VERY IMPORTANT for cub3D:

- called every frame
    
- used for rendering loop
    

---

# cub3D minimal usage pattern

```c
mlx = mlx_init();
win = mlx_new_window(mlx, 800, 600, "cub3D");

img = mlx_new_image(mlx, 800, 600);
addr = mlx_get_data_addr(img, &bpp, &line, &endian);

mlx_loop_hook(mlx, render, data);
mlx_loop(mlx);
```

---

# What you ACTUALLY use in cub3D

## MUST KNOW:

- mlx_init
    
- mlx_new_window
    
- mlx_new_image
    
- mlx_get_data_addr
    
- mlx_put_image_to_window
    
- mlx_loop
    
- mlx_hook
    
- mlx_loop_hook
    

## OPTIONAL:

- mlx_destroy_image
    
- mlx_destroy_window
    
- mlx_pixel_put (rare)
    

---

# 🧠 Key insight

For cub3D, MLX is NOT a full API to study.

It is just:

> "create window → draw pixels in buffer → push to screen → repeat"

---

If you want next step, I can:

- build your **cub3D rendering pipeline diagram**
    
- or show exactly how raycasting plugs into `mlx_loop_hook` (this is where everything clicks)