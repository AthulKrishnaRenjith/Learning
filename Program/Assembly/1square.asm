DATA SEGMENT
MSG1 DB 10,13,"ENTER THE NO: $"
MSG2 DB 10,13,"RESULT: $"
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
      MOV AX,DATA
      MOV DS,AX

      LEA DX,MSG1
      MOV AH,9
      INT 21H

      MOV AH,1
      INT 21H

      SUB AL,30H

      MOV BL,AL
      MUL BL
      AAM

      ADD AL,30H
      ADD AH,30H
      MOV BX,AX

      LEA DX,MSG2
      MOV AH,9
      INT 21H  
      
      MOV DL,BH
      MOV AH,2
      INT 21H
      MOV DL,BL
      MOV AH,2
      INT 21H

      MOV AH,4CH
      INT 21H

      CODE ENDS
END START

