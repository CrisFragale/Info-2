	.file	"sock-lib.c"
	.section	.rodata
.LC0:
	.string	"Error en gethostbyname"
.LC1:
	.string	"Error en creaci\363n de socket"
	.align 8
.LC2:
	.string	"Error tratando de conectar al server"
	.text
	.globl	cliente_conectar
	.type	cliente_conectar, @function
cliente_conectar:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movl	%esi, -60(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	gethostbyname
	movq	%rax, -40(%rbp)
	cmpq	$0, -40(%rbp)
	jne	.L2
	movl	$.LC0, %edi
	call	herror
	movl	$1, %edi
	call	exit
.L2:
	movl	$0, %edx
	movl	$1, %esi
	movl	$2, %edi
	call	socket
	movl	%eax, -44(%rbp)
	cmpl	$-1, -44(%rbp)
	jne	.L3
	movl	$.LC1, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L3:
	movw	$2, -32(%rbp)
	movl	-60(%rbp), %eax
	movzwl	%ax, %eax
	movl	%eax, %edi
	call	htons
	movw	%ax, -30(%rbp)
	movq	-40(%rbp), %rax
	movq	24(%rax), %rax
	movq	(%rax), %rax
	movl	(%rax), %eax
	movl	%eax, -28(%rbp)
	leaq	-32(%rbp), %rax
	addq	$8, %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	bzero
	leaq	-32(%rbp), %rcx
	movl	-44(%rbp), %eax
	movl	$16, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	connect
	cmpl	$-1, %eax
	jne	.L4
	movl	$.LC2, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L4:
	movl	-44(%rbp), %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L6
	call	__stack_chk_fail
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	cliente_conectar, .-cliente_conectar
	.section	.rodata
	.align 8
.LC3:
	.string	"Error en funci\363n socket. C\363digo de error %s\n"
	.align 8
.LC4:
	.string	"Error en funci\363n bind. C\363digo de error %s\n"
	.align 8
.LC5:
	.string	"Error en funci\363n listen. C\363digo de error %s\n"
	.text
	.globl	servidor_abrirConexion
	.type	servidor_abrirConexion, @function
servidor_abrirConexion:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -52(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %edx
	movl	$1, %esi
	movl	$2, %edi
	call	socket
	movl	%eax, -40(%rbp)
	cmpl	$-1, -40(%rbp)
	jne	.L8
	movl	-40(%rbp), %eax
	movl	%eax, %edi
	call	strerror
	movq	%rax, %rdx
	movq	stderr(%rip), %rax
	movl	$.LC3, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$-1, %eax
	jmp	.L12
.L8:
	movw	$2, -32(%rbp)
	movl	-52(%rbp), %eax
	movzwl	%ax, %eax
	movl	%eax, %edi
	call	htons
	movw	%ax, -30(%rbp)
	movl	$0, -28(%rbp)
	leaq	-32(%rbp), %rax
	addq	$8, %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	bzero
	leaq	-32(%rbp), %rcx
	movl	-40(%rbp), %eax
	movl	$16, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	bind
	movl	%eax, -36(%rbp)
	cmpl	$-1, -36(%rbp)
	jne	.L10
	movl	-36(%rbp), %eax
	movl	%eax, %edi
	call	strerror
	movq	%rax, %rdx
	movq	stderr(%rip), %rax
	movl	$.LC4, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$-1, %eax
	jmp	.L12
.L10:
	movl	-40(%rbp), %eax
	movl	$10, %esi
	movl	%eax, %edi
	call	listen
	movl	%eax, -36(%rbp)
	cmpl	$-1, -36(%rbp)
	jne	.L11
	movl	-36(%rbp), %eax
	movl	%eax, %edi
	call	strerror
	movq	%rax, %rdx
	movq	stderr(%rip), %rax
	movl	$.LC5, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$-1, %eax
	jmp	.L12
.L11:
	movl	-40(%rbp), %eax
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
.LFE3:
	.size	servidor_abrirConexion, .-servidor_abrirConexion
	.section	.rodata
	.align 8
.LC6:
	.string	"Error en funci\363n accept. C\363digo de error %s\n"
.LC7:
	.string	"server:  conexion desde:  %s\n"
	.text
	.globl	servidor_aceptarPedidos
	.type	servidor_aceptarPedidos, @function
servidor_aceptarPedidos:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -52(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$16, -40(%rbp)
	leaq	-40(%rbp), %rdx
	leaq	-32(%rbp), %rcx
	movl	-52(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	accept
	movl	%eax, -36(%rbp)
	cmpl	$-1, -36(%rbp)
	jne	.L15
	movl	-36(%rbp), %eax
	movl	%eax, %edi
	call	strerror
	movq	%rax, %rdx
	movq	stderr(%rip), %rax
	movl	$.LC6, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$-1, %eax
	jmp	.L17
.L15:
	movl	-28(%rbp), %eax
	movl	%eax, %edi
	call	inet_ntoa
	movq	%rax, %rsi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	movl	-36(%rbp), %eax
.L17:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L18
	call	__stack_chk_fail
.L18:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	servidor_aceptarPedidos, .-servidor_aceptarPedidos
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
