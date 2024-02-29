PREDICATES
f(integer,integer)
CLAUSES
f(X,0):- X<3.
f(X,2):- 3<=X,!,X<6.
f(X,4):- 6<X.
GOAL
f(7,X).
