	.file	"fun2.c"
	.section	.rodata
.LC0:
	.string	"w+"
	.align 8
.LC1:
	.string	"NombreTema: %s \n Autor: %s \n CantidadReproducciones %d \n"
	.text
	.globl	almacenar
	.type	almacenar, @function
almacenar:
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
	movl	$0, -12(%rbp)
	movq	-32(%rbp), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L4
	movl	$-1, %eax
	jmp	.L3
.L5:
	movq	-24(%rbp), %rax
	movl	44(%rax), %esi
	movq	-24(%rbp), %rax
	leaq	24(%rax), %rcx
	movq	-24(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	-8(%rbp), %rax
	movl	%esi, %r8d
	movl	$.LC1, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movq	-24(%rbp), %rax
	movq	48(%rax), %rax
	movq	%rax, -24(%rbp)
	addl	$1, -12(%rbp)
.L4:
	cmpq	$0, -24(%rbp)
	jne	.L5
	movl	-12(%rbp), %eax
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	almacenar, .-almacenar
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
