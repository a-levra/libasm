; Function:ssize_t write(int fildes, const void *buf, size_t nbyte);
; Arguments:
; 	rdi		fd
;	rsi		ptr to buffer
;	rdx		number of bytes to writes
; Returned value :
;	number of bytes written into the fil descriptor or -1

extern __errno_location
global ft_write
section .text


ft_write:
	mov rax, 1			; 1 is the sys call number for sys_write
	syscall
	cmp rax, 0
	jl error
	ret

error:
	neg		rax
	mov		rdi, rax	; store the positive error code
	call	__errno_location wrt ..plt ; calling errno through a PLT (so it's still a PIE)
	mov		[rax], rdi	; set the positive error code to errno 
	mov		rax, -1
	ret
