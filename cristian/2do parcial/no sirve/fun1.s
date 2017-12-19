	.file	"fun1.c"
	.text
	.globl	lecturaTemas
	.type	lecturaTemas, @function
lecturaTemas:
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
	movl	$2, -72(%rbp)
	movq	-96(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	open
	movl	%eax, -68(%rbp)
	leaq	-64(%rbp), %rcx
	movl	-68(%rbp), %eax
	movl	$48, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movl	%eax, -76(%rbp)
	jmp	.L2
.L6:
	cmpl	$2, -72(%rbp)
	jne	.L3
	movq	-88(%rbp), %rax
	pushq	-24(%rbp)
	pushq	-32(%rbp)
	pushq	-40(%rbp)
	pushq	-48(%rbp)
	pushq	-56(%rbp)
	pushq	-64(%rbp)
	movq	%rax, %rdi
	call	insertarini
	addq	$48, %rsp
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rax
	movq	(%rax), %rax
	movl	44(%rax), %edx
	subl	$1, %edx
	movl	%edx, 44(%rax)
.L3:
	movq	-88(%rbp), %rax
	pushq	-24(%rbp)
	pushq	-32(%rbp)
	pushq	-40(%rbp)
	pushq	-48(%rbp)
	pushq	-56(%rbp)
	pushq	-64(%rbp)
	movq	%rax, %rdi
	call	corroborar
	addq	$48, %rsp
	testl	%eax, %eax
	jne	.L4
	movq	-88(%rbp), %rax
	pushq	-24(%rbp)
	pushq	-32(%rbp)
	pushq	-40(%rbp)
	pushq	-48(%rbp)
	pushq	-56(%rbp)
	pushq	-64(%rbp)
	movq	%rax, %rdi
	call	insertarini
	addq	$48, %rsp
	movl	%eax, -72(%rbp)
	cmpl	$0, -72(%rbp)
	je	.L4
	movl	$-1, %eax
	jmp	.L7
.L4:
	leaq	-64(%rbp), %rcx
	movl	-68(%rbp), %eax
	movl	$48, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movl	%eax, -76(%rbp)
.L2:
	cmpl	$0, -76(%rbp)
	jne	.L6
	movl	-68(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	$0, %eax
.L7:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L8
	call	__stack_chk_fail
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	lecturaTemas, .-lecturaTemas
	.globl	insertarini
	.type	insertarini, @function
insertarini:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$56, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L10
	movl	$-1, %eax
	jmp	.L11
.L10:
	movq	-8(%rbp), %rax
	movq	$0, 48(%rax)
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
	movl	56(%rbp), %edx
	movl	%edx, 40(%rax)
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 48(%rax)
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	movl	$0, %eax
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	insertarini, .-insertarini
	.globl	corroborar
	.type	corroborar, @function
corroborar:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	pushq	56(%rbp)
	pushq	48(%rbp)
	pushq	40(%rbp)
	pushq	32(%rbp)
	pushq	24(%rbp)
	pushq	16(%rbp)
	movq	%rax, %rdi
	call	busqueda
	addq	$48, %rsp
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L13
	movl	$0, %eax
	jmp	.L14
.L13:
	movq	-8(%rbp), %rax
	movl	44(%rax), %eax
	leal	1(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 44(%rax)
	movl	$1, %eax
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	corroborar, .-corroborar
	.globl	busqueda
	.type	busqueda, @function
busqueda:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	jmp	.L16
.L19:
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movl	16(%rbp), %eax
	cmpl	%eax, %edx
	jne	.L17
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	jmp	.L18
.L17:
	movq	-24(%rbp), %rax
	movq	48(%rax), %rax
	movq	%rax, -24(%rbp)
.L16:
	cmpq	$0, -24(%rbp)
	jne	.L19
	movl	$0, %eax
.L18:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	busqueda, .-busqueda
	.section	.rodata
	.align 8
.LC0:
	.string	"dato:\n codigo: %d \n nombre: %s \n autor: %s \n cantidad: %d \n"
	.text
	.globl	imprimir
	.type	imprimir, @function
imprimir:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	jmp	.L21
.L22:
	movq	-8(%rbp), %rax
	movl	44(%rax), %esi
	movq	-8(%rbp), %rax
	leaq	24(%rax), %rcx
	movq	-8(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%esi, %r8d
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movq	48(%rax), %rax
	movq	%rax, -8(%rbp)
.L21:
	cmpq	$0, -8(%rbp)
	jne	.L22
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	imprimir, .-imprimir
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
