.586
.MODEL flat, stdcall
includelib kernel32.lib
includelib msvcrt.lib                ; ���������� ������� ���������� �

SetConsoleTitleA   PROTO :DWORD      ; ���������� ��������� ���� ������� 
GetStdHandle       PROTO :DWORD      ; �������� handle ������ �� �������
WriteConsoleA      PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD ; ����� �� �������
ExitProcess	PROTO   :DWORD

.STACK 4096

.const

consoletitle   db 'int_to_char',0
str_pause      db 'pause', 0

.data

myarray DWORD 11, 12, 13, 14, 15, 16, 17, 18, 99, 10
min DWORD ?
max DWORD ?
result1 byte 40 dup(0)             ; ������ 40 ������, ����������� ������

.code
getmin PROC parm1 :DWORD, parm2 :DWORD
	mov esi, parm1          
    mov ecx, parm2
    mov eax, [esi] 
L1:
	cmp [esi], eax
	jl L2
	jmp next
L2:
	mov eax, [esi]
next:
	add esi, 4
	loop L1
	ret          
getmin ENDP

getmax PROC parm1 :DWORD, parm2 :DWORD
	mov esi, parm1          
    mov ecx, parm2
    mov eax, [esi] 
L1:
	cmp [esi], eax
	jg L2
	jmp next
L2:
	mov eax, [esi]
next:
	add esi, 4
	loop L1
	ret          
getmax ENDP

printconsole PROC uses eax ebx ecx esi edi,
                      pstr: dword, ptitle: dword
   push ptitle
   call SetConsoleTitleA
   push -11
   call GetStdHandle
   mov esi, pstr
   mov edi, -1
count:
   inc edi
   cmp byte ptr [esi + edi],0         ; ���������� 2 ����� 
   jne count                          ; ������� � count, ���� ��� �� �����
   push 0
   push 0
   push edi
   push pstr
   push eax
   call WriteConsoleA
   ret
   printconsole ENDP

int_to_char proc uses eax ebx ecx edi esi,   ; ������ ������� 
                      pstr: dword,           ; ����� ������ ���������
                      intfield: dword        ; ������������� �����
    mov edi,pstr             ; ����� ���������� � -> edi
    mov esi,0                ; ���������� �������� � ���������� 
    cdq                      ; �������������� 2�� ����� � ������������ ����������� ��������� ���� �������� eax �� ��� ���� �������� edx
    mov ebx,10               ; ���������� ������� ���������
    idiv ebx                 ; aex = eax/ebx, ������� -> edx
    test eax,80000000h       ; ��������� ������������� ?
    jz plus                  ; ���� ��������� ���������� ������� 0, �.�.������������� �� �� plus
    neg eax                  ; eax = -eax
    neg edx                  ; edx = -edx
    mov cl, '-'              ; ������ ������ ���������� '-'
    mov [edi],cl             ; ������ ������ ���������� '-'
    inc edi                  ; ++edi
plus:
    push dx                  ; ������� -> ����
    inc esi                  ; ++esi
    test eax, eax            ; eax == 0?
    jz fin                   ; ���� �� �� �� fin
    cdq                      ; ���� �������������� � eax �� edx
    idiv ebx                 ; aex = eax/ebx, ������� -> edx
    jmp plus
fin:
    mov ecx, esi             ; ���������� ��������� �������� = ���������� �������� � ����������
write:                       ; ���� ������ ����������
    pop bx                   ; ������� �� ����� -> bx
    add bl,'0'               ; ������������ ������ � bl
    mov [edi],bl             ; bl-> � ���������
    inc edi                  ; edi++
    loop write               ; if (--ecx) > 0 goto write
    
    ret
int_to_char ENDP

main PROC
	mov esi,OFFSET myarray 
	mov ecx,LENGTHOF myarray
	mov ebx, ecx
	push ecx                   ; ���������� � ����
	push esi
    call getmin
	mov min,eax
	mov esi,OFFSET myarray 
	mov ecx,LENGTHOF myarray
	push ecx
	push esi
	call getmax
	mov max,eax
	mov eax,max
	sub eax,min

    push eax                   ; �������� �����
    push offset result1        ; ����� ��� ����������
    call int_to_char           ; ����� ��������� ��������������

    push offset consoletitle   ; ��������� ���� �������
    push offset result1        ; ��������� �����
    call printconsole
	push 0
	call ExitProcess
main ENDP

end main
end