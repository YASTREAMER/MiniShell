# 🐚 MiniShell (C++)

A lightweight, minimal shell written in **C++**, developed as a passion project. This shell supports a few basic Unix-like commands and is designed to mimic basic terminal interactions with a personal touch — including home path `~` support and user-friendly path display.

---

## ✨ Features

* Basic built-in command support:

  * `ls` – List directory contents
  * `mkdir <dir>` – Create a new directory

    * `mkdir file\name` - Create a new dir with space in the folder name.
  * `rm <file>` – Remove files
  * `rm -rf <dir>` – Recursively remove directories (with `-rf` flag only)
  * `pwd` – Print current working directory
  * `cd <path>` – Change directory

    * Supports `~` as a shortcut for the home directory (e.g., `~/folder`)
  * `echo <text>` – Print text to the terminal

    * Currently supports plain text only (no variable expansion yet)
  * `quit` – Exit the shell
* Path shortening: Displays paths starting from home as `~/...` instead of full absolute path
* Color customization: Shell prompt supports color customization via a config file

---

## 🛠️ Getting Started

### Prerequisites

* A C++ compiler (e.g., `g++`)
* A Unix-like environment (Linux, macOS)
* `make`

### Build

```bash
make && ./build/MiniShell
```

---


## 🎨 Configuring Prompt Color in MiniShell

MiniShell supports customizing the prompt color via a simple config file. Here's how you can set it up:

### ✅ Configuration File Details

* 📁 **Location**: The configuration file is automatically generated and located at:

  ```
  ~/config/.config
  ```

* 🎨 **Format**: The file uses a key-value format to define the prompt color:

  ```
  colour = #e807b4
  ```

  > Use any valid **hex color code** (e.g., `#ff0000` for red, `#00ff00` for green, `#e807b4` for pink, etc.).

### 🔁 Applying Changes

To apply your color customization:

1. Open the config file in an editor:

   ```bash
   nano ~/.config/minishell/.config
   ```

2. Set the `colour` value to your desired hex color:

   ```
   colour = #00ffee
   ```

3. **Restart MiniShell** to see your changes reflected in the prompt.

---

## 🤔 Why Make This?

This shell is **not** intended to be a replacement for Bash, Zsh, Fish, or any other mature shell. It’s a **learning project**, created for fun and personal growth.

I know it’s far from optimized and is missing many features — but that’s okay! The goal here is to explore how shells work under the hood and enjoy building something from scratch in C++.
