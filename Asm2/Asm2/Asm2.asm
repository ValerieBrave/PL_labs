.586P                      ; ������� ������ (��������� Pentum)
.MODEL FLAT, STDCALL       ; ������ ������ + ���������� � �������
includelib kernel32.lib    ; ����������� ������ � ..

ExitProcess PROTO : DWORD  ; �������� ��� ���������� �������� �������
MessageBoxA PROTO : DWORD,: DWORD,: DWORD,: DWORD

.STACK 4096               ; ��������� ����� 4 ���������

.CONST                    ; ������� ��������
MB_OK  EQU 0              ; EQU ���������� ���������
;MB_OKCANCEL EQU 2

.DATA                     ; ������� ������
STR1   BYTE "��� ������ ���������", 0     ;������, ������ + ������� ����
STR2   BYTE  "��������� �������� = ", 0
HW     DD ?               ; ������� ����� 4 �����, ������������������
a byte 4
b byte 5

.CODE                     ; ������� ����
main PROC                 ; ����� ����� main
START :
	mov ah, A 
	add ah, B 
	add ah, 48 
	mov STR2+21 , ah 
	INVOKE MessageBoxA, HW, OFFSET STR2, OFFSET STR1, MB_OK 
	push 0                  ; ��� ��������
	call ExitProcess         ; ���������� �������� �������
main ENDP                 ; ����� ���������

end main                   ; ����� ������ main