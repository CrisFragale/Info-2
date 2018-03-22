	.file	"server.c"
	.section	.rodata
.LC0:
	.string	"uso: %s port\n"
	.align 8
.LC1:
	.string	"Fall\363 la creaci\363n de la conexi\363n"
	.align 8
.LC2:
	.string	"Error escribiendo mensaje en socket"
.LC3:
	.string	"Enviado: %s"
.LC4:
	.string	"fin\n"
.LC5:
	.string	"error de lectura en el socket"
.LC6:
	.string	"Recibido: %s"
.LC7:
	.string	""
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
	cmpl	$1, -4388(%rbp)
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
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, %edi
	call	servidor_abrirConexion
	movl	%eax, -4380(%rbp)
	cmpl	$-1, -4380(%rbp)
	jne	.L3
	movl	$.LC1, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L3:
	movl	-4380(%rbp), %eax
	movl	%eax, %edi
	call	servidor_aceptarPedidos
	movl	%eax, -4376(%rbp)
	jmp	.L4
.L7:
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
	movl	$.LC2, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L5:
	leaq	-4368(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	leaq	-4368(%rbp), %rax
	movl	$.LC4, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	je	.L4
	leaq	-4112(%rbp), %rcx
	movl	-4376(%rbp), %eax
	movl	$4096, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movl	%eax, -4372(%rbp)
	cmpl	$0, -4372(%rbp)
	jg	.L6
	movl	$.LC5, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L6:
	movl	-4372(%rbp), %eax
	cltq
	movb	$0, -4112(%rbp,%rax)
	leaq	-4112(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
.L4:
	leaq	-4368(%rbp), %rax
	movl	$.LC4, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L7
	movl	-4376(%rbp), %eax
	movl	%eax, %edi
	call	close
	movzbl	.LC7(%rip), %eax
	movb	%al, -4368(%rbp)
	jmp	.L3
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
