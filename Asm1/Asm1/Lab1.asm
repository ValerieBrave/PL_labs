.586P                      ; ������� ������ (��������� Pentum)
.MODEL FLAT, STDCALL       ; ������ ������ + ���������� � �������
includelib kernel32.lib    ; ����������� ������ � ..

ExitProcess PROTO : DWORD  ; �������� ��� ���������� �������� �������
MessageBoxA PROTO : DWORD,: DWORD,: DWORD,: DWORD

.STACK 4096               ; ��������� ����� 4 ���������

.CONST                    ; ������� ��������

.DATA                     ; ������� ������
MB_OK  EQU 0              ; EQU ���������� ���������
STR1   DB "��� ������ ���������", 0     ;������, ������ + ������� ����
STR2   DB "������ ����!", 0
HW     DD ?               ; ������� ����� 4 �����, ������������������

.CODE                     ; ������� ����


main PROC                 ; ����� ����� main
START :
	push MB_OK
	push OFFSET STR1
	push OFFSET STR2
	push HW
	call MessageBoxA     ; ����� �������
	push -1                  ; ��� ��������
	call ExitProcess         ; ���������� �������� �������
main ENDP                 ; ����� ���������

end main                   ; ����� ������ main