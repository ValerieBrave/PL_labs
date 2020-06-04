.586
.MODEL flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib lib_d.lib
SetConsoleTitleA   PROTO :DWORD      ; ���������� ��������� ���� ������� 
GetStdHandle       PROTO :DWORD      ; �������� handle ������ �� �������
WriteConsoleA      PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD ; ����� �� �������
extrn getmin : proc   
extrn getmax	: proc         

ExitProcess	PROTO   :DWORD

.STACK 4096

.const

consoletitle   db 'int_to_char',0
str_pause      db 'pause', 0
text byte 'getmax - getmin = ', 0
.data

array SDWORD 11, 12, 13, 14, 15, 16, 17, 18, 59, 10
min SDWORD ?
max SDWORD ?
result1 byte 40 dup(0)             ; ������ 40 ������, ����������� ������
.code
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
;-------------------------------------------------------
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
;------------------------------------------------------------------------
main PROC                 ; ����� ����� main
START :
	mov esi, OFFSET array		; ������ �������
	mov ecx, LENGTHOF array	; ����� �������
	mov ebx, ecx
	push ecx                    ; ���������� � ��e��
	push esi
    call getmin
	mov min, eax
	;----------------
	mov esi,OFFSET array 
	mov ecx,LENGTHOF array
	push ecx
	push esi
	call getmax
	mov max,eax
	;-----------------
	mov eax,max
	sub eax,min						; �������� � eax
	;---------------
	push eax                   ; �������� �����
    push offset result1        ; ����� ��� ����������
    call int_to_char           ; ����� ��������� ��������������

    push offset consoletitle   ; ��������� ���� �������
    push offset text        ; ��������� �����
    call printconsole
	push offset consoletitle   ; ��������� ���� �������
    push offset result1        ; ��������� �����
    call printconsole
	push 0						; ��� ��������
	call ExitProcess			; ���������� �������� �������

	
main ENDP						; ����� ���������

end main	