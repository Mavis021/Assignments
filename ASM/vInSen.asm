TITLE TO COUNT THE NUMBER OF VOWELS IN THE ENTERED SENTENCE
.MODEL SMALL
.STACK 32
.DATA
OUTPUT1 DB 'THERE ARE ','$'
OUTPUT2 DB  ' VOWELS IN THE ENTERED SENTENCE','$'
COUNT DB 0
NUM DB 0
RES DW 00
STRING LABEL BYTE
MAXLEN DB 30
ACCTUAL DB ?
INPUT DB 30 DUP('$')

.CODE
MAIN PROC FAR
MOV AX, @DATA
MOV DS, AX

MOV AH,00H      ;clear screen
MOV AL,03H
INT 10H

MOV AH,0AH
LEA DX,STRING
INT 21H

;CALCULATION
CALL COUNT_VOWELS

MOV AH,02H
MOV DL,0DH
INT 21H
MOV DL,0AH
INT 21H

;DISPLAY RESULT
MOV AH,09H     
LEA DX,OUTPUT1
INT 21H

MOV AL,COUNT
MOV AH,0
;PLACE THE NUMBER TO BE CONVERTED IN AX
CALL DISPLAY_DECIMAL

MOV AH,09H
LEA DX,OUTPUT2
INT 21H

MOV AH,4CH
INT 21H

DISPLAY_DECIMAL PROC

MOV CX,10
MOV BX,0
STEP3:MOV DX,0
DIV CX
ADD DX,30H
PUSH DX
INC BX
CMP AX,0
JA STEP3

MOV AH,02
MOV CX,BX
DISP:POP DX
INT 21H
LOOP DISP
RET
DISPLAY_DECIMAL ENDP

COUNT_VOWELS PROC
MOV SI,OFFSET STRING
MOV CH,0
MOV CL, ACCTUAL+2
MOV DH,0
HERE:MOV DL,[SI]
CMP DL,'a'
JE INCREASE
CMP DL,'e'
JE INCREASE
CMP DL,'i'
JE INCREASE
CMP DL,'o'
JE INCREASE
CMP DL,'u'
JE INCREASE
CMP DL,'A'
JE INCREASE
CMP DL,'E'
JE INCREASE
CMP DL,'I'
JE INCREASE
CMP DL,'O'
JE INCREASE
CMP DL,'U'
JE INCREASE
SKIP:INC SI
LOOP HERE
RET
INCREASE:ADD COUNT,1
JMP SKIP
COUNT_VOWELS ENDP

MAIN ENDP
END MAIN
END