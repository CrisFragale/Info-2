	.file	"main.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"ingrese los valores de x e y de origen separados por una coma un espacio y luego los x e y finales separados por coma.\n ejemplo: 1,2 3,4"
.LC1:
	.string	"%d,%d %d,%d"
.LC2:
	.string	"%f\n"
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
	movl	$.LC0, %edi
	call	puts
	leaq	-16(%rbp), %rsi
	leaq	-24(%rbp), %rcx
	leaq	-20(%rbp), %rdx
	leaq	-28(%rbp), %rax
	movq	%rsi, %r8
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-16(%rbp), %ecx
	movl	-24(%rbp), %edx
	movl	-20(%rbp), %esi
	movl	-28(%rbp), %eax
	movl	%eax, %edi
	call	distancia
	movd	%xmm0, %eax
	movl	%eax, -12(%rbp)
	cvtss2sd	-12(%rbp), %xmm0
	movl	$.LC2, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	movq	-8(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
