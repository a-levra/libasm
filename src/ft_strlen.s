; Function: size_t ft_strlen(const char * string);
; Inputs:
;   %rdi - Pointer to the string (const char *s)
; Variable:
;   %rcx, ft_strlen's counter
; Output:
;   %rax - returned value

section .text

global ft_strlen
ft_strlen:
    xor rcx, rcx       

while_string:
    mov al, [rdi]
    test al, al        
    je null_byte_found

    inc rcx          
    inc rdi         
    jmp while_string

null_byte_found:
    mov rax, rcx   
    ret           

