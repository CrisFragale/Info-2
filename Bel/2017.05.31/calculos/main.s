	.file	"main.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"elija un numero del 1 al 4. siendo: \n 1 suma\n 2 resta\n 3 multiplicacion\n 4 division"
.LC1:
	.string	"%d"
	.align 8
.LC2:
	.string	"ingrese dos numeros separados por un espacio"
.LC3:
	.string	"%f %f"
.LC5:
	.string	"no se puede dividir por cero."
	.align 8
.LC6:
	.string	"la opci\303\263n que eligi\303\263 est\303\241 fuera de rango"
.LC7:
	.string	"el resultado es: %.2f\n"
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
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC0, %edi
	call	puts
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	$.LC2, %edi
	call	puts
	leaq	-28(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-24(%rbp), %eax
	cmpl	$2, %eax
	je	.L3
	cmpl	$2, %eax
	jg	.L4
	cmpl	$1, %eax
	je	.L5
	jmp	.L2
.L4:
	cmpl	$3, %eax
	je	.L6
	cmpl	$4, %eax
	je	.L7
	jmp	.L2
.L5:
	movq	$suma, -16(%rbp)
	jmp	.L8
.L3:
	movq	$resta, -16(%rbp)
	jmp	.L8
.L6:
	movq	$multiplicacion, -16(%rbp)
	jmp	.L8
.L7:
	movq	$division, -16(%rbp)
	movss	-28(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jp	.L15
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	je	.L14
	jmp	.L15
.L14:
	movl	$.LC5, %edi
	call	puts
	movl	$0, %eax
	jmp	.L12
.L2:
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	jmp	.L8
.L15:
	nop
.L8:
	movss	-28(%rbp), %xmm0
	movl	-32(%rbp), %edx
	movq	-16(%rbp), %rax
	movaps	%xmm0, %xmm1
	movl	%edx, -36(%rbp)
	movss	-36(%rbp), %xmm0
	call	*%rax
	movd	%xmm0, %eax
	movl	%eax, -20(%rbp)
	cvtss2sd	-20(%rbp), %xmm0
	movl	$.LC7, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
.L12:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L13
	call	__stack_chk_fail
.L13:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
