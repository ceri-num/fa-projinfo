# Contour du projet NetWorld

Sur la base du document éponyme, dans le [repertoire git](https://gvipers.imt-lille-douai.fr/fatus/networld/blob/master/project-outline.md) du projet.

Ce document regoupe l'ensemble des composants/briques/user-stories développées ou à developper pour completer le projet. Il sert pour le groupe pour visualisé ce qui est fait de ce qui reste à faire, pour identifié qui fait quoi, comme support aux refflexions sur ce que l'on peut ajouter et enfin dans la communication avec l'extérieur (les profs).

Sur chaque fonctionnalité adressée par le groupe, il est demandé d'identifier un ou deux contributeurs principaux (responsables de fait de la bonne réalisation des composants sous-jacents). Tout membre du gourpe doit être identifié comme contributeur principal (mainDeveloper), sur une des fonctionnalités. Tout contributeur qui alimente significativement la fonctionnalité (prise en charge d'un des composants) est identifié comme développeur secondaire.

Pour travailler en binôme sur un composant, nous vous invitons à vous utiliser sur le pluggin *LiveShare* de *VSC*.

Est oui en effet, toutes les fonctionnalités ne pourront pas être adressées dans le temps impartie au projet.

## Fct.1 - Project Framing.


This functionality cover a framework for the team of developers.


- Developers can communicate with others (discord, ...) - DONE
- A developer can share a working directory (git, gitlab, ...)
  1. Identification sur gviper (le gitlab de l'école)
  1. Création d'un groupe avec référence à la couleur (exemple: Pink-Panter) 
  1. Intégration des menbres
  1. Création d'un projet comme clone de NetWorld
  1. Inviter les @profs et valider avec eux que ça fonctionne.
- Hello World’s programmes can be compiled and executed.
- Everyone can refer to documentation.
- A first realize by merging contribution is generated.
- A solution for Unit Test is operational.


## Fct.2 - NetWorld


NetWorld represent the center piece of the game engine. It is the programme component that glue all the others. 
It is an environment for the game entities, viewed as a planar graph modelling all the possible movements. 


- A NetWorld is composed of nodes at specific position (x,y).
- Nodes are connected to other with edges.
- Nodes can contain entities.
- It is possible to generate NetWorld randomly (example: random nodes and Gabriel graph).
- An algorithm provides paths in the NetWorld between two positions (A*).
- Long edges are subdivided with intermediate nodes in order to generate an almost regular game tabletop.


## Fct.3 - Entities


Entities are the game element capable of actions. This functionality mainly regroups the basic interactions of those entities between them and with the NetWorld.



- An entity is at a specific node.
- Entities see the different possible movements (edges from the nodes) and can try one. The movement succeed only if the node is not over populated.
- Entities can act on the NetWorld (change the colour of a node for instance).
- Entities can act over other entities (damaging them for instance).


## Fct.4 - User Interface


This functionality focus on a graphical rendering of the NetWold and to provide a control through the mouse and keyboard.


- The program starts on welcome menu
- It is possible to launch and visualize a NetWorld and its Entities
- Players can save and load a game 
- Players can select its own entities and provide them for an expected location.
- Animations are triggered when an entity move from a node to another.



## Fct.5 - Robust Development environment


- All developers can refer to a good-practice doc for code.
- Developers would use a proper C unit-test framework.



## Fct.6 - Game-play


It is time to define game objectives and maybe change the name of the project.


## Fct.7 - Programme distributed programme

The goal here is to distribute the game process.


- A player owns entities.
- The player process can be executed on an independent computer process (network)
- The NetWorld simulation can be distributed over processes.
- The game is reachable from a web interface.


## Fct.8 - Tanks

Nodes are defined with a collection of tanks  where resources can be placed. (water for instance)

