---
marp: false
---

# C in short:

## First C program

### Hello, world: On the internet...

[Wikipedia](https://en.wikipedia.org/wiki/C\_\%28programming\_language\%29\#.22Hello.2C\_world.22\_example) - [Zentut](http://www.zentut.com/c-tutorial/c-hello-world/) - [Stackoverflow](http://stackoverflow.com/questions/12355758/proper-hello-world-in-c\#12355759)

---

### Hello, world

- Create a new work directory (on P)
- Edit a text file *hello.c* (SourceCode/notepad++)

```c
#include <stdio.h>

int main()
{
  puts("Hello World\n");
  return 0;
}
```
- **1** - Call to the library ``Standard Input/Output''
- **3** - Declaration of the ``main'' function (program entrance)
- **4-7** - Implementation of the function : block of instructions
- **5** - Posting to the standard output
- **6** - Returned value by the program (0, it's ok)

**ToDo**: Difference between *puts* and *printf* ?

---

## Exécutable

### Compile with GCC sous GNU Bash

*GNU* (GNU is Not Unix) an Operating System open created in 1983.

Few commands:

- **ls**: list directory contents (```ls -la /global/path```)
- **cd**: change directory (```cd relative/path```)
- **cp**: copy paste (**mv** to  move)
- **rm**: remove (**rmdir** for directories)
- **man**: manuals of commands and libraries ('Q' to quit)

And many others: *apropos*, *whereis*, *clear*, *egrep*, ...

**MSYS** and **MSYS2** or **Cygwin** offer an alternative under windows.

---

### Compile with GCC

Compile source code to target machine: 

```bash
gcc -c [FLAGS] file.c
```

Some flags:

- *-std=c99* : Use C99 standard 
- *-Wall -Wextra* : Verbose compilation with warning messages (all and more)
- *-gdb* : unable gdb to interact with the generated program
- ... : code optimization, compute for a diferent target machine, ... 

Link component: 

```bash
gcc -o program file.o file2.o file3.o ... [LIBS]
```

Example :

```bash
gcc -c -std=c99 -Wall -Wextra hello.c
gcc -o hello hello.o
./hello
```

---


## Language elements

### First instructions in *C*


```C
// Declaration:
//--------------
Type nomVariable;

// Assignment:
//--------------
nomVariable = expression;

// Call of function:
//--------------
functionName( parameter1, parameter2, ... );
expression operator (expression ... );
```

Example:
```C
int a;
int b= 3;
a= (b + 6) / 2;
printf("%i + 6 / 2 = %i", b, a);
sleep(3); // Sleep(3000) under Windows
```

---

### Basic types

- *int*: standard integer
- *unsigned int*: unsigned integer (~ absolut value)
- *short*, *unsigned short*: small integer
- *long*, *unsigned long*: long integer (double of int memory size)
- *long long*, *unsigned long long*: very long integer (double of long)

- *char*, *unsigned char*: character (eq. very small int)

- *float*: standard floating point number
- *double*: more precise than float
- *long double*:very precise floating point number (double of double)

---

### Functions

regroups a block of instructions [return one value]
```C
// Declaration :
//--------------
type myFct ( type param1, type param2, ...);

// Instanciation :
//----------------
type myFct ( type param1, type param2, ...)
{
  instruction;
  instruction;
  return expression;
}

// Call :
//--------
[var= ] myFct(var1, var2, ... );
```

---

### Tables

```C
// Declaration :
//--------------
type tabName [ N ]; // number of N elements

// Declaration and assignment :
//-----------------------------
type nomTab [ N ] = {var1, ..., varN};

// one element :
//--------------
... tabName[i] ... ;
```

---

### Control structures - Logic

Attention: no boolean, only integers are manipulated.

```C
if ( condition ){
  instructions;
}
else {
  instructions;
}

/*
condition : int/short ... : (0)false or true
condition && condition : and
condition || condition : or
!condition : no
( condition ) : priority
comparaison operators : == < > <= >=
*/
```

### Control structures - switch
  
You can see it as a succesion of several ``if ( == )''

```C
switch ( expression ){
  case value1 :
    instructions;
    break;

  case value2 :
      ...

  case valueN :
    instructions;
    break;

  default :
    instructions;
    break;
}
```

--- 

### Control structures - loops

Executing several-time a sucession of instriuctions:

```C
while ( condition )
{
  instructions;
  instructions;
  ...
}

do
{
  instructions;
  instructions;
  ...
}while ( condition )

for ( initialization ; condition ; iteration )
{
  instructions;
  instructions;
  ...
}
```

---


### Specific programe variables

- struct: No classes, but the possibility to group variables together.
```C
struct my_structure{
  type1 name_variable1;
  type2 name_variable2;
  type3 name_variable3;
  ...
};
```
- enumeration: define a finite domain
```C
enum color {
  blue= 0, red, green
};
```
- typedef: define new types.
```C
typedef description name_of_the_new_type;
```

---

### Example:

```c
#include <stdio.h>
#include <math.h>

struct complex{
  double a;
  double b;
};

double modulus( struct complex c );

int main(){
  struct complex aComplex;
  aComplex.a= 2.3;
  aComplex.b= 5.7;
  printf( "module: %lf\n", modulus(aComplex) );
  return 0;
}

double modulus( struct complex c ){
  return sqrt( c.a*c.a + c.b*c.b );
}
```

---

### Example (typedef):

```c
#include <stdio.h>
#include <math.h>

struct complex{
  double a;
  double b;
};

typedef struct complex Complex;

double modulus( Complex c );

int main()
{
  Complex aComplex;
  aComplex.a= 2.3;
  aComplex.b= 5.7;
  printf( "module: %lf\n", modulus(aComplex) );
  return 0;
}

double modulus( Complex c ){
  return sqrt( c.a*c.a + c.b*c.b );
}
```
