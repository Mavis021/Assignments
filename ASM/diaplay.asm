TITLE to display the string using string displaying function
.MODEL SMALL
.STACK 32
.DATA
STRING DB 'PROGRAMMING IS FUN','$'
STRLEN DW $-STRING

.CODE
MAIN PROC FAR
MOV AX, @DATA
MOV DS, AX

MOV AH,09H
LEA DX,STRING
INT 21H

MOV AH,4CH
INT 21H

MAIN ENDP
END MAIN