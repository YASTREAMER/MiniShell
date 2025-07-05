# 🐚 MiniShell (C++)

A lightweight, minimal shell written in **C++**, developed as a passion project. This shell supports a few basic Unix-like commands and is designed to mimic basic terminal interactions with a personal touch — including home path `~` support and user-friendly path display.

---

## ✨ Features

- Basic built-in command support:
  - `ls` – List directory contents
  - `mkdir <dir>` – Create a new directory
    - `mkdir file\name` - Create a new dir with space in the folder name.[^1]
  - `rm <file>` – Remove files
  - `rm -rf <dir>` – Recursively remove directories (with `-rf` flag only)
  - `pwd` – Print current working directory
  - `cd <path>` – Change directory
    - Supports `~` as a shortcut for the home directory
  - `quit` - Exiting the shell.
- Path shortening: Displays paths starting from home as `~/...` instead of full absolute path

[^1]: As of now when create a folder name with a space you have to use file\name and it whould not have gap. I will add support for the the more conventional file\ name in the future.

---

## 🛠️ Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++`)
- A Unix-like environment (Linux, macOS)
- Make 

### Build

```bash
make && ./build/MiniShell
```

## 🤔 Why Make This?

This shell is **not** intended to be a replacement for Bash, Zsh, Fish, or any other mature shell. It’s a **learning project**, created for fun and personal growth.

I know it’s far from optimized and is missing many features — but that’s okay! The goal here is to explore how shells work under the hood and enjoy building something from scratch in C++.
