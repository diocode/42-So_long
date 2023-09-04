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
$ ./git clone git@github.com:diocode/philosophers.git
```

#### 2º - Enter the project folder and run `make`
```bash
$ ./cd philosophers
$ ./make
```

#### 3º - Launch the program
> The last argument is optional for the execution of the program.
```bash
$ ./philo [n of philos] [time to die] [time to eat] [time to sleep] [n times each philo must eat]
```

<br>

#### MAKEFILE COMMANDS
`make` or `make all` - Compile program **mandatory** files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object file) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

#### TIPS
> Replace the "CFLAGS" in the Makefile file to use fsanitize to track data races and mutex errors:
```bash
CFLAGS = -Wall -Wextra -Werror
```
```bash
CFLAGS = -g -Wall -Wextra -Werror -L. -lpthread -g3 -fsanitize=thread -O3 -march=native
```

<br>

## EXAMPLES
 > The performance will change if you use `-fsanitize`, `valgrind` or both together.
 
| Example | Expected Result |
| :-- | :-- |
| `./philo 4 500 200 1.2`           | Invalid argument.                                              |
| `./philo 4 0 200 200`             | Invalid argument.                                              |
| `./philo 4 -500 200 200`          | Invalid argument.                                              |
| `./philo 4 214748364732 200 200`  | Invalid argument.                                              |
| `./philo 1 200 200 200`           | Philosopher 1 takes a fork and dies after 200 ms.              |
| `./philo 4 500 200 2147483647`    | A philosopher dies after 500 ms                                |
| `./philo 4 200 210 200`           | A philosopher dies, it should display the death before 210 ms. |
| `./philo 4 310 200 200`           | A philosopher dies.                                            |
| `./philo 5 800 200 200 7`         | The program stops when each philosopher has eaten 7 times.     |
| `./philo 5 800 200 200`           | No philosopher dies.                                           |
| `./philo 4 2147483647 200 200`    | No philosopher dies.                                           |
| `./philo 5 800 200 150`           | No philosopher dies.                                           |
| `./philo 3 610 200 80`            | No philosopher dies.                                           |
| `./philo 2 800 200 200`           | No philosopher dies.                                           |
| `./philo 4 410 200 200`           | No philosopher dies.                                           |
 > Examples provided by [jotavare](https://github.com/jotavare)

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





# **so_long**
> 42 Common Core Project 
</p>
<p align="center">
	<a href="#about">About</a> •
	<a href="#how-to-use">How to use</a> •
	<a href="#disclaimer">Disclaimer</a>
</p>

## ABOUT
The so_long project is a 2D game where the player navigates through a maze-like environment, avoiding obstacles and enemies to reach a goal.
It aims at teaching students about rendering, sprites, animations, color schemes and game development in 2D.

<br>

<div align="center">
  <img src=https://github.com/diocode/so_long/assets/107859177/c0dc45f3-649b-46aa-b83d-90ffe1585932) />
</div>

<br>

## HOW TO USE
1º - To compile so_long you should run `make` or `make bonus` in the terminal.


2º - Run the program using `so_long` or `so_long_bonus` with a map of your choice
```sh
$ ./so_long path_to_the_map_file.ber
```
```sh
$ ./so_long_bonus path_to_the_map_file.ber
```

<br>

## DISCLAIMER
At 42 School, it is expected that almost every project is written in accordance with the Norm, which is the coding standard of the school:

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
	- No more than 5 variables in 1 function
	... 
