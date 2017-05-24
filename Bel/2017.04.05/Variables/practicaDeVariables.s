	.file	"practicaDeVariables.c"
	.section	.rodata
.LC1:
	.string	"ingrese operando 1"
.LC2:
	.string	"%f"
.LC3:
	.string	"ingrese operando 2"
.LC4:
	.string	"el resultado es: %d\n"
.LC5:
	.string	"el resultado es: %f\n"
	.align 8
.LC6:
	.string	"0 no es un valor valido para el segundo operando."
	.align 8
.LC7:
	.string	"imbecil, cualquier numero menos 0."
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
	pxor	%xmm0, %xmm0
	movss	%xmm0, -24(%rbp)
	movl	$.LC1, %edi
	call	puts
	leaq	-28(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	$.LC3, %edi
	call	puts
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movss	-28(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, -20(%rbp)
	movss	-24(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, -16(%rbp)
	movss	-24(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jp	.L12
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	je	.L14
.L12:
	movss	-28(%rbp), %xmm1
	movss	-24(%rbp), %xmm0
	addss	%xmm1, %xmm0
	movss	%xmm0, -12(%rbp)
	movss	-12(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movss	-28(%rbp), %xmm0
	movss	-24(%rbp), %xmm1
	subss	%xmm1, %xmm0
	movss	%xmm0, -12(%rbp)
	movss	-12(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movss	-28(%rbp), %xmm1
	movss	-24(%rbp), %xmm0
	mulss	%xmm1, %xmm0
	movss	%xmm0, -12(%rbp)
	movss	-12(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movss	-28(%rbp), %xmm0
	movss	-24(%rbp), %xmm1
	divss	%xmm1, %xmm0
	movss	%xmm0, -12(%rbp)
	cvtss2sd	-12(%rbp), %xmm0
	movl	$.LC5, %edi
	movl	$1, %eax
	call	printf
	movl	-20(%rbp), %eax
	cltd
	idivl	-16(%rbp)
	movl	%edx, %eax
	pxor	%xmm0, %xmm0
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -12(%rbp)
	movss	-12(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	jmp	.L4
.L14:
	movl	$.LC6, %edi
	call	puts
.L4:
	movl	$.LC3, %edi
	call	puts
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movss	-24(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jp	.L5
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jne	.L5
	jmp	.L7
.L8:
	movl	$.LC7, %edi
	call	puts
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	__isoc99_scanf
.L7:
	movss	-24(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jp	.L5
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	je	.L8
.L5:
	movss	-28(%rbp), %xmm1
	movss	-24(%rbp), %xmm0
	addss	%xmm1, %xmm0
	movss	%xmm0, -12(%rbp)
	movss	-12(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movss	-28(%rbp), %xmm0
	movss	-24(%rbp), %xmm1
	subss	%xmm1, %xmm0
	movss	%xmm0, -12(%rbp)
	movss	-12(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movss	-28(%rbp), %xmm1
	movss	-24(%rbp), %xmm0
	mulss	%xmm1, %xmm0
	movss	%xmm0, -12(%rbp)
	movss	-12(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movss	-28(%rbp), %xmm0
	movss	-24(%rbp), %xmm1
	divss	%xmm1, %xmm0
	movss	%xmm0, -12(%rbp)
	cvtss2sd	-12(%rbp), %xmm0
	movl	$.LC5, %edi
	movl	$1, %eax
	call	printf
	movl	-20(%rbp), %eax
	cltd
	idivl	-16(%rbp)
	movl	%edx, %eax
	pxor	%xmm0, %xmm0
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -12(%rbp)
	movss	-12(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L11
	call	__stack_chk_fail
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
