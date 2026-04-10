# minirt ⚡︎

> ray tracer in c. no opengl. no shortcuts. just math and a lot of faith.

a ray tracing engine built from scratch in c, rendering 3d scenes with lighting, shadows, and surface textures — all from a simple `.rt` scene file.

---

## what it renders

| object | identifier |
|---|---|
| sphere | `sp` |
| plane | `pl` |
| cylinder | `cy` |
| cone | `co` |
| light | `L` |
| camera | `C` |
| ambient | `A` |

---

## features

- diffuse lighting + specular highlights (phong model)
- hard shadows
- checkerboard pattern
- texture mapping (`.xpm`)
- bump mapping (`.xpm`)
- object selection with mouse click
- live scene manipulation — move, rotate, resize objects in real time
- camera transforms (position + orientation)
- multi-light support

---

## scene format

```
# scene file: scenes/example.rt

A   0.2     255,255,255
C   0,0,10  0,0,-1      70
L   0,10,0  0.8         255,255,255

sp  0,0,0   2           145,170,255
pl  0,-2,0  0,1,0       125,125,125
cy  0,1,0   0,1,0  1 2  227,0,255
co  0,3,0   0,-1,0 1 2  255,89,89
```

| identifier | params |
|---|---|
| `A` | brightness rgb |
| `C` | position orientation fov |
| `L` | position brightness rgb |
| `sp` | center diameter rgb |
| `pl` | point normal rgb |
| `cy` | center axis diameter height rgb |
| `co` | center axis diameter height rgb |

---

## controls

| key | action |
|---|---|
| `wasd` | move on z/x axis |
| `q / e` | move on y axis |
| `arrows` | rotate |
| `1 / 2` | radius +/- |
| `3 / 4` | height +/- |
| `- / +` | brightness +/- |
| `T` | toggle texture |
| `B` | toggle bump map |
| `C` | toggle checkerboard |
| `mouse click` | select / deselect object |
| `ESC` | exit |

---

## build & run

```bash
make
./miniRT scenes/01-sphere.rt
```

included scenes: `01-sphere`, `02-cylinder`, `03-littlebitofall`, `04-camera`, `05-brightness`, `06-white`

---

## architecture

```
.
├── srcs/
│   ├── graphics/   ← ray tracing, lighting, colors, patterns, pixels
│   ├── objects/    ← sphere, plane, cylinder, cone intersection math
│   ├── parser/     ← .rt file parser, scene preparation, camera rotation
│   ├── hooks/      ← keyboard/mouse events, object manipulation
│   ├── vectors/    ← vector math (add, sub, dot, normalize, rotate)
│   └── includes/   ← all headers and type definitions
├── scenes/         ← example .rt scene files
└── patterns/       ← texture and bump map .xpm files
```

---

made at **1337 benguerir** · 42 network  
`wel-kass` · [intra](https://profile.intra.42.fr/users/wel-kass)
