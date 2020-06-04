.586P                      ; система команд (процессор Pentum)
.MODEL FLAT, STDCALL       ; модель памяти + соглашение о вызовах
includelib kernel32.lib    ; компоновать вместе с ..

ExitProcess PROTO : DWORD  ; прототип для завершения процесса виндовс
MessageBoxA PROTO : DWORD,: DWORD,: DWORD,: DWORD

.STACK 4096               ; выделение стека 4 мегабайта

.CONST                    ; сегмент констант

.DATA                     ; сегмент данных
MB_OK  EQU 0              ; EQU определяет константу
STR1   DB "Моя первая программа", 0     ;строка, данные + нулевой байт
STR2   DB "Привет всем!", 0
HW     DD ?               ; двойное слово 4 байта, неинициализировано

.CODE                     ; сегмент кода


main PROC                 ; точка входа main
START :
	push MB_OK
	push OFFSET STR1
	push OFFSET STR2
	push HW
	call MessageBoxA     ; вызов функции
	push -1                  ; код возврата
	call ExitProcess         ; завершение процесса виндовс
main ENDP                 ; конец процедуры

end main                   ; конец модуля main