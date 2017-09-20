	.file	"fun.c"
	.section	.rodata
.LC0:
	.string	"%s"
.LC1:
	.string	"diodo"
	.text
	.globl	cuentapalabras
	.type	cuentapalabras, @function
cuentapalabras:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-64(%rbp), %rax
	movl	$0, (%rax)
	movq	-64(%rbp), %rax
	addq	$4, %rax
	movl	$0, (%rax)
	leaq	-48(%rbp), %rdx
	movq	-56(%rbp), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf
	jmp	.L2
.L4:
	movq	-64(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	-64(%rbp), %rax
	movl	%edx, (%rax)
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	call	strcmp
	testl	%eax, %eax
	jne	.L3
	movq	-64(%rbp), %rax
	addq	$4, %rax
	movq	-64(%rbp), %rdx
	addq	$4, %rdx
	movl	(%rdx), %edx
	addl	$1, %edx
	movl	%edx, (%rax)
.L3:
	leaq	-48(%rbp), %rdx
	movq	-56(%rbp), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf
.L2:
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	feof
	testl	%eax, %eax
	je	.L4
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L6
	call	__stack_chk_fail
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	cuentapalabras, .-cuentapalabras
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
