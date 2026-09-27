# CHRONO_TOOL

A program to calculate and manipulate durations without a hitch!

---

## Table of Contents
- [About](#about)
  - [What it does](#what-it-does)
  - [Who it's for](#who-its-for)
  - [Why it stands out](#why-it-stands-out)
- [Features](#features)
- [Quick Start](#quick-start)
  - [Method 1 : With Make (Recommended)](#method-1--with-make-recommended)
  - [Method 2 : Direct command](#method-2--direct-command)
  - [Run the program](#run-the-program)
- [Preview](#preview)
- [Usage](#usage)
- [What I Learned](#what-i-learned)
- [Future Improvements](#future-improvements)
- [License and Author](#license-and-author)

---

## About

Durations are everywhere. Whether you're measuring a workout, tracking the time spent on a task, or handling time intervals in a program, you need a reliable way to represent and manipulate hours, minutes, and seconds.

**Chrono Tool** solves this by providing a robust C++ class `Duration` that handles time arithmetic, automatic normalization, and human-readable output.

### What it does

- Stores and manipulates durations (hours, minutes, seconds)
- Automatically normalizes values (e.g., `90s` becomes `1min 30s`)
- Supports arithmetic operations (`+`, `-`) and comparisons (`==`, `<`, `>`, `<=`, `>=`, `!=`)
- Converts to and from total seconds
- Displays results in a clean `Xh Ymin Zs` format

### Who it's for

- Anyone who needs a quick and reliable duration calculator
- Students learning Object-Oriented Programming (OOP), operator overloading, and time representation in C++
- Developers looking for a modular and reusable time-handling class

### Why it stands out

Unlike a basic time converter, this project includes:

- **Auto-normalization**: no invalid state like `75s` or `120min` is ever stored
- **Operator overloading**: `+`, `-`, comparisons, and stream output all work naturally
- **Clean architecture**: separation between `core/` (logic) and `app/` (interface)

---

## Features

### Time manipulation

- **Arithmetic operations**: `+`, `-`, `==`, `<`, `>`, `<=`, `>=`, `!=`
- **Auto-normalization**: seconds and minutes overflow (≥ 60) are automatically carried over
- **Conversion to HMS**: `toHMS()` returns `Xh Ymin Zs`
- **Conversion to seconds**: `toSeconds()` returns the total as an integer
- **Display in HMS format**: via `operator<<`

### Constructors

- `Duration()` — default (0h 0min 0s)
- `Duration(int hours)`
- `Duration(int hours, int minutes)`
- `Duration(int hours, int minutes, int seconds)`

### Robustness

- Normalization called automatically after every operation
- Clean output format

---

## Prerequisites

- **Compiler**: `g++` (version ≥ 7.0) or `clang++`
- **Build tool**: `make` (version ≥ 4.0)
- **C++ Standard**: C++17 (or later)
- **System**: Linux, macOS, or Windows (via WSL or Cygwin)

---

## Quick Start

### Method 1 : With Make (Recommended)

```bash
make
```

### Method 2 : Direct command

```bash
g++ -std=c++17 -Wall -Wextra -I Include/ -o main.cpp src/core/Duration.cpp
```

### Run the program

```bash
./programme.exe
```

---

## Preview

```text

> Duration d1(1, 75, 90);
> d1.toHMS()
  = 2h 16min 30s

> Duration d2(0, 0, 45);
> d1 + d2
  = 2h 17min 15s

> d1 > d2
  = true
```

---

## Usage

1. Launch the program with `./chrono_tool`.
2. Enter a duration using one of the supported constructors.
3. Apply operations (`+`, `-`) or comparisons.
4. Display the result in HMS format.

**Supported formats:**

| Input type | Examples |
| :--- | :--- |
| Duration (H, M, S) | `(1, 30, 45)`, `(0, 90, 30)` |
| Seconds only | `3665` |
| Operators | `+`, `-`, `==`, `<`, `>` |

**Normalization examples:**

| Before | After |
| :--- | :--- |
| `90s` | `1min 30s` |
| `120min` | `2h 0min` |
| `1h 75min 90s` | `2h 16min 30s` |

---

## What I Learned

- **Operator overloading**: implementing `+`, `-`, and all comparison operators for a custom `Duration` class.
- **Invariant maintenance**: using `normalize()` to guarantee that minutes and seconds are always in `[0, 59]`, which keeps the internal state consistent.
- **Time representation**: choosing to store the duration as `(hours, minutes, seconds)` for readability, while using `toSeconds()` for all arithmetic to avoid edge cases.
- **Stream output**: overloading `operator<<` to display durations in a human-readable format.

---

## Future Improvements

- [ ] **Stopwatch mode**: start, pause, resume, add/undo laps, and display total duration
- [ ] Handle negative durations (currently subtraction can produce invalid states)
- [ ] Add support for days and weeks
- [ ] Export stopwatch laps to a `.csv` file
- [ ] Add a timer mode (countdown)

---

## License and Author

Distributed under the MIT License. See `LICENSE` for details.

**Author** : Marc-Eliel Ouattara  
**GitHub** : [Marelispeedyone](https://github.com/Marelispeedyone)
