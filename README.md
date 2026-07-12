# Wordle in C

A wordle game that can be enjoyed on terminal in C. This project
practices C programming and implements file handling, modular programming, user input and Makefile.

---

## Features

- Play Wordle on the terminal
- Accepts only valid 5-letter English words
- Color-coded feedback for each guess
- Organized into multiple header files and source files
- Build using make

---

## Project Structure

```
.
|-- Makefile
|-- README.md
|-- common.h
|-- main.c
|-- game.c
|-- game.h
|-- io.c
|-- io.h
|-- words.c
|-- words.h
|-- wordlist.txt
`-- build/
    |-- *.o
    `-- wordle

```

## Requirements

- GCC
- GNU Make

---

## Build the Project

Run the following commands to compile, run and clean the project:

```bash
make # Build project
make run # Build and run
make clean # Remove build directory
```

---

## How to Play

- The game randomly selects a five-letter word from a text file wordlist.txt
- You have **5 attempts** to guess the correct word.

Feedback:

- **Green** - Correct letter in correct position.
- **Yellow** - Letter exists in the word but is in wrong position.
- **Red** - Letter is not in the word.

Only valid five-letter words are to be accepted.

---

## Files in the project

| File           | Description                             |
| -------------- | --------------------------------------- |
| `main.c`       | Program entry point                     |
| `game.c`       | Game loop and game state                |
| `io.c`         | User input and output                   |
| `words.c`      | Dictionary handling and word comparison |
| `common.h`     | Shared constants, types and globals     |
| `wordlist.txt` | Dictionary of valid words               |
| `Makefile`     | Build automation                        |

---

## Build Options

```bash
-Wall -Wextra -std=gnu11 -g
```

---

## Author

Manish Kumar
