; Function: char *ft_strcpy(char *dest, const char *src);
; Arguments:
;	rdi - dest (destination buffer)
;	rsi - src (source string)
; Variable:
; Returned value :
;	a pointer to dest
;


section .text
global ft_strcpy

ft_strcpy:
	mov rax,rdi

copy_loop:
	mov bl, byte [rsi]
	mov [rdi], bl	

	test bl, bl
	je done
	
	inc rsi
	inc rdi

	jmp copy_loop

done:
	ret ; rax is storing the original dest ptr

