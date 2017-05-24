	.file	"imprimiendo.c"
	.section	.rodata
	.align 8
.LC2:
	.string	"La letra de varChar es: '%c' y su valor ascii es: %hhd \nEl valor de varShort es: %hd \nEl valor de varFloat es: %.2f \nEl valor de varDouble es: %.4lf\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movb	$67, -15(%rbp)
	movw	$333, -14(%rbp)
	movss	.LC0(%rip), %xmm0
	movss	%xmm0, -12(%rbp)
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	cvtss2sd	-12(%rbp), %xmm0
	movswl	-14(%rbp), %ecx
	movsbl	-15(%rbp), %edx
	movsbl	-15(%rbp), %eax
	movsd	-8(%rbp), %xmm1
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$2, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC0:
	.long	1067618140
	.align 8
.LC1:
	.long	1518700436
	.long	1074117843
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
