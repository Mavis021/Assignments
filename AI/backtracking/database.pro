DOMAINS
date=d(integer,symbol,integer)
works=w(symbol,integer)
FACTS
person(symbol,symbol,date,works).
PREDICATES
start
load_name
evalans(integer)
display
search
dispname(symbol)
delete
CLAUSES
person(shyam,sharma,d(12,august,1976),w(ntv,18000)).
person(ram,sharma,d(12,august,1976),w(ntv,18000)).
person(ram,singh,d(13,may,2001),w(utl,12000)).
start:-
write("*************MENU**************"),nl,
write("Press 1 to add new data"),nl,
write("Press 2 to show existing data"),nl,
write("Press 3 to search"),nl,
write("Press 4 to delete"),nl,
write("Press 0 to exit"),nl,
write("*************MENU**************"),nl,
readint(X),
evalans(X).
evalans(1):-load_name,start.
evalans(2):-display,evalans(2).
evalans(3):-search,start.
evalans(4):-delete,start.
evalans(0):-write("Thank You").
delete :-
    write("Enter the name of the person to delete: "), nl,
    readln(N),
        retract(person(N,_,d(_,_,_),w(_,_))), 
    write("Person deleted successfully."), nl. 
search:-
write("Enter the name \n"),nl,
readln(N),
	person(N,_,d(_,_,_),w(_,_)),
	dispname(N).
dispname(N):-
person(N,C,d(D,M,Y),w(O,S)),
write("Name:",N," ",C),nl,
write("Date of Birth:",D,"th"," ",M," ",Y),nl,
write("Organisation:",O),nl,
write("Salary:",S),nl,nl.
display:-
retract(person(N,X,d(D,M,Y),w(O,S))),
write("Name:",N," ",X),nl,
write("Date of Birth:",D,"th"," ",M," ",Y),nl,
write("Organisation:",O),nl,
write("Salary:",S),nl,nl.
load_name:-
write("Enter the name \n"),
readln(N),
write("Enter the surname \n"),
readln(S),
write("Date of Birth \n Day:"),
readint(D),nl,
write("Month:"),
readln(M),nl,
write("Year:"),
readint(Y),nl,
write("Enter the organisation:"),
readln(O),
write("Enter the salary:"),
readint(Sl),nl,nl,
asserta(person(N,S,d(D,M,Y),w(O,Sl))).
GOAL
Start.
