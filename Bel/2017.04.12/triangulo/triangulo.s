	.file	"triangulo.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"ingrese un lado, presione enter. repita. dos veces mas"
.LC1:
	.string	"%d %d %d"
.LC2:
	.string	"es equil\303\241tero."
.LC3:
	.string	"es isoceles."
.LC4:
	.string	"es escaleno"
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
	leaq	-12(%rbp), %rcx
	leaq	-16(%rbp), %rdx
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-20(%rbp), %edx
	movl	-16(%rbp), %eax
	cmpl	%eax, %edx
	jne	.L2
	movl	-16(%rbp), %edx
	movl	-12(%rbp), %eax
	cmpl	%eax, %edx
	jne	.L2
	movl	$.LC2, %edi
	call	puts
	jmp	.L3
.L2:
	movl	-20(%rbp), %edx
	movl	-16(%rbp), %eax
	cmpl	%eax, %edx
	jne	.L4
	movl	-16(%rbp), %edx
	movl	-12(%rbp), %eax
	cmpl	%eax, %edx
	jne	.L5
.L4:
	movl	-20(%rbp), %edx
	movl	-12(%rbp), %eax
	cmpl	%eax, %edx
	jne	.L6
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %eax
	cmpl	%eax, %edx
	jne	.L5
.L6:
	movl	-16(%rbp), %edx
	movl	-12(%rbp), %eax
	cmpl	%eax, %edx
	jne	.L7
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	cmpl	%eax, %edx
	je	.L7
.L5:
	movl	$.LC3, %edi
	call	puts
	jmp	.L3
.L7:
	movl	$.LC4, %edi
	call	puts
.L3:
	movl	$0, %eax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L9
	call	__stack_chk_fail
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
