# Start-Up & Shut-down

Welcome to the world of the "chicken and egg" problem! 

## Starting the Game
When a game starts, the first thing it does is to be sure it can correctly run, load resources and prepare the data structures it will use.

A recommended game start-up could be as follow:
* Check system resources, a.k.a drive space, memory, input/output devices
* Check the game's files integrity
* Initialize your main random number generator (<-RNG is ALWAYS used in game)
* Initialize your string subsystem (doing it early allow to display error msg) 
* Initialize your memory cache
* Create your windows
* Initialize the audio system
* Load the player's game options and saved game files
* Create your drawing surface
* Perform initialization for game systems, *e.g.* AI, physics, collision...

All in all, your goal is to perform a good, least dependent as possible, initialization chain.

Think deeply of a good organization in order to, hopefully, limit your problem in this area.

### Always fix leaks!
A leak happens when a resource is not properly deallocated during the runtime of your program, consequently taking memory space and virtual/physical resources from your computer.
Leaks can quickly become dramatic, leading your program to be unexpectedly killed by your OS to preserve its integrity or, in the good ol' time some BSOD.

Your best friend here is [valgrind](https://valgrind.org/). It can automatically detect many memory management and threading bugs, and perform great profiling.
To investigate memory leak, instead of running your program in CLI like
```bash
monprogramme arg0 arg1
```
You can invoke your program inside the valgrind context.
```bash
valgrind --leak-check=yes monprogramme arg0 arg1
```

A word of caution though, your program will run slower (~ 20 to 30 times) and will use a lot of memory for the profiling.

## Shuting Down the Game

Exceptions aside, deallocation of ressources should be performed in the **reverse order of which they were created**. This is particularly true for complex and dependant resources.

* Correctly catch the game close event (or any events unusing allocated resources) and system shuting down the application (*e.g.* El famoso rage quit Alt+F4)
* Data structure should be traversed and freed
* Destructor-like functions should exist for data structure
* Define an `onClose()` function handling all the deallocation in the correct order, and well documented

### Word of caution
If your initialization is not well performed, deallocation could fail dramatically! Thus the need to create a good pipeline regarding the creation of your game's elements.
When multiple dependencies exist, lean on a reference counting mechanism (*e.g.* pool counter) to hold on to resources until they are not needed anymore.
