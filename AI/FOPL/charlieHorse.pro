  GNU nano 7.1                               charlieHorse.pro                              %SOURCE CODE
PREDICATES
MAMMAL(STRING)
OFFSPRING(STRING, STRING)
HORSE(STRING)
COW(STRING)
PIG(STRING)
PARENT(STRING, STRING)

CLAUSES
MAMMAL(X):- HORSE(X); COW(X); PIG(X).
PIG(X).
COW(X).
 
HORSE("Bluebeard").
HORSE(Y) :- OFFSPRING(X,Y) , HORSE(X). 

PARENT("Bluebeard", "Charlie").
PARENT(_,X):-MAMMAL(X).

OFFSPRING(X, Y) :- PARENT(Y, X).

GOAL
HORSE("Charlie").

