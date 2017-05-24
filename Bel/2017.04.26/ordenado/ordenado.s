	.file	"ordenado.c"
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"es creciente"
.LC2:
	.string	"no es creciente"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-20(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L2
.L6:
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-20(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jle	.L3
	movl	-20(%rbp), %eax
	movl	%eax, -16(%rbp)
	jmp	.L4
.L3:
	movl	-20(%rbp), %eax
	testl	%eax, %eax
	jne	.L5
	addl	$1, -16(%rbp)
	movl	$.LC1, %edi
	call	puts
	jmp	.L4
.L5:
	movl	$.LC2, %edi
	call	puts
.L4:
	addl	$1, -12(%rbp)
.L2:
	movl	-20(%rbp), %eax
	testl	%eax, %eax
	jne	.L6
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L8
	call	__stack_chk_fail
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
