# General question
## How to debug assembly ? 

1) compile asm with nasm -g
2) compile .c with up-to-date gcc -g3
3) use up-to-date gdb with the followin : 
	gdb asm
	break ft_strcpy
	set disassembly-flavor intel
	r
	layout asm
	layout regs
	nexti
	p (char) $al
nexti is the way to do step-by-step in assembly

# ft_strcpy

## why did we do a `mov al, byte [rsi]` ? 

In x86_64 assembly, the mov instruction can operate on different sizes of data: bytes (8 bits), words (16 bits), double words (32 bits), and quad words (64 bits).

The size of the operand determines how many bytes of data are transferred and how the data is handled.

Here’s a quick overview of the different sizes:

    Byte (8 bits): mov al, byte [rsi]
    Word (16 bits): mov ax, word [rsi]
    Double Word (32 bits): mov eax, dword [rsi]
    Quad Word (64 bits): mov rax, qword [rsi]

## Did we really needed to mov into al and into [rdi] directly ?

Kind of.
`test byte [rsi], byte [rsi]` is problematic because test is generally used with registers or immediate values, not with memory operands in this way.
