
	.section .rodata
msg:	.asciz "Hello, world!\n"

	.text
	.global main
main:
	movq $14, %rdx
	leaq msg(%rip), %rsi
	movq $1, %rdi

	movq $1, %rax
	syscall

	ret

