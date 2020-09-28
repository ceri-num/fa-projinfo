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

Source : \url{https://en.wikipedia.org} -\url{https://fr.wikipedia.org}

---

### Norm of C

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

Sources : \url{https://fr.wikipedia.org/} - \url{https://en.wikipedia.org/}

---

## Philosophy


### Language C and C++


Close to the machine, more or less expressive

![](resources/ccpp.pdf)

An imperative programming language:

```c
...
Instruction;
instruction;
instruction;
...
```
 
Main differences with C++

Addition | Limit
---------|--------
[$+$] Notions of POO             | [$-$] Not supported on all hardware architectures
[$+$] Templates and STL          | [$-$] Not the same strictness as other object languages
[$+$] Still close to the machine | [$-$] Different behaviors fct(compiler, architectures)

