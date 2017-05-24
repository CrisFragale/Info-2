	.file	"temp.c"
	.section	.rodata
.LC0:
	.string	"ingrese una temperatura"
.LC1:
	.string	"%d"
	.align 8
.LC2:
	.string	"el promedio de las temperaturas es:%f, la temperatura maxima es:%d, la temperatura minima es:%d \n"
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
	movl	$0, -28(%rbp)
	movl	$0, -24(%rbp)
	movl	$0, -20(%rbp)
	movl	$0, -32(%rbp)
	movl	$.LC0, %edi
	call	puts
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-32(%rbp), %eax
	addl	%eax, -28(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -24(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -20(%rbp)
	movl	$1, -16(%rbp)
	jmp	.L2
.L5:
	movl	$.LC0, %edi
	call	puts
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-32(%rbp), %eax
	addl	%eax, -28(%rbp)
	movl	-32(%rbp), %eax
	cmpl	%eax, -24(%rbp)
	jge	.L3
	movl	-32(%rbp), %eax
	movl	%eax, -24(%rbp)
.L3:
	movl	-32(%rbp), %eax
	cmpl	%eax, -20(%rbp)
	jle	.L4
	movl	-32(%rbp), %eax
	movl	%eax, -20(%rbp)
.L4:
	addl	$1, -16(%rbp)
.L2:
	movl	-32(%rbp), %eax
	testl	%eax, %eax
	jne	.L5
	pxor	%xmm0, %xmm0
	cvtsi2ss	-28(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2ss	-16(%rbp), %xmm1
	divss	%xmm1, %xmm0
	movss	%xmm0, -12(%rbp)
	cvtss2sd	-12(%rbp), %xmm0
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L7
	call	__stack_chk_fail
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
