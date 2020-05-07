Design Patterns Course Slides
=============================

Slides for Design Patterns Course are written in tex.

## Dependencies 
XeLaTex, Pygments, GNU Make


## General Instructions
To generate updated slides for all patterns just run `update_all.sh` script.
Generated slides are put under pdf folder. 
Script also can be modified to batch edit all pattern tex files etc.


`Makefile` in the slides root directory shouldn't be directly used.
It is a generic makefile, and is soft linked into all specific pattern folders.

`ArmenianSlides.sty` tex styles file contains all common styling settings.
It is also soft linked into all specific patterns folders and used by each one.


## Working with specific pattern slides

To work with or build  specific pattern slides, go to its specific folder under src dir, like:

`cd src/Structural/Proxy/`

Each pattern specific folder has following structure:

```
.
├── ArmenianSlides.sty -> ../../../ArmenianSlides.sty
├── Makefile -> ../../../Makefile
├── res
│   ├── ...
│   ├── motivation.png
│   └── structure.png
└── tex
    └── Proxy.tex
```

Here you can build specific pattern slides by running:

`make slides`

This will generate pdf file and some temporary files and folders.
You can clean up all build results by running:

`make clean`
