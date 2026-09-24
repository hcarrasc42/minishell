# minishell

A Unix shell built from scratch in C: parsing, pipes, redirections, built-ins, and signal handling.

The project that forced me to actually understand how a process tree works, not just use one — implementing pipelines, `>` / `<` / `>>` / `<<` redirections, built-ins (`cd`, `echo`, `export`, `unset`, `env`, `exit`, ...), and signal handling (`Ctrl-C`, `Ctrl-\`, `Ctrl-D`) that behaves the way a real shell's does, including the edge cases bash itself gets particular about (heredocs, quoting, exit codes).

**Built with:** C · process management · signal handling

---

A pair project completed as part of the core curriculum at [42 Urduliz](https://42urduliz.com). Part of my [GitHub profile](https://github.com/hcarrasc42).
