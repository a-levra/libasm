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
https://youtu.be/ZZTUgIFm9u0?si=DOKEF5qYj-ufHYR5

## How do we retrieve parameters in the asm function ? 
    rdi - First argument
    rsi - Second argument
    rdx - Third argument
    rcx - Fourth argument
    r8 - Fifth argument
    r9 - Sixth argument

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

# ft_write

## What is the wrt ..plt thing ?

Basically, this ensure that the executable is still a PIE (position independant executable)
By specifying PLT, I ask to NASM to use a PLT to store the address of the errno function
Documentation :
Referring to a procedure name using wrt ..plt causes the linker to build a procedure linkage table entry for the symbol, and the reference gives the address of the PLT entry.
You can only use this in contexts which would generate a PC-relative relocation normally 
(i.e. as the destination for CALL or JMP), since ELF contains no relocation type to refer to PLT entries absolutely.
https://www.tortall.net/projects/yasm/manual/html/objfmt-elf32-wrt.html

## jl ?

This means JUMP LESS (often use with the cmp instruction ..). That basically means : jump if left operand is less than right operand (in Intel syntax)

