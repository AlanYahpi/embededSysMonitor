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

## Working
The code opens /proc/  
*meminfo    (for RAM)
*stat       (for CPU)
As the source of data. It is got, tokenize and processed from a characters array to intagers for procesing data into readable statistics.


## Notes
Today, that is all.  
To do:

- Implement configration sheet.
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
I don't care, I'll eat from my emeddedd systems hardware-software implementations, my codes are yours.
## Contact
Created by Alan  
(https://github.com/AlanYahpi)

