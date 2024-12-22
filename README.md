Number Spelling in French
=========================

French is famously weird about numbers, especially between 70 and 99. But there is extra weirdness in
how these should be spelled out: when to put dashes, when to put a plural. I therefore wrote a C++
library that implements all this madness. The code is simple enough to be easily portable to any other
language.

For the curious among you, here are those rules:
 - For numbers below 100, put dashes except when "et" is there ("vingt et un", but "vingt-deux").
 - The 1990 spelling reform allows to put dashes everywhere.
 - Adjectives take plural when needed, except if followed by another **adjective** ("deux cents", but "deux cent un").
   - Numbers up to 1000 are adjectives, the ones above are **nouns** (million, millard, ...).<br>
     Tip : if you need to put "_de_" between the number and its object, it's a noun ("un million **de** voitures").
   - Mille is invariant (but is an adjective nonetheless).
   - The only two adjectives that may take a plural form are therefore _vingt_ and _cent_.
 - Nouns always take the plural form where needed.
 - The ordinal suffix "_ième_" turns nouns into adjectives.
 - In ordinal numbers (1er, 2e, 3e, ...) and in cardinal numbers used as ordinal ones ("page 80"), adjectives never take the plural form.
 - Numbers can be masculine or feminine depending on what they refer to.


Écriture des nombres en français
================================

Les nombres en français sont bizarres, particulièrement entre 70 et 99, mais leur écriture l'est encore plus.
Celle-ci est bourrée de cas particuliers et de règles obscures : quand mettre des tirets, quand mettre un pluriel.
J'ai donc écrit une librarie en C++ qui suit toutes ces règles. Le code me semble suffisamment simple pour pouvoir
être porté dans tout autre langage.

Pour les curieux parmi vous, voici les règles en question :
 - Les nombres jusqu'à 100 prennent des tirets sauf lorsque "et" est présent ("vingt et un", mais "vingt-deux").
 - La réforme orthographique de 1990 autorise de mettre des tirets partout ("deux-cent-vingt-et-un").
 - Les adjectifs s'accordent au pluriel, sauf s'ils sont suivis d'un autre **adjectif** ("deux cents", mais "deux cent un").
   - Les nombres jusqu'à 1000 sont des adjectifs, les suivants sont des **noms** (million, millard, ...).<br>
     Astuce : s'il faut mettre "_de_" entre le nombre et son objet, c'est un nom ("un million **de** voitures").
   - Mille est invariable (mais reste un adjectif).
   - Les deux seuls adjectifs concernés sont donc _vingt_ et _cent_.
 - Les noms s'accordent toujours au pluriel lorsque nécessaire.
 - Le suffix ordinal "_ième_" transforme les noms en adjectifs.
 - Dans les nombres ordinaux (1er, 2e, 3e, ...) ainsi que les cardinaux utilisés comme ordinaux ("page 80"), les adjectifs restent au singulier dans tous les cas.
 - Les nombres s'accordent au féminin ou au masculin suivant ce à quoi ils se réfèrent.
