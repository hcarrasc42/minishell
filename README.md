This project was built as part of the 42 cursus by hcarrasc42 and ruramire.

# minishell

> _"As beautiful as a shell." — and half as forgiving._

A minimalist reimplementation of a Unix shell in C, inspired by `bash`. It reads
a command line, tokenizes and expands it, parses it into a table of commands
connected by pipes and redirections, and executes them — built-ins in-process,
external programs via `fork` + `execve` — while handling quoting, environment
variables, signals, and exit statuses the way an interactive shell should.

![Language](https://img.shields.io/badge/language-C-blue?style=flat-square)
![Standard](https://img.shields.io/badge/norm-42-black?style=flat-square)
![Libraries](https://img.shields.io/badge/libs-readline-informational?style=flat-square)

## 📖 About

A shell is the program that sits between a human and the operating system: it
reads a line of text and turns it into processes, file descriptors, and system
calls. `minishell` recreates that pipeline from scratch, restricted to a subset
of `bash`'s behavior and to the functions allowed by the 42 Norm.

The program runs an interactive read–eval loop:

1. **Read** a line with GNU `readline` (with history).
2. **Tokenize** it into a linked list of typed tokens (commands, arguments,
   pipes, redirections), tracking single/double quoting per token.
3. **Expand** environment variables (`$VAR`, `$?`), respecting quoting rules.
4. **Validate** the token syntax (e.g. no dangling pipe or redirection).
5. **Parse** the tokens into a command table: a list of simple commands, each
   with its `argv`, its redirections, and its position in the pipeline.
6. **Execute** the table, wiring pipes between commands and applying
   redirections, then wait for children and record the exit status.

## ✨ Key Features

- **Interactive prompt** with line editing and command history via `readline`
  (`readline`, `add_history`).
- **Tokenizer** that classifies input into typed tokens — `TOKEN_CMD`,
  `TOKEN_ARG`, `TOKEN_PIPE`, `TOKEN_GREAT` (`>`), `TOKEN_GREATGREAT` (`>>`),
  `TOKEN_LESS` (`<`), `TOKEN_LESSLESS` (`<<`) — and records whether each token
  was single- or double-quoted.
- **Quote handling:** single quotes preserve their contents literally; double
  quotes allow variable expansion but suppress word-splitting.
- **Environment variable expansion**, including the special `$?` for the exit
  status of the last command, expanded only where quoting permits.
- **Pipelines** of arbitrary length: each command is connected to the next with
  an anonymous `pipe()`, the read end handed forward to the following command.
- **Redirections:** input (`<`), output/truncate (`>`), append (`>>`), and
  heredoc (`<<`), applied in the child before `execve`.
- **Built-ins:** `echo` (with `-n`), `cd`, `pwd`, `export`, `unset`, `env`,
  `exit` — each reimplemented from scratch.
- **Parent vs. child built-ins:** built-ins that mutate shell state (`cd`,
  `export`, `unset`, `exit`) run in the parent process so their effect persists;
  the rest can run in a child within a pipeline.
- **Signal handling** faithful to an interactive shell: `Ctrl-C` (`SIGINT`)
  redraws a fresh prompt on a new line, `Ctrl-\` (`SIGQUIT`) is ignored at the
  prompt, and both are set up with `sigaction`.
- **Correct exit statuses:** `$?` reflects the child's `WEXITSTATUS`, `128 + n`
  when a child is terminated by signal `n`, and `127` for command-not-found.
- **Own environment copy:** `envp` is duplicated at startup and managed with a
  small dynamic string-array API (`add_str_to_array`, `del_str_from_array`,
  `set_env`, …), so `export`/`unset` never touch the real `environ`.

## 🛠 Technologies

| Component | Detail |
|-----------|--------|
| Language | C (compiled with `gcc`, `-Wall -Werror -Wextra`) |
| Line editing | GNU `readline` (`readline`, `add_history`, `rl_*`) |
| Process control | `fork`, `execve`, `waitpid`, `pipe`, `dup2`, `close` |
| Signals | `sigaction`, `signal` (`SIGINT`, `SIGQUIT`) |
| Environment | custom copy of `envp` + dynamic string-array helpers |
| Build system | GNU Make (`all`, `clean`, `fclean`, `re`) |
| Support library | `libft` (bundled; own `libc` reimplementations) |

## 🏗 Architecture

### Core data structures

| Struct | Role |
|--------|------|
| `t_mini` | Top-level shell state: current `readline` buffer, the environment copy (`envp`), and the prompt. |
| `t_token` | One lexical token: its `type`, its string, and single/double-quote flags. |
| `t_cmd` | A whole command line: the number of commands, a list of `t_simple_cmd`, and a background flag. |
| `t_simple_cmd` | One command in the pipeline: `argc`/`argv`, detected built-in type, its file descriptors, its list of redirections, its `pid`, and its `pipe_fds[2]`. |
| `t_redirection` | One redirection: its type (`<`, `>`, `>>`, `<<`), target file, and fd. |

A single global variable, `g_exec_ret` (the last exit status), is used — the one
global the 42 Norm permits for a minishell, needed because a signal handler must
communicate the status without extra parameters.

### Pipeline flow

```
main()
  └── initvar()                 — duplicate envp, zero state
  └── setup_parent_signals()    — SIGINT handler, SIGQUIT ignored
  └── loop: ft_read(state)
        └── readline()          — read one line (+ history)
        └── process_readline()
              ├── prompt_to_tokens()      — lexer: string → typed token list
              ├── expand_token_strings()  — $VAR / $? expansion (quote-aware)
              ├── validate_syntax_tokens()— reject malformed token sequences
              ├── tokens_to_cmd_table()   — parser: tokens → t_cmd / t_simple_cmd
              ├── exec_cmd_table()         — run the pipeline
              └── free_cmd_table() / free_tokens()
```

### Execution model

For each simple command, `exec_cmd()`:

1. Calls `create_pipe()` — if another command follows, opens a `pipe()` and
   points this command's `fd_out` at its write end.
2. If the command is a **parent built-in** (`cd`/`export`/`unset`/`exit`), runs
   it in-process so its state change survives.
3. Otherwise `fork()`s; the child (`child_pipe` → `child_start`) wires its
   `fd_in`/`fd_out` with `dup2`, applies redirections, and either runs a
   built-in or `execve`s the external program.
4. `parent_pipe()` hands the pipe's read end to the next command and closes the
   spent write end; `wait_for_child()` `waitpid`s and records `g_exec_ret`.

### Concurrency & signal safety

- While a child runs, the parent ignores `SIGINT`/`SIGQUIT` and restores its
  interactive handlers afterward, so `Ctrl-C` interrupts the running command,
  not the shell.
- Exit status conventions match `bash`: `WEXITSTATUS` on normal exit,
  `128 + WTERMSIG` on signal, `127` when the binary can't be found.

## 🚀 How to Run

### Dependencies

`minishell` links against **GNU readline**. On macOS the provided `Makefile`
expects it under `~/.brew/opt/readline`; on Linux, install `libreadline-dev` and
adjust the `INCLUDES`/`LDFLAGS` paths accordingly.

### Compile

```sh
make
```

This builds the `minishell` binary in the project root.

### Run

```sh
./minishell
```

Then type commands at the `minishell$> ` prompt:

```sh
minishell$> echo hello world
hello world
minishell$> ls -la | grep .c | wc -l
minishell$> export NAME=42 && echo $NAME
minishell$> cat < input.txt | sort > output.txt
minishell$> cat << EOF
minishell$> exit
```

### Cleanup

```sh
make clean    # remove object files
make fclean   # remove object files and the binary
make re       # full rebuild
```

## 📂 Project Structure

```
minishell/
├── Makefile
├── minishell.c                 # Entry point: init, signal setup, read loop
├── lib/
│   └── minishell.h             # All structs, enums, and prototypes
├── libft/                      # Bundled libc reimplementations
└── src/
    ├── ft_read.c               # Read → tokenize → expand → validate → exec → free
    ├── array.c                 # Dynamic string-array helpers (env management)
    ├── malloc.c  error.c  signals.c
    ├── token/                  # Lexer, expansion, syntax validation, token types
    │   ├── token.c  expand.c  validate.c  type.c  free.c
    ├── command/                # Parser + execution
    │   ├── table.c  command.c  add.c  exec.c  exec_child.c
    ├── redirection/            # Redirection parsing and application
    │   ├── redirection.c  apply.c
    ├── built_ins/              # echo, cd, pwd, export, unset, env, exit, path
    └── str/                    # String scanning helpers (is/skip/str)
```

## 💡 What This Project Demonstrates

- **Building an interpreter pipeline** end to end: lexing, expansion, syntax
  validation, parsing into an intermediate representation, and execution.
- **Unix process control:** `fork`/`execve`/`waitpid`, anonymous pipes, and file
  descriptor plumbing with `dup2`/`close`.
- **Correct shell semantics:** quoting rules, environment expansion, `$?`, exit
  status conventions, and the parent/child built-in distinction.
- **Signal handling** with `sigaction` for a responsive interactive prompt.
- **Manual memory and resource management** in C, with no leaks across the
  read–eval loop, under the 42 Norm (strict style, a single global variable).
- **Working in a pair**, splitting a large codebase across well-defined modules.

## Note

Group project, done together with a teammate (**ruramire**).
