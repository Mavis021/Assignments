TITLE to convert the text in the memory into uppercase
.MODEL SMALL
.STACK 32
.DATA
LIST DB 'a','e','i','o','U','$'
LEN DB $-LIST

.CODE
MAIN PROC FAR
MOV AX,@DATA
MOV DS,AX

MOV SI,OFFSET LIST
MOV CH,0
MOV CL,LEN
L1:MOV DL,[LIST+SI-2]
CMP DL,'a'
JB SKIP
CMP DL,'z'
JA SKIP
SUB DL,20H
MOV [LIST+SI-2],DL
SKIP:INC SI
LOOP L1

MOV AH,09H
LEA DX,LIST
INT 21H

MOV AH,4CH
INT 21H

MAIN ENDP
END MAIN