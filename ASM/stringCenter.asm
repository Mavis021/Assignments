TITLE to accept the string and display that in the center of a clear screen
.MODEL SMALL
.STACK 32
.DATA
STRING LABEL BYTE
MAXLEN DB 20
ACCTUAL DB ?
INPUT  DB 20 DUP('$')

.CODE
MAIN PROC FAR
MOV AX, @DATA
MOV DS, AX

MOV AH,0AH
LEA DX,STRING
INT 21H

MOV AH,00H
MOV AL,03H
INT 10H
MOV DH,12
MOV DL,30
MOV AH,02H
MOV BH,0
INT 10H

MOV AH,09H
LEA DX,STRING+2
INT 21H

MOV AH,4CH
INT 21H

MAIN ENDP
END MAIN
