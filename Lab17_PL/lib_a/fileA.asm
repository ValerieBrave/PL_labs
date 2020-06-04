.586
.MODEL flat, stdcall
includelib kernel32.lib    ; компоновать вместе с ..
includelib msvcrt.lib 
.code

getmin PROC parm1 :DWORD, parm2 :DWORD		; объявление процедуры
	mov esi, parm1          
    mov ecx, parm2
    mov eax, [esi] 
L1:
	cmp [esi], eax
	jl L2									; если первый операнд  меньше второго
	jmp next								; если больше, надо двигаться дальше по массиву
L2:
	mov eax, [esi]							; запоминаем меньший операнд
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
	cmp [esi], eax							; все то же самое, только операнды поменяли местами
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