.586
.MODEL flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib lib_d.lib
SetConsoleTitleA   PROTO :DWORD      ; установить заголовок окна консоли 
GetStdHandle       PROTO :DWORD      ; получить handle вывода на консоль
WriteConsoleA      PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD ; вывод на консоль
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
result1 byte 40 dup(0)             ; массив 40 байтов, заполненный нулями
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
   cmp byte ptr [esi + edi],0         ; сравниваем 2 числа 
   jne count                          ; переход к count, если они не равны
   push 0
   push 0
   push edi
   push pstr
   push eax
   call WriteConsoleA
   ret
   printconsole ENDP
;-------------------------------------------------------
int_to_char proc uses eax ebx ecx edi esi,   ; начало функции 
                      pstr: dword,           ; адрес строки результат
                      intfield: dword        ; преобразуемое число
    mov edi,pstr             ; адрес результата в -> edi
    mov esi,0                ; количество символов в результате 
    cdq                      ; преобразование 2го слова в учетверенное копирование знакового бита регистра eax на все биты регистра edx
    mov ebx,10               ; десятичная система счисления
    idiv ebx                 ; aex = eax/ebx, остаток -> edx
    test eax,80000000h       ; результат отрицательный ?
    jz plus                  ; если результат предыдущей команды 0, т.е.положительный то на plus
    neg eax                  ; eax = -eax
    neg edx                  ; edx = -edx
    mov cl, '-'              ; первый символ результата '-'
    mov [edi],cl             ; первый символ результата '-'
    inc edi                  ; ++edi
plus:
    push dx                  ; остаток -> стек
    inc esi                  ; ++esi
    test eax, eax            ; eax == 0?
    jz fin                   ; если да то на fin
    cdq                      ; знак распространили с eax на edx
    idiv ebx                 ; aex = eax/ebx, остаток -> edx
    jmp plus
fin:
    mov ecx, esi             ; количество ненулевых остатков = количеству символов в результате
write:                       ; цикл записи результата
    pop bx                   ; остаток из стека -> bx
    add bl,'0'               ; сформировали символ в bl
    mov [edi],bl             ; bl-> в результат
    inc edi                  ; edi++
    loop write               ; if (--ecx) > 0 goto write
    
    ret
int_to_char ENDP
;------------------------------------------------------------------------
main PROC                 ; точка входа main
START :
	mov esi, OFFSET array		; начало массива
	mov ecx, LENGTHOF array	; длина массива
	mov ebx, ecx
	push ecx                    ; размещение в стeке
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
	sub eax,min						; разность в eax
	;---------------
	push eax                   ; исходное число
    push offset result1        ; место для результата
    call int_to_char           ; вызов процедуры преобразования

    push offset consoletitle   ; заголовок окна консоли
    push offset text        ; выводимый текст
    call printconsole
	push offset consoletitle   ; заголовок окна консоли
    push offset result1        ; выводимый текст
    call printconsole
	push 0						; код возврата
	call ExitProcess			; завершение процесса виндовс

	
main ENDP						; конец процедуры

end main	