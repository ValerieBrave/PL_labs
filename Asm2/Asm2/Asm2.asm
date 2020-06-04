.586P                      ; система команд (процессор Pentum)
.MODEL FLAT, STDCALL       ; модель памяти + соглашение о вызовах
includelib kernel32.lib    ; компоновать вместе с ..

ExitProcess PROTO : DWORD  ; прототип для завершения процесса виндовс
MessageBoxA PROTO : DWORD,: DWORD,: DWORD,: DWORD

.STACK 4096               ; выделение стека 4 мегабайта

.CONST                    ; сегмент констант
MB_OK  EQU 0              ; EQU определяет константу
;MB_OKCANCEL EQU 2

.DATA                     ; сегмент данных
STR1   BYTE "Моя первая программа", 0     ;строка, данные + нулевой байт
STR2   BYTE  "Результат сложения = ", 0
HW     DD ?               ; двойное слово 4 байта, неинициализировано
a byte 4
b byte 5

.CODE                     ; сегмент кода
main PROC                 ; точка входа main
START :
	mov ah, A 
	add ah, B 
	add ah, 48 
	mov STR2+21 , ah 
	INVOKE MessageBoxA, HW, OFFSET STR2, OFFSET STR1, MB_OK 
	push 0                  ; код возврата
	call ExitProcess         ; завершение процесса виндовс
main ENDP                 ; конец процедуры

end main                   ; конец модуля main