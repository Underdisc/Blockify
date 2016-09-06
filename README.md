# BLOCKIFY

**Compile and Run**
```
gcc src/main.c src/block_text.c src/options.c -o blockify
./blockify
```

All current documentation can be found in documentation/html/index.html

Given a null terminated string, the blockify program will generate the text in the form of a block. If desired, an option to add a diagonal through the block is possible as well. If no text is provided, the blockify program will use "SAMPLETEXT" as the null terminated string.

##### Options
- --diagonal or -d: Add a diagonal to the block
- --text "text" or -t "text": Specify custom text
- --help or -h: Print this

##### Sample Usage

*Regular Block*
```
./blockify -t "custom text"

c u s t o m   t e x t
u                   x
s                   e
t                   t
o
m                   m
                    o
t                   t
e                   s
x                   u
t x e t   m o t s u c
```

*Diagonal Block*
```
./blockify -d -t "custom text"

c u s t o m   t e x t
u u               x x
s   s           e   e
t     t       t     t
o       o
m         m         m
            o       o
t     t       t     t
e   e           s   s
x x               u u
t x e t   m o t s u c
```
**Current Version: 1.0**

Version List
- **1.0** Ability to create blocks and add diagonals to the blocks
