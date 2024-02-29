PREDICATES
HCF(integer, integer, integer)

CLAUSES
HCF(X, Y, Z):- Y>X, HCF(Y, X, Z).
HCF(X, Y, Z):- Y=0, Z=X.
HCF(X, Y, Z):- X=0, Z=Y.
HCF(X, Y, Z):- X>Y, R = X mod Y, HCF(Y, R, Z).

GOAL
HCF(18, 20, X).
