# Math Quiz Game (C++) 🧮

A console-based math quiz game built in C++, where the player answers arithmetic questions generated randomly by the computer. The game supports multiple difficulty levels and operation types, tracks the player's score, and announces a final Pass or Fail result.

This is my third practical programming project in C++, built to apply and deepen my understanding of Structures, Enums, and clean code organization.

---

## 🎓 Learning and Programming Foundation

This project was built as part of the practical applications in the **"Algorithms and Problem Solving - Level 2 (Course 5)"** course on [programmingadvices.com](https://programmingadvices.com), under the supervision of engineer **Mohammed Abu Hadhoud** 👑 ([LinkedIn](https://www.linkedin.com/in/abuhadhoud)).

---

## 🎮 How the Game Works

- The player chooses how many questions to answer **(1 to 10)**
- The player chooses a difficulty level: **Easy / Med / Hard / Mix**
- The player chooses an operation type: **Add / Sub / Mul / Div / Mix**
- Questions are generated randomly based on the chosen level and operation
- Each answer is corrected immediately with visual feedback:
  - 🟢 **Green** → Correct answer
  - 🔴 **Red** → Wrong answer
- At the end, full results are displayed with **PASS** or **FAIL**

---

## 🧠 Programming Concepts Applied

- **Enums** (`enum`) — to represent difficulty levels and operation types cleanly
- **Structures** (`struct`) — to group question data and quiz results together
- **Functions** — each task is handled by a small, focused, independent function
- **Random number generation** — for generating question numbers based on level
- **Screen color control** — visual feedback using `system("color")`


---

## 📈 My Progress: My Attempt vs. Final Solution

I kept both versions in this repository to track my own growth as a developer.

### 1. `Math_Game_MyAttempt.cpp` — My First Try
- My initial approach to solving the problem independently
- Helped me identify gaps in my logic and structure

### 2. `Math_Game_FinalSolution.cpp` — The Improved Version
- Cleaner and more efficient structure
- Used a single `GenerateQuestion` function instead of repeating logic
- Handles all operation types and levels in a unified way

---

## 📂 Project Files

| File | Description |
|------|-------------|
| `Math_Game_FinalSolution.cpp` | The improved and structured version |
| `Math_Game_MyAttempt.cpp` | My first independent attempt |
| `README.md` | This file, explaining the project |

---

## 🛠 How to Run the Game

### Prerequisites
You need a C++ compiler installed (like **GCC** on Linux/Mac or **MinGW** on Windows).

### Steps

1. Clone this project:
```bash
git clone https://github.com/karimmesselmi/math-game.git
```

2. Go to the project folder:
```bash
cd math-game
```

3. Compile the final version:
```bash
g++ Math_Game_FinalSolution.cpp -o MathGame
```

4. Run the game:

On Windows:
```bash
MathGame
```
On Linux/Mac:
```bash
./MathGame
```

---

## 👤 About Me

**Karim Messelmi** — Computer Science student, building my foundation one project at a time.

🔗 [LinkedIn](https://www.linkedin.com/in/karim-messelmi-34a02a379)

> *"Every project I build teaches me something new. This is just the beginning."* 🚀
