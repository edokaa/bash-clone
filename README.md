# Bash Shell Clone in C
Welcome to our custom Bash shell clone project! This project aims to create a simple Bash-like shell using C programming. It was developed in collaboration between [@edokaa](https://github.com/edokaa) and [@sandra113](https://github.com/sandra113).

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)

## Introduction

In this project, we have implemented a simplified version of the Bash shell using the C programming language. This shell provides a basic command-line interface for users to interact with the underlying operating system.

## Features

- **Command Execution**: Execute commands entered by the user.
- **Input/Output Redirection**: Support for input and output redirection using `>` and `<`.
- **Piping**: Implement basic command piping using `|`.
- **Built-in Commands**: Include some built-in commands like `cd`, `pwd`, `echo`, `#`, `env`, etc.
- **Error Handling**: Handle errors gracefully and display informative error messages.
- **PATH Handling**: Handle the PATH variable.


## Getting Started

To get started with our Bash shell clone, follow these steps:

1. Clone this repository to your local machine:

    ```bash
    git clone https://github.com/edokaa/bash-clone.git
    ```
2. Navigate to the project directory:
    ```bash
    cd bash-clone
    ```
3. Compile the C code:
    ```bash
    gcc shell.c -o shell
    ```
4. Run the shell:
    ```bash
    ./shell
    ```

## Usage
Once you have the shell up and running, you can use it just like a regular command-line shell. Here are some examples:

- Run a command:
    ```bash
    ls -l
    ```
- Redirect input and output:
    ```bash
    cat input.txt > output.txt
    ```
- Use pipes:
    ```bash
    ls -l | grep .txt
    ```
