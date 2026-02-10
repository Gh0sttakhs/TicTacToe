
# 🎮 Tic-Tac-Toe

A complete Tic-Tac-Toe game implemented in **C**, designed to be played via the command line (Console).

The game features a colorful interface, support for two players, and two different Artificial Intelligence (Bot) levels.

## ✨ Features

* 🎨 **Colorful UI:** Uses ANSI codes for board and message coloring (Red for X, Cyan for O, Yellow for UI).
* 🤖 **Two AI Levels:**
    * **Normal Bot:** A smart bot that attempts to win, defend, and control the center and corners.
    * **Pro Bot (Invincible):** Uses the **Minimax** algorithm and is mathematically impossible to beat. The best result you can achieve against it is a draw.
* 👥 **Local Multiplayer:** Play against a friend on the same computer.
* 🛡️ **Input Validation:** Protection against invalid inputs (letters instead of numbers, out-of-bound positions, occupied cells).

## 📂 File Structure

The project consists of 3 main files for proper code organization:

1.  `main.c`: Contains the game flow, menu, and user interface.
2.  `bot.c`: Contains the Artificial Intelligence logic (Normal Strategy & Minimax Algorithm).
3.  `tictactoe.h`: Header file connecting the above two files.

## 🚀 Installation and Execution

To run the game, you need a C compiler (such as `gcc`).

### 1. Compilation
Open your terminal in the project folder and run the command:

```bash
gcc main.c bot.c -o tictactoe

```

### 2. Execution (Run)

**On Windows:**

Bash

```
tictactoe.exe

```

**On Linux / macOS:**

Bash

```
./tictactoe

```

## 🎮 How to Play

The board is divided into Columns (A, B, C) and Rows (1, 2, 3).

```
   A   B   C
1  -   -   -  1
2  -   -   -  2
3  -   -   -  3
   A   B   C
```

When prompted to play, enter coordinates in the format `LETTER NUMBER`.

**Examples:**

-   `A 1` (Top Left)
    
-   `B 2` (Center)
    
-   `C 3` (Bottom Right)
    

## 🧠 AI Technical Details

### Normal Bot Strategy

The standard Bot follows a hierarchy of rules:

1.  **Win:** If it can win in this move, it does.
    
2.  **Block:** If the player threatens to win, it blocks them.
    
3.  **Center:** Tries to take the center (strategic position).
    
4.  **Corners:** Prefers corners over sides.
    
5.  **Random:** If none of the above apply, it plays randomly.
    

### Pro Bot (Minimax)

The invincible Bot uses the recursive **Minimax** algorithm.

-   Simulates **all** possible future moves until the end of the game.
    
-   Scores each outcome (+10 for win, -10 for loss, 0 for draw).
    
-   Always chooses the move that maximizes its gain, assuming the opponent also plays perfectly.
