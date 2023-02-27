TITLE to add all the elements of a table, which are between 50 and 150 only,Display the result as the decimal value
.MODEL SMALL
.STACK 32
.DATA
NUM DB 0
NUMBERS DW 51,52,04,05,160,140,57,'$'
LEN DB $-NUMBERS

.CODE
MAIN PROC FAR
MOV AX,@DATA
MOV DS,AX

MOV SI,OFFSET NUMBERS
MOV CH,0
MOV CL,LEN
MOV BX,0
MOV AX,0
STEP1:MOV DX,[NUMBERS+BX]
CMP DX,32H      ;compairing with 50
JB SKIP         ;skip if less
CMP DX,96H       ;compairing with 150
JA SKIP         ;skip if greater
ADD AX,DX
SKIP: INC BX
LOOP STEP1

MOV NUM,AL
LEA SI,NUM
MOV BX,10      ;for dividing the number by 10
MOV CX,0
STEP2:MOV DX,0
DIV BX          
ADD DX,30H     ;converting into ascii character
PUSH DX        ;storing in stack
INC CX
CMP AX,0       
JNE STEP2

;DISPLAY the stored decimal digits
MOV AH, 02
DISP:POP DX
INT 21H
LOOP DISP

MOV AH,4CH
INT 21H

MAIN ENDP
END MAIN
