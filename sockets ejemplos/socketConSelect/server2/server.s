	.file	"server.c"
	.section	.rodata
.LC0:
	.string	"uso: %s port\n"
	.align 8
.LC1:
	.string	"Fall\363 la creaci\363n de la conexi\363n"
.LC2:
	.string	"error de lectura en el socket"
.LC3:
	.string	"Recibido: %s"
	.align 8
.LC4:
	.string	"Error escribiendo mensaje en socket"
.LC5:
	.string	"Enviado: %s"
.LC6:
	.string	"fin\n"
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
	pushq	%rbx
	subq	$4552, %rsp
	.cfi_offset 3, -24
	movl	%edi, -4548(%rbp)
	movq	%rsi, -4560(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	cmpl	$1, -4548(%rbp)
	jg	.L2
	movq	-4560(%rbp), %rax
	movq	(%rax), %rdx
	movq	stderr(%rip), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$1, %edi
	call	exit
.L2:
	movq	-4560(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, %edi
	call	servidor_abrirConexion
	movl	%eax, -4540(%rbp)
	cmpl	$-1, -4540(%rbp)
	jne	.L3
	movl	$.LC1, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L3:
	movl	-4540(%rbp), %eax
	movl	%eax, %edi
	call	servidor_aceptarPedidos
	movl	%eax, -4536(%rbp)
	movl	$0, %eax
	movl	$16, %ecx
	leaq	-4512(%rbp), %rdx
	movq	%rdx, %rdi
#APP
# 37 "server.c" 1
	cld; rep; stosq
# 0 "" 2
#NO_APP
	movl	%edi, %eax
	movl	%ecx, %edx
	movl	%edx, -4532(%rbp)
	movl	%eax, -4528(%rbp)
	movl	-4536(%rbp), %eax
	leal	63(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$6, %eax
	movl	%eax, %esi
	movslq	%esi, %rax
	movq	-4512(%rbp,%rax,8), %rdi
	movl	-4536(%rbp), %eax
	cltd
	shrl	$26, %edx
	addl	%edx, %eax
	andl	$63, %eax
	subl	%edx, %eax
	movl	$1, %edx
	movl	%eax, %ecx
	salq	%cl, %rdx
	movq	%rdx, %rax
	orq	%rax, %rdi
	movq	%rdi, %rdx
	movslq	%esi, %rax
	movq	%rdx, -4512(%rbp,%rax,8)
	movq	stdin(%rip), %rax
	movq	%rax, %rdi
	call	fileno
	movl	%eax, %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$26, %eax
	addl	%eax, %edx
	andl	$63, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	$1, %edx
	movl	%eax, %ecx
	salq	%cl, %rdx
	movq	%rdx, %rax
	movq	%rax, %rbx
	movq	stdin(%rip), %rax
	movq	%rax, %rdi
	call	fileno
	leal	63(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$6, %eax
	movl	%eax, %ecx
	movslq	%ecx, %rax
	movq	-4512(%rbp,%rax,8), %rax
	orq	%rbx, %rax
	movq	%rax, %rdx
	movslq	%ecx, %rax
	movq	%rdx, -4512(%rbp,%rax,8)
	movq	stdin(%rip), %rax
	movq	%rax, %rdi
	call	fileno
	cmpl	-4536(%rbp), %eax
	jge	.L4
	movl	-4536(%rbp), %eax
	movl	%eax, -4544(%rbp)
	jmp	.L6
.L4:
	movq	stdin(%rip), %rax
	movq	%rax, %rdi
	call	fileno
	movl	%eax, -4544(%rbp)
	jmp	.L6
.L11:
	movl	-4544(%rbp), %eax
	leal	1(%rax), %edi
	leaq	-4512(%rbp), %rax
	movl	$0, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movq	%rax, %rsi
	call	select
	movl	-4536(%rbp), %eax
	leal	63(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$6, %eax
	cltq
	movq	-4512(%rbp,%rax,8), %rsi
	movl	-4536(%rbp), %eax
	cltd
	shrl	$26, %edx
	addl	%edx, %eax
	andl	$63, %eax
	subl	%edx, %eax
	movl	$1, %edx
	movl	%eax, %ecx
	salq	%cl, %rdx
	movq	%rdx, %rax
	andq	%rsi, %rax
	testq	%rax, %rax
	je	.L7
	leaq	-4128(%rbp), %rcx
	movl	-4536(%rbp), %eax
	movl	$4096, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movl	%eax, -4524(%rbp)
	cmpl	$0, -4524(%rbp)
	jg	.L8
	movl	$.LC2, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L8:
	movl	-4524(%rbp), %eax
	cltq
	movb	$0, -4128(%rbp,%rax)
	leaq	-4128(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	leaq	-4128(%rbp), %rdx
	leaq	-4384(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
	jmp	.L9
.L7:
	movq	stdin(%rip), %rax
	movq	%rax, %rdi
	call	fileno
	leal	63(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$6, %eax
	cltq
	movq	-4512(%rbp,%rax,8), %rbx
	movq	stdin(%rip), %rax
	movq	%rax, %rdi
	call	fileno
	movl	%eax, %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$26, %eax
	addl	%eax, %edx
	andl	$63, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	$1, %edx
	movl	%eax, %ecx
	salq	%cl, %rdx
	movq	%rdx, %rax
	andq	%rbx, %rax
	testq	%rax, %rax
	je	.L9
	movq	stdin(%rip), %rdx
	leaq	-4384(%rbp), %rax
	movl	$255, %esi
	movq	%rax, %rdi
	call	fgets
	leaq	-4384(%rbp), %rcx
	movl	-4536(%rbp), %eax
	movl	$255, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write
	cmpq	$-1, %rax
	jne	.L10
	movl	$.LC4, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L10:
	leaq	-4384(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
.L9:
	movl	$0, %eax
	movl	$16, %ecx
	leaq	-4512(%rbp), %rdx
	movq	%rdx, %rdi
#APP
# 77 "server.c" 1
	cld; rep; stosq
# 0 "" 2
#NO_APP
	movl	%edi, %eax
	movl	%ecx, %edx
	movl	%edx, -4520(%rbp)
	movl	%eax, -4516(%rbp)
	movl	-4536(%rbp), %eax
	leal	63(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$6, %eax
	movl	%eax, %esi
	movslq	%esi, %rax
	movq	-4512(%rbp,%rax,8), %rdi
	movl	-4536(%rbp), %eax
	cltd
	shrl	$26, %edx
	addl	%edx, %eax
	andl	$63, %eax
	subl	%edx, %eax
	movl	$1, %edx
	movl	%eax, %ecx
	salq	%cl, %rdx
	movq	%rdx, %rax
	orq	%rax, %rdi
	movq	%rdi, %rdx
	movslq	%esi, %rax
	movq	%rdx, -4512(%rbp,%rax,8)
	movq	stdin(%rip), %rax
	movq	%rax, %rdi
	call	fileno
	movl	%eax, %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$26, %eax
	addl	%eax, %edx
	andl	$63, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	$1, %edx
	movl	%eax, %ecx
	salq	%cl, %rdx
	movq	%rdx, %rax
	movq	%rax, %rbx
	movq	stdin(%rip), %rax
	movq	%rax, %rdi
	call	fileno
	leal	63(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$6, %eax
	movl	%eax, %ecx
	movslq	%ecx, %rax
	movq	-4512(%rbp,%rax,8), %rax
	orq	%rbx, %rax
	movq	%rax, %rdx
	movslq	%ecx, %rax
	movq	%rdx, -4512(%rbp,%rax,8)
.L6:
	leaq	-4384(%rbp), %rax
	movl	$.LC6, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L11
	movl	-4536(%rbp), %eax
	movl	%eax, %edi
	call	close
	movzbl	.LC7(%rip), %eax
	movb	%al, -4384(%rbp)
	jmp	.L3
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
