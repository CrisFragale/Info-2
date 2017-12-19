	.file	"fun3.c"
	.section	.rodata
.LC0:
	.string	"127.0.0.1"
	.align 8
.LC1:
	.string	"Error escribiendo mensaje en socket"
.LC2:
	.string	"sali"
	.text
	.globl	fun3
	.type	fun3, @function
fun3:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movq	%rdi, -88(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1515, %esi
	movl	$.LC0, %edi
	call	cliente_conectar
	movl	%eax, -68(%rbp)
	jmp	.L2
.L4:
	movq	-88(%rbp), %rcx
	movl	-68(%rbp), %eax
	movl	$44, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write
	cmpq	$-1, %rax
	jne	.L3
	movl	$.LC1, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L3:
	movq	-88(%rbp), %rax
	movq	48(%rax), %rax
	movq	%rax, -88(%rbp)
.L2:
	cmpq	$0, -88(%rbp)
	jne	.L4
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$-1, -64(%rbp)
	leaq	-64(%rbp), %rcx
	movl	-68(%rbp), %eax
	movl	$44, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write
	cmpq	$-1, %rax
	jne	.L5
	movl	$.LC1, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L5:
	movl	-68(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L7
	call	__stack_chk_fail
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	fun3, .-fun3
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
