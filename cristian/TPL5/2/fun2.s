	.file	"fun2.c"
	.section	.rodata
	.align 8
.LC1:
	.string	"El error cometido en X fue de %f \n"
	.align 8
.LC2:
	.string	"El error cometido en y fue de %f \n"
	.text
	.globl	promediar
	.type	promediar, @function
promediar:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$232, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -232(%rbp)
	movq	%rsi, -240(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	$0, -192(%rbp)
	movq	$0, -184(%rbp)
	movl	$0, -216(%rbp)
	movl	$0, -200(%rbp)
	movl	$0, -196(%rbp)
	movl	$0, -212(%rbp)
	pxor	%xmm0, %xmm0
	movss	%xmm0, -208(%rbp)
	pxor	%xmm0, %xmm0
	movss	%xmm0, -204(%rbp)
	jmp	.L2
.L19:
	movq	-232(%rbp), %rdx
	leaq	-112(%rbp), %rax
	movl	$40, %esi
	movq	%rax, %rdi
	call	fgets
	movq	-240(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movl	$40, %esi
	movq	%rax, %rdi
	call	fgets
	leaq	-112(%rbp), %rax
	movq	%rax, -192(%rbp)
	jmp	.L3
.L4:
	addq	$1, -192(%rbp)
.L3:
	movq	-192(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$44, %al
	jne	.L4
	leaq	-64(%rbp), %rax
	movq	%rax, -184(%rbp)
	jmp	.L5
.L6:
	addq	$1, -184(%rbp)
.L5:
	movq	-184(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$44, %al
	jne	.L6
	movl	$0, -216(%rbp)
	addq	$1, -192(%rbp)
	jmp	.L7
.L9:
	movq	-192(%rbp), %rax
	movzbl	(%rax), %edx
	movl	-216(%rbp), %eax
	cltq
	movb	%dl, -176(%rbp,%rax)
	addq	$1, -192(%rbp)
	addl	$1, -216(%rbp)
.L7:
	movq	-192(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$44, %al
	je	.L8
	movq	-192(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L9
.L8:
	cmpl	$0, -216(%rbp)
	je	.L9
	movl	-216(%rbp), %eax
	addl	$1, %eax
	cltq
	movb	$0, -176(%rbp,%rax)
	movl	$0, -216(%rbp)
	addq	$1, -184(%rbp)
	jmp	.L10
.L12:
	movq	-184(%rbp), %rax
	movzbl	(%rax), %edx
	movl	-216(%rbp), %eax
	cltq
	movb	%dl, -160(%rbp,%rax)
	addq	$1, -184(%rbp)
	addl	$1, -216(%rbp)
.L10:
	movq	-184(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$44, %al
	je	.L11
	movq	-184(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L12
.L11:
	cmpl	$0, -216(%rbp)
	je	.L12
	movl	-216(%rbp), %eax
	addl	$1, %eax
	cltq
	movb	$0, -160(%rbp,%rax)
	movl	$0, -216(%rbp)
	addq	$1, -192(%rbp)
	jmp	.L13
.L15:
	movq	-192(%rbp), %rax
	movzbl	(%rax), %edx
	movl	-216(%rbp), %eax
	cltq
	movb	%dl, -144(%rbp,%rax)
	addq	$1, -192(%rbp)
	addl	$1, -216(%rbp)
.L13:
	movq	-192(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$44, %al
	je	.L14
	movq	-192(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L15
.L14:
	cmpl	$0, -216(%rbp)
	je	.L15
	movl	-216(%rbp), %eax
	addl	$1, %eax
	cltq
	movb	$0, -144(%rbp,%rax)
	movl	$0, -216(%rbp)
	addq	$1, -184(%rbp)
	jmp	.L16
.L18:
	movq	-184(%rbp), %rax
	movzbl	(%rax), %edx
	movl	-216(%rbp), %eax
	cltq
	movb	%dl, -128(%rbp,%rax)
	addq	$1, -184(%rbp)
	addl	$1, -216(%rbp)
.L16:
	movq	-184(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$44, %al
	je	.L17
	movq	-184(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L18
.L17:
	cmpl	$0, -216(%rbp)
	je	.L18
	movl	-216(%rbp), %eax
	addl	$1, %eax
	cltq
	movb	$0, -128(%rbp,%rax)
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, %ebx
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	atoi
	subl	%eax, %ebx
	movl	%ebx, %eax
	movl	%eax, -200(%rbp)
	leaq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, %ebx
	leaq	-144(%rbp), %rax
	movq	%rax, %rdi
	call	atoi
	subl	%eax, %ebx
	movl	%ebx, %eax
	movl	%eax, -196(%rbp)
	addl	$1, -212(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2ss	-200(%rbp), %xmm0
	movss	-208(%rbp), %xmm1
	addss	%xmm1, %xmm0
	movss	%xmm0, -208(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2ss	-196(%rbp), %xmm0
	movss	-204(%rbp), %xmm1
	addss	%xmm1, %xmm0
	movss	%xmm0, -204(%rbp)
.L2:
	movq	-232(%rbp), %rax
	movq	%rax, %rdi
	call	feof
	testl	%eax, %eax
	je	.L19
	pxor	%xmm0, %xmm0
	cvtsi2ss	-212(%rbp), %xmm0
	movss	-208(%rbp), %xmm1
	divss	%xmm0, %xmm1
	movaps	%xmm1, %xmm0
	movss	%xmm0, -208(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2ss	-212(%rbp), %xmm0
	movss	-204(%rbp), %xmm1
	divss	%xmm0, %xmm1
	movaps	%xmm1, %xmm0
	movss	%xmm0, -204(%rbp)
	cvtss2sd	-208(%rbp), %xmm0
	movl	$.LC1, %edi
	movl	$1, %eax
	call	printf
	cvtss2sd	-204(%rbp), %xmm0
	movl	$.LC2, %edi
	movl	$1, %eax
	call	printf
	movq	-232(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	movq	-240(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	movl	$0, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L21
	call	__stack_chk_fail
.L21:
	addq	$232, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	promediar, .-promediar
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
