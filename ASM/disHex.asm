TITLE to add all the elements of a table, which are between 30 and 100 only,Display the result as the hexadecimal value
.MODEL SMALL
.STACK 32
.DATA
NUM DB 0
NUMBERS DB 40,40,40,40,80,02,140,'$'
LEN DB $-NUMBERS

.CODE
MAIN PROC FAR
MOV AX,@DATA
MOV DS,AX

MOV SI,OFFSET NUMBERS
MOV CH,0
MOV CL,LEN
MOV AX,0
MOV BX,0
STEP1:MOV DL,[NUMBERS+BX]
CMP DL,'$'
JE SKIP
CMP DL,1EH      ;compairing with 30
JB SKIP         ;skip if less
CMP DL,64H       ;compairing with 100
JA SKIP         ;skip if greater
ADD AL,DL
SKIP: INC BX
LOOP STEP1

MOV NUM,AL
LEA SI,NUM
MOV BX,16      ;for dividing the number by 16
MOV CX,0
MOV AH,0
STEP2:MOV DX,0
DIV BX           ;DIVIDES AX:DX BY BX AND REMAINDER IS IN DX ,QUOTIENT IS IN AX
CMP DX, 0H
JB NEXT
CMP DX, 09H
JA NEXT        
ADD DX,30H     ;converting into ascii character
JMP NEXT2
NEXT:CMP DX,0AH
JB NEXT2
CMP DX,0FH
JA NEXT2
ADD DX,37H           ;ADDING 37H TO THE REMAINDER DX
NEXT2:PUSH DX        ;storing in stack
INC CX
CMP AX,0         ;QUOTIENT       
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
