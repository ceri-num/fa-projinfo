# Documenter son projet

Si la documentation de *'RayLib'* est un peu bordéliques (du fait de plusieurs points d'entrée) elle reste quant même une bonne référence en la matière.

Les 3 points d'entrée classique d'une documentation:

1. L'accueil - à minima le fichier classique: *README.md*.
2. La prise en main - La description pas-à-pas permettant l'installation et l'exécution de la solution (idéalement sous forme de tutoriels éprouvés).
3. Le code lui-même - Si le code est lisible , alors il se suffira quasiment à lui-même en termes de documentation.

# Une doc en fichier textuel

Pourquoi privilégier une documentation au format textuel (édité avec un éditeur de texte plutôt qu'un traitement de texte) ?

- Pas moins lisible (en fonction du format choisie).
- Claire dissociation du fond et de la forme.
- Plus facilement versionnable.
- Parssable et donc transférable sur tous supports.

Quelques exemples de format:

- [MarkDown](https://fr.wikipedia.org/wiki/Markdown): les plus: *ultra léger*, *lisible* ,*natif sur les serveurs git*. les moins: *expressivité de mise en forme limitée*. Particulièrement recommandé pour éditer rapidement une documentation.
- [latex](https://fr.wikipedia.org/wiki/LaTeX): les plus: *léger*, *éditable*, *programmable*, *nombreux pluggins dont mathématique, citation...*. les moins: *plus lourd à compiler*. Largement utilisé pour l'édition de documentation technique et scientifique.
- [html/css](https://fr.wikipedia.org/wiki/LaTeX): les plus: *complet*, *directement interprétable dans un navigateur*. les moins: *verbeux*. Le langage du Web.

Sur les aspects de transformation d'un format à l'autre, l'exemple de [pandoc](https://pandoc.org/) parle de lui-même.

L'autre avantage de langage aux formats plain-text et ouvert c'est la multitude d'extensions que l'on peut trouver de contributeurs divers. Citons [Marp](https://marp.app/) qui permet de générer des présentations sur une base MarkDown et qui s'intègre naturellement à [Atom](https://atom.io/packages/atom-marp) ou [VSCode](https://marketplace.visualstudio.com/items?itemName=marp-team.marp-vscode).


# Commenter le code

Enfin, avant une documentation exhaustive, des sources qui se lisent facilement c'est déjà 90\% du travail accompli.

- **Surtout les header:** plus que les modèles et l'algorithme sus-jacent à une fonctionnalité, c'est une bonne définition de ces paramètres et de ce qu'elle retourne qui permettra son utilisation.
- **À jour:** Les commentaires doivent être écrits en même temps que le code et les modifications qu'on lui apporte.
- **Modulable:** éviter les fonctions à rallonge dans lesquels on ne s'y retrouve plus. Diviser les fonctionnalités complexes en sous-fonctionnalité qui fait passer par des résultats intermédiaires.


Pour les 10\% de travail restant, un outil de générations automatique de documentation basée sur un code proprement commenté sera tout aussi efficace comme [doxigen](https://fr.wikipedia.org/wiki/Doxygen) pour le C/C+++.

