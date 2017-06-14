	.file	"main.c"
	.section	.rodata
.LC0:
	.string	"ingrese la frase"
	.align 8
.LC1:
	.string	"ingrese la palabra que quiere buscar"
.LC2:
	.string	"%s"
.LC3:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1056, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -1044(%rbp)
	movl	$.LC0, %edi
	call	puts
	movq	stdin(%rip), %rdx
	leaq	-1040(%rbp), %rax
	movl	$512, %esi
	movq	%rax, %rdi
	call	fgets
	movq	stdin(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__fpurge
	movl	$.LC1, %edi
	call	puts
	leaq	-528(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	leaq	-528(%rbp), %rdx
	leaq	-1040(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	encuentro
	movl	%eax, -1044(%rbp)
	movl	-1044(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
