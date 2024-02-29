%SOURCE CODE
%BANANA + GUAVA = ORANGE
DOMAINS
int_list=integer*

PREDICATES
solution(int_list)
member(integer,int_list)

CLAUSES
solution([]).

solution([B,A,N,G,V,U,O,R,E]):- 
	C5 = 1,
	member(C1, [0,1]),
	member(C2, [0,1]),
	member(C3, [0,1]),
	member(C4, [0,1]),
	
	member(B,[0,1,2,3,4,5,6,7,8,9]),
	member(A,[0,1,2,3,4,5,6,7,8,9]),
	member(N,[0,1,2,3,4,5,6,7,8,9]),
	member(G,[0,1,2,3,4,5,6,7,8,9]),
	member(U,[0,1,2,3,4,5,6,7,8,9]),
	member(V,[0,1,2,3,4,5,6,7,8,9]),
	member(O,[0,1,2,3,4,5,6,7,8,9]),
	member(R,[0,1,2,3,4,5,6,7,8,9]),
	member(E,[0,1,2,3,4,5,6,7,8,9]),
	
	B<>N,B<>A,B<>G,B<>V,B<>U,B<>O,B<>R,B<>E,
	A<>N,A<>G,A<>U,A<>V,A<>O,A<>R,A<>E,
	N<>G,N<>V,N<>U,N<>O,N<>R,N<>E,
	G<>V,G<>U,G<>O,G<>R,G<>E,
	V<>U,V<>O,V<>R,V<>E,
	U<>O,U<>R,U<>E,
	O<>R,O<>E,
	R<>E,
	
	A + A = E + 10*C1,
	N + V + C1 = G + 10*C2,
	A + A + C2 = N + 10*C3,
	N + U + C3 = A + 10*C4,
	A + G + C4 = R + 10*C5,
	B + C5 = O.
	
	member(X, [X|_]).
	
member(X, [_|Z]):-
	member(X,Z).
	
GOAL
solution([B,A,N,G,U,V,O,R,E]).

