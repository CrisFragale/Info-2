	.file	"funciones.c"
	.text
	.globl	encuentro
	.type	encuentro, @function
encuentro:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	subq	$1, %rax
	movq	%rax, -8(%rbp)
	jmp	.L2
.L3:
	addq	$1, -8(%rbp)
	movq	-32(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strstr
	movq	%rax, -8(%rbp)
	addl	$1, -12(%rbp)
.L2:
	cmpq	$0, -8(%rbp)
	jne	.L3
	movl	-12(%rbp), %eax
	subl	$1, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	encuentro, .-encuentro
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
