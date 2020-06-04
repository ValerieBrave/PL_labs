.586P                      ; система команд (процессор Pentum)
.MODEL FLAT, STDCALL       ; модель памяти + соглашение о вызовах
includelib kernel32.lib    ; компоновать вместе с ..

ExitProcess PROTO : DWORD  ; прототип для завершения процесса виндовс
MessageBoxA PROTO : DWORD,: DWORD,: DWORD,: DWORD
.STACK 4096               ; выделение стека 4 мегабайта

.CONST                    ; сегмент констант
MB_OK  EQU 0 
STR1   DB "Проверка массива", 0     ;строка, данные + нулевой байт
STR2   DB "Найден нулевой элемент", 0
STR3   DB "Не найден нулевой элемент", 0

.DATA                     ; сегмент данных
myBytes BYTE 10h, 20h, 30h, 40h
myWords WORD 8Ah, 3Bh, 44h, 5Fh, 99h
myNumbers WORD 1, 2, 3, 4, 5, 6, 7
myCheck DWORD 1, 2, 3, 0, 5, 6, 7

HW DD ?
.CODE                     ; сегмент кода
main PROC                 ; точка входа main
START :
	mov ESI, OFFSET myWords
	mov AX, [ESI + 4]
	mov BX, [ESI + 2]
	;---------------------------------------------------
	mov ESI, OFFSET myNumbers
	mov EAX, 0
	mov ECX, 7
CYCLE:
	add AX, [ESI]
	add ESI, 2
	loop CYCLE
	;---------------------------------------------------
	mov EAX, 0
	mov EBX, 0
	mov ESI, OFFSET myCheck
	mov ECX, 7
CHECK:
	mov EAX, [ESI]
	add ESI, 4
	cmp EAX, EBX
	je EQUA
	loop CHECK

	jmp FIN

EQUA:
	INVOKE MessageBoxA, HW, OFFSET STR2, OFFSET STR1, MB_OK
	mov EBX, 1
	
FIN:
	push 0                  ; код возврата
	call ExitProcess        ; завершение процесса виндовс	
main ENDP                 ; конец процедуры

end main                   ; конец модуля main