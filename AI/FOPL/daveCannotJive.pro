%SOURCE CODE
PREDICATES
	MEMBER(STRING)
	CAN(STRING, STRING)
	CANNOT(STRING, STRING)
	PARENT(STRING, STRING)
	
CLAUSES
	MEMBER("DAVE").
	MEMBER("FRED").
	
	PARENT("DAD", "FRED").
	
	CANNOT("DAD", "WALTZ").
	CANNOT(X,Y) :- PARENT(Z,X), CANNOT(Z,Y).
	CANNOT(X,"WALTZ"):- MEMBER(X), CAN(X,"JIVE").
	CANNOT(X,"JIVE"):- MEMBER(X), CAN(X, "WALTZ").
	
	CAN("DAVE",Y):- CANNOT("FRED",Y).
	
GOAL
	MEMBER(X) , CANNOT(X,"JIVE").
