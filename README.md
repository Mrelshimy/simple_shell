Project: Simple Shell

Description:
------------
Simple Shell is a program implemented in C.
It provides a command-line interface where users can enter commands,
which are then executed by the shell.
The project aims to demonstrate the basics of shell programming,
including command parsing, execution, and handling input/output.

Features:
---------
- Command execution: Users can enter various commands that the shell will execute.
- Basic command parsing: The shell can split the entered command into individual arguments.
- Input/output redirection: The shell supports input/output redirection using the '>' and '<' symbols.
- Background processes: Users can run commands in the background by appending the '&' symbol at the end.
- Built-in commands: The shell provides a few built-in commands such as 'cd', 'setenv', and 'unsetenv'.

Usage:
------
1. Compile the project using gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
2. Run the executable file.
3. Enter commands at the prompt and press Enter to execute them.
4. Use Ctrl+D to exit the shell.
