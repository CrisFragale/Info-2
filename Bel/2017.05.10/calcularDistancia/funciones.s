	.file	"funciones.c"
	.text
	.globl	distancia
	.type	distancia, @function
distancia:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	%ecx, -32(%rbp)
	movl	-28(%rbp), %eax
	subl	-20(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	subl	-20(%rbp), %eax
	imull	%eax, %edx
	movl	-32(%rbp), %eax
	subl	-24(%rbp), %eax
	movl	%eax, %ecx
	movl	-32(%rbp), %eax
	subl	-24(%rbp), %eax
	imull	%ecx, %eax
	addl	%edx, %eax
	pxor	%xmm0, %xmm0
	cvtsi2sd	%eax, %xmm0
	call	sqrt
	cvtsd2ss	%xmm0, %xmm1
	movss	%xmm1, -4(%rbp)
	movss	-4(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	distancia, .-distancia
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
