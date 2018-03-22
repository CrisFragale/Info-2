	.file	"main.c"
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"ingrese el dato a buscar "
.LC2:
	.string	"dato buscado %d \n"
	.align 8
.LC3:
	.string	"ingrese el dato a ingresar en la lista "
.LC4:
	.string	"nueva lista "
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
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$0, -48(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	jmp	.L2
.L3:
	leaq	-48(%rbp), %rdx
	subq	$8, %rsp
	subq	$24, %rsp
	movq	%rsp, %rax
	movq	-32(%rbp), %rcx
	movq	%rcx, (%rax)
	movq	-24(%rbp), %rcx
	movq	%rcx, 8(%rax)
	movl	-16(%rbp), %ecx
	movl	%ecx, 16(%rax)
	movq	%rdx, %rdi
	call	insertarfin
	addq	$32, %rsp
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	__isoc99_scanf
.L2:
	movl	-32(%rbp), %eax
	cmpl	$-1, %eax
	jne	.L3
	movl	$.LC1, %edi
	call	puts
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movq	-48(%rbp), %rdx
	subq	$8, %rsp
	subq	$24, %rsp
	movq	%rsp, %rax
	movq	-32(%rbp), %rcx
	movq	%rcx, (%rax)
	movq	-24(%rbp), %rcx
	movq	%rcx, 8(%rax)
	movl	-16(%rbp), %ecx
	movl	%ecx, 16(%rax)
	movq	%rdx, %rdi
	call	busqueda
	addq	$32, %rsp
	movq	%rax, -40(%rbp)
	cmpq	$0, -40(%rbp)
	jne	.L4
	movl	$0, %eax
	jmp	.L6
.L4:
	movq	-40(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$.LC3, %edi
	call	puts
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	leaq	-48(%rbp), %rdx
	subq	$8, %rsp
	subq	$24, %rsp
	movq	%rsp, %rax
	movq	-32(%rbp), %rcx
	movq	%rcx, (%rax)
	movq	-24(%rbp), %rcx
	movq	%rcx, 8(%rax)
	movl	-16(%rbp), %ecx
	movl	%ecx, 16(%rax)
	movq	%rdx, %rdi
	call	insetarorden
	addq	$32, %rsp
	movl	$.LC4, %edi
	call	puts
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	imprimir
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	leaq	-48(%rbp), %rdx
	subq	$8, %rsp
	subq	$24, %rsp
	movq	%rsp, %rax
	movq	-32(%rbp), %rcx
	movq	%rcx, (%rax)
	movq	-24(%rbp), %rcx
	movq	%rcx, 8(%rax)
	movl	-16(%rbp), %ecx
	movl	%ecx, 16(%rax)
	movq	%rdx, %rdi
	call	eliminar
	addq	$32, %rsp
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	imprimir
	movl	$0, %eax
.L6:
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L7
	call	__stack_chk_fail
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
