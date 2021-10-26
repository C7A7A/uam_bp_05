	.file	"main.cpp"
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
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$12, -28(%rbp)
	leaq	-28(%rbp), %rax
	movq	%rax, -24(%rbp)
	movl	$1, -16(%rbp)
	movl	$2, -12(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, %edi
	call	_Z10pass_valuei@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_Z12pass_pointerPi@PLT
	leaq	-28(%rbp), %rax
	movq	%rax, %rdi
	call	_Z14pass_referenceRi@PLT
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_Z10pass_arrayPi@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
