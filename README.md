# Embedded system monitor
System monitor for embedded applications as the first project i do to learn programming.
October/2024
Age: 15
High School

## Philosophy
This is my very first coding project for learning to code (I had no knowledge before) and it aims to the optimization an embedded system needs. Define "optimization" as the less resources the process needs to work and the most useful and prior data to be analyzed.  
As this is a compiled language, I focus on minimalist in the compiled executable.

## Instalation
This is a basic C program that reqires standard C libraries in **gcc** and being a *linux based system* to work. Depends your system, you might ensure being able to open **proc** files (*/proc*); you can try using `cat /proc/stat` , for example.
It can be complied with a simple
```bash
gcc main.c -o greatProgram
```

## Configuration

### Configuring scripts
I am not incluiding none of this in the repository because you might want to set your own scripts based on your needings, nevertheless, I recommend using this scripts.  
  
For compiling and moving the executable to anywhere:  
```bash
gcc -o configEXE config.c && ./configEXE && rm configEXE && \
    gcc -o main main.c \
    && echo "The header files looks like: " && cat config.h && rm config.h
```
You can use temporary directories if do not want to dirty your workspace. I used the following while developing:  
```bash
mkdir -p .tmp
gcc $1 -o .tmp/output && ./.tmp/output && rm -f .tmp/output && rmdir .tmp
```
use **main.c** or **config.c** as an argument (**sh gcc.sh main.c**) for running them isolated, they will me executed and removed when finish, and you will not see any change in your directories.

### Selecting Data Unit
You can select which data unit do you want to be displayed in the main program when printing memory information:  
Binary  Decimal  
KiB     KB  
MiB     MB  
GiB     GB  
  
The default unit (if the main does not find a header) is GiB.  
You can select it by compiling and running the **config.c** program, it will ask you for the unit by a CLI menu.

## Working
### Main program
The code opens /proc/  
*meminfo    (for RAM)
*stat       (for CPU)
As the source of data. It is got, tokenize and processed from a characters array to intagers for procesing data into readable statistics.

### Configuration
#### To get data unit
The configuration script will calculate the correct denominator (also called divider) to convert the original KB expresed by the /proc system. The denominator is defined in a new header file **config.h** for avoiding using variables that uses memory or reading configuration texts that consumes resources wwhen reading and storing data. This way the data procesing is given to the compiler and the computer that will compile the program before its use in an embedded system.  
The program follows the next math:  

For binary:  
$$\frac{Kb}{1024^n * 1000}$$  

This converts KB into bytes and divide it by a power of **1024** that is represented as **n**. This **n** is what we select in the configuration script.  

## Notes
Today, that is all.  
To do:

- Add PID monitoring.

## Aditional information
Software used:
- Kitty Terminal
- Neovim
- GCC 
- Valgrind
- Bash script for automating execution

## License
This project is licensed under the unlicense license.
I do not care about code licenses, my codes are yours.
## Contact
Created by Alan  
(https://github.com/AlanYahpi)

