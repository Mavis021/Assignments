PREDICATES
PROFESSOR(STRING, STRING)
FRIEND(STRING, STRING)
GUIDE(STRING, STRING)
STUDENT(STRING, STRING)

CLAUSES 
PROFESSOR("BISCUIT", "KILLUA").
PROFESSOR("BISCUIT", "GON").
PROFESSOR("WING", "ZUSHI").

FRIEND("GON", "KILLUA").
FRIEND("GON", "ZUSHI").
FRIEND("GON", "KURAPIKA").

STUDENT(A,B):- PROFESSOR(B,A).
STUDENT(A,C):- PROFESSOR(C,B),FRIEND(B,A).

GUIDE(A,C):- PROFESSOR(A,B),FRIEND(B,C).

GOAL
GUIDE(X, "KURAPIKA").
