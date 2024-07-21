; Function: int ft_strcmp(const char *dest, const char *src);
; Arguments:
; 	rdi		s1
;	rsi		s2
; Variable:
;	rcx		counter
; Returned value :

section .text
global ft_strcmp

ft_strcmp:
    ; Function prologue (optional)
    push rbx

	xor rcx,rcx
loop:
	mov al, byte [rdi]
	mov bl, byte [rsi]
	cmp al, bl
	jne not_equal
	test al,al
	je null_byte_found
	
	inc rdi
	inc rsi
	jmp loop

not_equal:
	sub al, bl	
	movsx rax, al 
	jmp end
null_byte_found:
	xor rax,rax
	jmp end
end:
    ; Function epilogue (optional)
    pop rbx
	ret
