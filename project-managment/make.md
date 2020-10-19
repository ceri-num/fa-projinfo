# Construction du projet

Comme la plupart des langages le C et le C++ autorisent d'éclater le code sur plusieurs fichiers. 
Il est alors possible de compiler séparément l'ensemble des sources puis de les lier ensemble pour générer le programme exécutable.

Plusieurs solutions existent pour automatiser cette procédure.

## Rappel des conventions en C et C++

Par convention en C et C++ on sépare les déclarations dans des fichiers Header (*file.h*) des implémentations dans des fichiers de code (*file.c* ou *file.cpp*).

Les fichiers d'en-tête ont vocation à déclarer les structures, les nouveaux types, les déclarations de fonctions qui seront implémentées ailleurs dans le programme (les classes en *C++*).

Par exemple: 

```c
struct Str_NetWorld {
    int size;
    Node * nodes;
};
typedef struct Str_NetWorld NetWorld;

// Constructor / Destructor
NetWorld * NetWorld_new(int aSize);
void NetWorld_delete(NetWorld * self);
```

En aucun cas, on ne trouvera d'instanciation de variable (on peut inclure plusieurs fois un même *header*, mais on ne peut pas instancier plusieurs fois une même variable).

Enfin, il faut protéger les *headers* d'inclusion multiple en usant d'[instruction aux préprocesseurs](https://fr.wikipedia.org/wiki/Pr%C3%A9processeur_C) comme suit:


```c
#ifndef NETWORLD_H
#define NETWORLD_H

....
Declarations....
...

#endif
```

Soit avec *#ifndef*, si la macro *NETWORLD_H* n'est pas défini on regarde les instructions qui suivent jusqu'au prochain *#endif* rencontré. 
Et la première action sera de définir la macro pour ignorer ce bloc de code si on repasse par là
(notamment dans un cadre d'inclusion en cascade et récursive *a.h* qui inclu *b.h* qui lui-même inclut *a.h*).

Ensuite, il est possible de décomposer les sources dans autant de fichiers *.c* que désiré.



## Générer un exécutable

Imaginons que nous avons 3 fichiers sources: 'A.h', 'A.c' et 'main.c', on va pourvoir compiler 'A.c', 'main.c' puis générer le programme:

```bash
gcc -c A.c
gcc -c main.c
gcc -o prog A.o main.o
```

Si on effectue une modification dans *'A.c'* on va pourvoir re-compiler que partiellement notre projet:

```bash
gcc -c A.c
gcc -o prog A.o main.o
```

En d'autres termes, il est possible de recompiler uniquement les sources modifiées pour générer à nouveau le programme.
Cette optimisation est particulièrement bienvenue si on manipule un projet de plusieurs milliers de lignes de code demandant plusieurs minutes de compilations.
Attention cependant, les header étant partagé, leur modification implique générale de nombreuse recompilation. 
Ici on peut imaginer que *'A.h'* est partagé avec *'A.c'* et *'main.c'*.
Modifier *'A.h'* implique donc de recompiler *'A.c'* et *'main.c'*.

La gestion de ces conditions est fastidieuse. 
Elle est généralement laissée à la charge de l'IDE du développeur qui utilise des outils plus ou moins génériques.



## Avec un MakeFile

La commande *'Make'* qui s'appuie sur un fichier de configuration *'MakeFile'* est le premier de ces outils génériques de construction de projet automatisé.
Pour du *'C'*, le *'MakeFile'* liste l'ensemble des consignes de compilations sous la forme de règles: 

```make
Cible: condition1 condition2
    commande à exécuter
```

Avec une règle spéciale *'all'* qui marque le point d'entrée par défaut.

Pour notre exemple on aurait:

```make
all: A.o main.o
    gcc -o prog A.o main.o

A.o: A.h A.c
    gcc -c A.c

main.o: A.h main.c
    gcc -c main.c
```

Dans le cas où les règles pointent des fichiers ou des répertoires dans l'arborescence du projet,
une règle est déclenchée si la date de modification d'un des fichiers est postérieure à la cible. 
Soit, la règle pour construire *'A.o'* sera déclenché si: `(date(A.o) < max( date(A.h), date(A.c)) )`.

*MakeFile* autorise la définition de variables et inclut un certain nombre de macros qui permet de factoriser sa définition.
Un premier point d'entrée pour aller plus loin: [Wikipedia](https://fr.wikipedia.org/wiki/Make).



## Plus fort: CMake

La limite de *'Make'* réside dans sa capacité quasi nulle à gérer les conditions: adapter les règles à l'OS cible, au compilateur utilisé, à la présence ou non de librairie...
*CMake* est certainement la solution la plus répandue pour pallier cette limite.

*CMake* comme *Make* repose sur un fichier de configuration qui guide la construction du projet *'CMakeLists.txt'*.
Cependant, celui-ci est construit sur une modalité déclarative.
On déclare à l'aide de fonctions le nom du projet, les dépendances, ce qui doit être construit, etc.

Exemple minimal:

```cmake
project(my_projetc LANGUAGES C)
cmake_minimum_required(VERSION 3.10)

add_exécutable(prog A.c main.c)
```

*CMake* se charge ensuite de construire les règles de génération de votre projet en fonction de la configuration de la machine (sous forme de *MakeFiles*).
En général, on se place dans un répertoire *'build'* pour éviter de polluer le répertoire de travail. Soit dans un terminal correctement configuré:

```bash
mkdir build
cd build
cmake ..
make 
```

De nouveau, [Wikipedia](https://fr.wikipedia.org/wiki/CMake) est votre amie pour aller plus loin sur la prise en main de *CMake*.


## Aller plus loin: générer des librairies


Enfin, vous avez la possibilité de créer vos propres librairies et de venir les inclure au besoin dans vos projets, à la manière de RayLib.

**À la main**, une librairie dite static n'ait jamais que le regroupement de plusieurs fichiers compilés *'.o'*. archivé dans un fichier *'.a'* avec la commande *'ar'* sous linux par exemple.
```bash
ar rcs A.a A1.o A1.o
```

Une librairie dite *'shared'* - partagé - en *'.so'* sous linux ou *'.dll'* sous Windows sera généré avec le compilateur en applicant les paramètres adéquate:

```bash
gcc -shared A.o B.o -o libA.so
```

À la compilation d'un programme , le contenue de la librairie static est ajouté à l'exécutable créer contrairement à une librairie dite 'shared'. 
Dans ce second cas, les éléments de la librairie ne sont chargés qu'à l'exécution du programme.
Pour gcc il faut regarder les paramètres -l et L pour inclure une librairie (ici se serais -lA).

**Pour CMake**, on ajoutera simplement la déclaration d'une librairie avec *'add_library'* que l'on pourra inclure dans un programme avec *'target_link_libraries'*.

```cmake
project(my_projetc LANGUAGES C)
cmake_minimum_required(VERSION 3.10)

add_library(A A1.c A2.c)
add_executable(prog main.c)
target_link_libraries(prog A)
```
