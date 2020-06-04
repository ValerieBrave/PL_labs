.586
.MODEL flat, stdcall
includelib libucrt.lib
includelib kernel32.lib

includelib LP_Lab_d.lib

extrn getmin : proc ;PROTO : DWORD, : DWORD
extrn getmax : proc ;PROTO : DWORD, : DWORD

SetConsoleTitleA PROTO : DWORD
GetStdHandle PROTO : DWORD
WriteConsoleA PROTO : DWORD, : DWORD, : DWORD, : DWORD, : DWORD

ExitProcess PROTO : DWORD

.stack 4096

.const
consoletitle byte ' Lab17 Console', 0
text byte 'getmax - getmin = ', 0

.data
consolehandle dword 0h
myarray dword 11, 12, 13, 14, 15, 16, 17, 18, 59, 10
strtoconsole byte 255 dup(0)
max dword ?
min dword ?
result dword ?

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
cmp byte ptr [esi + edi],0 ; сравниваем 2 числа
jne count ; переход к count, если они не равны
push 0
push 0
push edi
push pstr
push eax
call WriteConsoleA
ret
printconsole ENDP

int_to_char proc uses eax ebx ecx edi esi, ; начало функции
pstr: dword, ; адрес строки результат
intfield: dword ; преобразуемое число
mov edi,pstr ; адрес результата в -> edi
mov esi,0 ; количество символов в результате
cdq ; преобразование 2го слова в учетверенное копирование знакового бита регистра eax на все биты регистра edx
mov ebx,10 ; десятичная система счисления
idiv ebx ; aex = eax/ebx, остаток -> edx
test eax,80000000h ; результат отрицательный ?
jz plus ; если результат предыдущей команды 0, т.е.положительный то на plus
neg eax ; eax = -eax
neg edx ; edx = -edx
mov cl, '-' ; первый символ результата '-'
mov [edi],cl ; первый символ результата '-'
inc edi ; ++edi
plus:
push dx ; остаток -> стек
inc esi ; ++esi
test eax, eax ; eax == 0?
jz fin ; если да то на fin
cdq ; знак распространили с eax на edx
idiv ebx ; aex = eax/ebx, остаток -> edx
jmp plus
fin:
mov ecx, esi ; количество ненулевых остатков = количеству символов в результате
write: ; цикл записи результата
pop bx ; остаток из стека -> bx
add bl,'0' ; сформировали символ в bl
mov [edi],bl ; bl-> в результат
inc edi ; edi++
loop write ; if (--ecx) > 0 goto write

ret
int_to_char ENDP


main PROC


mov esi,OFFSET myarray
mov ecx,LENGTHOF myarray
mov ebx, ecx
push ecx ; размещение в стке
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

push eax ; исходное число
push offset result ; место для результата
call int_to_char ; вызов процедуры преобразования

push offset consoletitle
push offset text
call printconsole

push offset consoletitle ; заголовок окна консоли
push offset result ; выводимый текст
call printconsole

push 0
call ExitProcess
main ENDP

end main