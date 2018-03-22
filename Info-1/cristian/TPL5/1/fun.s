	.file	"fun.c"
	.text
	.globl	lecturaPacientes
	.type	lecturaPacientes, @function
lecturaPacientes:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movq	%rdi, -88(%rbp)
	movq	%rsi, -96(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-96(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	open
	movl	%eax, -72(%rbp)
	cmpl	$-1, -72(%rbp)
	jne	.L2
	movl	$-3, %eax
	jmp	.L8
.L2:
	leaq	-64(%rbp), %rcx
	movl	-72(%rbp), %eax
	movl	$56, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movl	%eax, -76(%rbp)
	cmpl	$-1, -76(%rbp)
	jne	.L5
	movl	-76(%rbp), %eax
	jmp	.L8
.L7:
	movq	-88(%rbp), %rax
	subq	$8, %rsp
	pushq	-16(%rbp)
	pushq	-24(%rbp)
	pushq	-32(%rbp)
	pushq	-40(%rbp)
	pushq	-48(%rbp)
	pushq	-56(%rbp)
	pushq	-64(%rbp)
	movq	%rax, %rdi
	call	insetarorden
	addq	$64, %rsp
	movl	%eax, -68(%rbp)
	cmpl	$-1, -68(%rbp)
	jne	.L6
	movl	$-2, %eax
	jmp	.L8
.L6:
	leaq	-64(%rbp), %rcx
	movl	-72(%rbp), %eax
	movl	$56, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movl	%eax, -76(%rbp)
	cmpl	$-1, -76(%rbp)
	jne	.L5
	movl	-76(%rbp), %eax
	jmp	.L8
.L5:
	cmpl	$0, -76(%rbp)
	jne	.L7
	movl	-72(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	$0, %eax
.L8:
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L9
	call	__stack_chk_fail
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	lecturaPacientes, .-lecturaPacientes
	.globl	insetarorden
	.type	insetarorden, @function
insetarorden:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movl	$64, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L11
	movl	$-1, %eax
	jmp	.L12
.L11:
	movq	-8(%rbp), %rax
	movq	16(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	32(%rbp), %rdx
	movq	%rdx, 16(%rax)
	movq	40(%rbp), %rdx
	movq	%rdx, 24(%rax)
	movq	48(%rbp), %rdx
	movq	%rdx, 32(%rax)
	movq	56(%rbp), %rdx
	movq	%rdx, 40(%rax)
	movq	64(%rbp), %rdx
	movq	%rdx, 48(%rax)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L13
	movq	-40(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 56(%rax)
	movl	$0, %eax
	jmp	.L12
.L13:
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movss	48(%rax), %xmm0
	movq	-8(%rbp), %rax
	movss	48(%rax), %xmm1
	ucomiss	%xmm1, %xmm0
	jb	.L22
	movq	-40(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 56(%rax)
	movq	-40(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	movl	$0, %eax
	jmp	.L12
.L22:
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	56(%rax), %rax
	movq	%rax, -16(%rbp)
	jmp	.L16
.L18:
	movq	-16(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	56(%rax), %rax
	movq	%rax, -16(%rbp)
.L16:
	cmpq	$0, -16(%rbp)
	je	.L17
	movq	-16(%rbp), %rax
	movss	48(%rax), %xmm1
	movq	-8(%rbp), %rax
	movss	48(%rax), %xmm0
	ucomiss	%xmm1, %xmm0
	jnb	.L18
.L17:
	cmpq	$0, -16(%rbp)
	jne	.L19
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 56(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 56(%rax)
	jmp	.L20
.L19:
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 56(%rax)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 56(%rax)
.L20:
	movl	$0, %eax
.L12:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	insetarorden, .-insetarorden
	.section	.rodata
.LC0:
	.string	"turno %f \n"
	.text
	.globl	imprimir
	.type	imprimir, @function
imprimir:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	jmp	.L24
.L25:
	movq	-8(%rbp), %rax
	movss	48(%rax), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movl	$.LC0, %edi
	movl	$1, %eax
	call	printf
	movq	-8(%rbp), %rax
	movq	56(%rax), %rax
	movq	%rax, -8(%rbp)
.L24:
	cmpq	$0, -8(%rbp)
	jne	.L25
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	imprimir, .-imprimir
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
