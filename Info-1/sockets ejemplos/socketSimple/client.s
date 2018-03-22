	.file	"client.c"
	.section	.rodata
.LC0:
	.string	"uso: %s hostname port\n"
.LC1:
	.string	"error de lectura en el socket"
.LC2:
	.string	"Recibido: %s"
.LC3:
	.string	"fin\n"
	.align 8
.LC4:
	.string	"Error escribiendo mensaje en socket"
.LC5:
	.string	"Enviado: %s"
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
	subq	$4400, %rsp
	movl	%edi, -4388(%rbp)
	movq	%rsi, -4400(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	cmpl	$2, -4388(%rbp)
	jg	.L2
	movq	-4400(%rbp), %rax
	movq	(%rax), %rdx
	movq	stderr(%rip), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$1, %edi
	call	exit
.L2:
	movq	-4400(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, %edx
	movq	-4400(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	cliente_conectar
	movl	%eax, -4376(%rbp)
	jmp	.L3
.L6:
	leaq	-4112(%rbp), %rcx
	movl	-4376(%rbp), %eax
	movl	$4096, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movl	%eax, -4372(%rbp)
	cmpl	$0, -4372(%rbp)
	jg	.L4
	movl	$.LC1, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L4:
	movl	-4372(%rbp), %eax
	cltq
	movb	$0, -4112(%rbp,%rax)
	leaq	-4112(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	leaq	-4112(%rbp), %rax
	movl	$.LC3, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	je	.L3
	movq	stdin(%rip), %rdx
	leaq	-4368(%rbp), %rax
	movl	$255, %esi
	movq	%rax, %rdi
	call	fgets
	leaq	-4368(%rbp), %rcx
	movl	-4376(%rbp), %eax
	movl	$255, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write
	cmpq	$-1, %rax
	jne	.L5
	movl	$.LC4, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L5:
	leaq	-4368(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
.L3:
	leaq	-4112(%rbp), %rax
	movl	$.LC3, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L6
	movl	-4376(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	$0, %eax
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
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
