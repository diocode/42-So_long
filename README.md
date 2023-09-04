![so_long_banner-03](https://github.com/diocode/42-So_long/assets/107859177/f2d4d204-c35c-4eef-bb63-09aea6376882)

<p align="center">
	<img src="https://img.shields.io/badge/status-finished-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/badge/evaluated-13%20%2F%2004%20%2F%202023-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/badge/score-125%20%2F%20100-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/github/last-commit/diocode/philosophers?color=%2312bab9&style=flat-square"/>
	<a href='https://www.linkedin.com/in/diogo-gsilva' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-100000?style=flat-square&logo=Linkedin&logoColor=white&labelColor=0A66C2&color=0A66C2'/></a>
</p>

<p align="center">
	<a href="#about">About</a> •
	<a href="#how-to-use">How to use</a> •
	<a href="#examples">Examples</a> •
	<a href="#norminette">Norminette</a>
</p>

## ABOUT ([Subject](/.github/en.subject.pdf))

<br>

<p align="center">
  <img src="https://github.com/diocode/42-So_long/blob/master/.github/so_long.gif" alt="Alt Text">
</p>

<br>

In this computer graphics project, the primary objective is to use the MiniLibX graphical library to create a basic game. The project focuses on improving skills related to window management, event handling, color rendering, and textures. The game's goal is for the player to collect all collectibles on the map and then find the shortest route to escape. Player movement is controlled using the W, A, S, and D keys, with restrictions to prevent moving through walls. The number of movements is displayed in the shell after each move. The bonus part allows for additional features such as player loss upon touching enemy patrols, sprite animations, and on-screen display of the movement count.

The project emphasizes the use of MiniLibX, requires a Makefile for compilation, and takes a map description file as input. While encouraging creativity, the instructions also suggest focusing on core concepts as more advanced graphics projects will follow, offering opportunities for further exploration and development of original features.

<a href="/.github/en.subject.pdf">Click here</a> for the subject of this project.

<br>

## HOW TO USE
#### COMPILATION AND EXECUTION
#### 1º - Clone the repository
```bash
$ git clone git@github.com:diocode/42-So_long.git
```

#### 2º - Enter the project folder and run `make` or `make bonus`
```bash
$ ./cd 42-So_long.git
$ ./make
$ ./make bonus
```

#### 3º - Launch the program
> You can use any of the maps inside `maps` folder
#### Mandatory:
```bash
$ ./so_long [".ber" map file]
```
#### Bonus:
```bash
$ ./so_long_bonus [".ber" map file]
```

<br>

#### MAKEFILE COMMANDS
`make` or `make all` - Compile program **mandatory** files.

`make bonus` - Compile program **bonus** files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object file) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

`make reb` - Use rules `fclean` + `bonus`.

#### TIPS
- Make sure you have minlibx downloaded.
- Have X11 lib updated.
- Use valgrind to check for leaks:
```bash
$ valgrind -s ./so_long_bonus [".ber" map file]
```

<br>

## EXAMPLES
 > Map suggestions
 ```bash
$ ./so_long_bonus maps/small_map.ber
```
<p align="center">
  <img src="https://github.com/diocode/42-So_long/assets/107859177/1047ba9d-8df8-4e79-a2c2-63f2351cf800" alt="Alt Text">
</p>

 ```bash
$ ./so_long_bonus maps/map_demo.ber
```
<p align="center">
  <img src="https://github.com/diocode/42-So_long/assets/107859177/4d6205fa-b36f-40e9-a158-fa1279b8ca09" alt="Alt Text">
</p>

<br>

## NORMINETTE
At 42 School, projects are generally expected to adhere to the Norm, the school's coding standard:

```
- No for, do while, switch, case or goto are allowed
- No more than 25 lines per function and 5 functions per file
- No assigns and declarations in the same line (unless static)
- No more than 5 variables in 1 function
... 
```

* [Norminette](https://github.com/42School/norminette) - Tool by 42, to respect the code norm. `GitHub`
* [42 Header](https://github.com/42Paris/42header) - 42 header for Vim. `GitHub`
