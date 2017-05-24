	.file	"funciones.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"ingrese un numero positivo. para finalizar, presione 0."
.LC1:
	.string	"%d"
	.text
	.globl	contadorDeNumeros
	.type	contadorDeNumeros, @function
contadorDeNumeros:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC0, %edi
	call	puts
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	jmp	.L2
.L4:
	movl	-16(%rbp), %eax
	testl	%eax, %eax
	jle	.L3
	addl	$1, -12(%rbp)
.L3:
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
.L2:
	movl	-16(%rbp), %eax
	testl	%eax, %eax
	jne	.L4
	movq	-24(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rax)
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L5
	call	__stack_chk_fail
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	contadorDeNumeros, .-contadorDeNumeros
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
