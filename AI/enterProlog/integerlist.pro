DOMAINS
INT_LIST=integer*

PREDICATES
ADD_LIST(INT_LIST, integer)

CLAUSES 
ADD_LIST([],0).
ADD_LIST([H|T],A):- 
	ADD_LIST(T,A1),A=H+A1.

GOAL
ADD_LIST([1,2,3,4],X).