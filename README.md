# Simple Shell

## Introduction

This project involves developing a simple shell for Linux/macOS. The shell supports the following features:

- **Builtin Commands**: `pwd`, `cd`, `exit`, `set`, `unset`, `echo`, `help`, `history`
- **Shell Variables**: Create, modify, and expand variables (`$VAR`)
- **External Command Execution**: Execute external commands by searching directories in `PATH` or using direct pathnames.
- **History Feature**: Store and display the last 500 commands entered by the user.

## Shell Workflow

The shell operates in an interactive loop:

1. **Prompt the user** with `mysh>`.
2. **Read the command line** from the user.
3. **Parse the command** into command and arguments.
4. **Check for Builtin Commands**:
    - If it’s a builtin, execute it with internal logic.
    - If not, attempt to execute it as an external command by creating a child process (`fork`).
5. **Store the command** in a history buffer for future recall.
6. **Repeat** until the user types `exit` or an EOF condition occurs.

## Shell Variables

### 1. Internal Key-Value Pairs
- The shell maintains a dictionary of variables.
- **Set Command**: `set NAME=VALUE` adds or updates a variable.
- **Unset Command**: `unset NAME` deletes a variable.
- **Variable Expansion**: If a command token starts with `$`, it expands to the corresponding variable value.

### 2. Builtin Variables (e.g., `PWD`)
- The shell tracks the current working directory (`PWD`).
- When `cd` is used, `PWD` is updated.
- Commands like `pwd` retrieve and print the `PWD`.

## Builtin Commands

### 1. `set`
- Creates or updates a variable.
- Usage: `set NAME=VALUE`
- Lists all variables if called with no arguments.

### 2. `unset`
- Removes a named variable.

### 3. `echo`
- Prints text and performs variable expansion.
- Example: `echo hello $USER`

### 4. `pwd`
- Prints the current working directory (`PWD`).

### 5. `cd`
- Changes the current directory and updates `PWD`.

### 6. `help`
- Lists available builtin commands and provides simple usage notes.

### 7. `history`
- Displays previously entered commands (up to 500).
- Usage: `history` to display all, or `history N` to display the last `N` commands.

### 8. `exit`
- Ends the shell session.

## History Feature

- **Circular Buffer**: Stores the last 500 commands. Once the buffer is full, the oldest entry is overwritten.
- **Display History**: The `history` command shows all or part of the stored commands.

## External Commands

When a command is not a builtin:

1. **Check for Direct Path**: If the command contains a slash (e.g., `./command`), run it directly.
2. **Search `PATH`**: If no slash, search for the command in the directories specified in the `PATH` environment variable.
3. **Fork and Execute**: Create a child process to run the command. If execution fails, an error message is displayed.
4. **Parent Process**: The parent waits for the child to finish, unless background jobs are implemented.

## Step-by-Step Shell Cycle

1. Display prompt (`mysh>`).
2. Read the command line.
3. Store the line in the history buffer.
4. Parse the command into tokens (command and arguments).
5. Expand variables (e.g., `$USER`).
6. Check if the command is a builtin:
    - If a builtin, execute it.
    - If an external command, fork and execute.
7. Return to the prompt for the next input.

## Suggestions for Implementation

- **Memory Management**: Allocate and free memory for command history to prevent leaks.
- **Circular Buffer**: Track the position in the history buffer, overwriting the oldest command once 500 commands are stored.
- **Error Handling**: Print error messages if `cd` fails or if an external command is not found.
- **Optional Features**: Implement advanced features like redirection (`>`, `<`), piping (`|`), background jobs (`&`), persistent history, and advanced variable expansions.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
