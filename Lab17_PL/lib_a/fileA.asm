.586
.MODEL flat, stdcall
includelib kernel32.lib    ; ����������� ������ � ..
includelib msvcrt.lib 
.code

getmin PROC parm1 :DWORD, parm2 :DWORD		; ���������� ���������
	mov esi, parm1          
    mov ecx, parm2
    mov eax, [esi] 
L1:
	cmp [esi], eax
	jl L2									; ���� ������ �������  ������ �������
	jmp next								; ���� ������, ���� ��������� ������ �� �������
L2:
	mov eax, [esi]							; ���������� ������� �������
next:
	add esi, 4
	loop L1
	ret          
getmin ENDP
;-------------------------------------------------------------------------
getmax PROC parm1 :DWORD, parm2 :DWORD
	mov esi, parm1          
    mov ecx, parm2
    mov eax, [esi] 
L1:
	cmp [esi], eax							; ��� �� �� �����, ������ �������� �������� �������
	jg L2
	jmp next
L2:
	mov eax, [esi]
next:
	add esi, 4
	loop L1
	ret          
getmax ENDP
END