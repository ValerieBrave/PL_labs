.586P                      ; ������� ������ (��������� Pentum)
.MODEL FLAT, STDCALL       ; ������ ������ + ���������� � �������
includelib kernel32.lib    ; ����������� ������ � ..
includelib msvcrt.lib                ; ���������� ������� ���������� �
includelib lib_a.lib
;includelib libuctr.lib


SetConsoleTitleA   PROTO :DWORD											; ���������� ��������� ���� ������� 
GetStdHandle       PROTO :DWORD											; �������� handle ������ �� �������
WriteConsoleA      PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD				; ����� �� �������
ExitProcess	PROTO   :DWORD
getmin PROTO : DWORD, : DWORD
getmax PROTO : DWORD, : DWORD


.STACK 4096               ; ��������� ����� 4 ���������
.CONST                    ; ������� ��������

consoletitle   db 'int_to_char',0
str_pause      db 'pause', 0

.DATA                     ; ������� ������

array sdword 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
min SDWORD ?
max SDWORD ?               
result1 byte 40 dup(0)             ; ������ 40 ������, ����������� ������

.CODE                     ; ������� ����

printconsole PROC uses eax ebx ecx esi edi,
                      pstr: dword, ptitle: dword
   push  ptitle
   call SetConsoleTitleA
   push -11
   call GetStdHandle
   mov esi, pstr						; esi - ������ ���������
   mov edi, -1
count:
   inc edi
   cmp byte ptr [esi + edi],0         ; ���������� 2 ����� = ���� ������ �� ����������
   jne count                          ; ������� � count, ���� ��� �� �����
   push 0
   push 0
   push edi
   push pstr
   push eax
   call WriteConsoleA
   ret
  printconsole ENDP

  int_to_char PROC uses eax ebx ecx edi esi,   ; ������ ������� 
                      pstr: dword,           ; ����� ������ ���������
                      intfield: dword        ; ������������� �����
    mov edi,pstr             ; ����� ���������� � -> edi
    mov esi,0                ; ���������� �������� � ���������� 
	mov eax,intfield
    cdq                      
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
	sub min, eax					; �������� � eax
	;---------------
	push min                   ; �������� �����
    push offset result1        ; ����� ��� ����������
    call int_to_char           ; ����� ��������� ��������������

    push offset consoletitle   ; ��������� ���� �������
    push offset result1        ; ��������� �����
    call printconsole
	;-----------------
	push offset str_pause
	;call system
	push 0						; ��� ��������
	call ExitProcess			; ���������� �������� �������

	
main ENDP						; ����� ���������

end main						; ����� ������ main