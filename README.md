# penCil

Text editor made mostly with the C programming language, inspired by the **kilo** project, which is also a C-based text editor, created by developer *antirez*, in 1000 LOC (lines of code).
Repo for kilo is ![here](https://github.com/antirez/kilo) if you wanna check it out.

The difference between penCil and kilo is merely the fact that its creation will be more modular, as in spread out among more files, as kilo was created in just one big C file (kilo isn't really big, as for the size of its codebase, it's pretty lightweight).
There will be header files for declaration, other C files to add logic to functions declared by those headers, and *main.c* will tie everything together.

There will be a .txt file named **tokei** (which is a Rust-written CLI tool that lists the number of lines of code, comments, and blanks within a project directory, as well as amount of files in each language used.),
it will list out this project's codebase; I'll simply just paste the command output into the file. I'll try to update it every time I update code.
Tokei repo ![here](https://github.com/XAMPPRocky/tokei).

## How to Build

Note:
- penCil at the moment is Linux-exclusive due to dominant use of **POSIX** headers (termios.h, unistd.h), so make sure you have a Linux distro, or are using WSL (if using Windows).

```
make
./pencil
```

Simple! If you would like to clean up the compiled binary after, just use ```make clean```.
