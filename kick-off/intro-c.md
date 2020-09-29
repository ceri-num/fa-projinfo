#  Introduction to C

## A little bit of history

### C and C++: at the beginning

- [**1972**] - Developed in parallel to UNIX 
    * UNIX: Operating System multi-task  and multi-user (le shell)
    * Dennis Ritchie and Ken Thompson
    * Come after the language B, brings notably the notion of types
- [**1978**] The C Programming Language (the book)
    * Dennis Ritchie et Brian Kernighan
- [**1979**] C with classes (Will become C++)
    * Bjarne Stroustrup (After his PhD Thesis)
- [**1987**] GNU Compiler Collection (GCC) support C++
    * It is the first (natively)
    * Today: GNU project C and C++ Compiler

### Norm o C

- [**1983**] group creation part of ANSI
    * American National Standards Institute
- [**1989**] ANSI C or C89 (with minor evolution)
- [**1990**] adoption of C89 by ISO (C90)
    * International Organization for Standardization
- [**1999**] New evolution of the ISO norm (C99)
    * Variable size table, increments of floating point variables ...
    * Increase of the standard library
- [**2011**] New evolution of the ISO norm (C11)
    * Multi-thread, generic type...
 
### C++ norm evolves in parallel:
- C++98, C++03, C++11 (et C++14)

Sources : [fr.wikipedia.org](https://fr.wikipedia.org/) - [en.wikipedia.org](https://en.wikipedia.org/)

---

## Philosophy


### Language C and C++


Close to the machine, more or less expressive

![](resources/ccpp.svg)

An imperative programming language:

```c
...
Instruction;
instruction;
instruction;
...
```

---

### Main differences in C++

Addition | Limit
---------|--------
**+** Notions of POO             | **-** Not supported on all hardware architectures
**+** Templates and STL          | **-** Not the same strictness as other object languages
**+** Still close to the machine | **-** Different behaviors fct(compiler, architectures)

---

## Online resources

### Understand with Wikipedia :

* C (langage) : [C - fr](https://fr.wikipedia.org/wiki/C\_\%28langage\%29) - [C en](https://en.wikipedia.org/wiki/C\_\%28programming\_language\%29)
* C++ : [C++ - fr](https://fr.wikipedia.org/wiki/C\%2B\%2B)
* Programmation impérative : [Programmation impérative](https://fr.wikipedia.org/wiki/Programmation\_imp\%C3\%A9rative)
* GCC : [GNU Compiler Collection](https://fr.wikipedia.org/wiki/GNU_Compiler_Collection)
* ...

### Courses, tutorials, forums :
* [c-faq.com](http://www.c-faq.com/)
* [zentut.com - c-tutorial](http://www.zentut.com/c-tutorial/)
* [cplusplus.com](http://www.cplusplus.com/)
* [developpez.com C](http://c.developpez.com) et [C++](http://cpp.developpez.com/)
* [stackoverflow.com](http://stackoverflow.com)
* ...

---

###  Tools :

- GNU_Compiler_Collection
  * Windows: Minimalist GNU for Windows (with GCC) : [MinGW](http://mingw.org/)
- IDE (Integrated Development Environment) Dédié
  * OS independent : [codeblocks](http://www.codeblocks.org/)
  * IDE Linux : [kdevelop](https://www.kdevelop.org/)
  * IDE Windows : [Visual-Studio](http://www.microsoft.com/france/visual-studio/)
- IDE Générique
  * **Visual Studio Code** 
  * ATOM
  * ...
- Debugger:
  * Build Automation: Make, CMake 
  * Debugger: GNU Debugger [GDB](https://www.gnu.org/software/gdb/) ([possible UI](https://www.gdbgui.com/))
  * Automatic test: Answer on [stackoverflow](https://stackoverflow.com/questions/65820/unit-testing-c-code#65845)

---