	.file	"main.cpp"
	.text
	.globl	_Z10pass_valuei
	.type	_Z10pass_valuei, @function
_Z10pass_valuei:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_Z10pass_valuei, .-_Z10pass_valuei
	.globl	_Z12pass_pointerPi
	.type	_Z12pass_pointerPi, @function
_Z12pass_pointerPi:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_Z12pass_pointerPi, .-_Z12pass_pointerPi
	.globl	_Z14pass_referenceRi
	.type	_Z14pass_referenceRi, @function
_Z14pass_referenceRi:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	_Z14pass_referenceRi, .-_Z14pass_referenceRi
	.globl	_Z10pass_arrayPi
	.type	_Z10pass_arrayPi, @function
_Z10pass_arrayPi:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_Z10pass_arrayPi, .-_Z10pass_arrayPi
	.globl	main
	.type	main, @function
main:
.LFB4:
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
	call	_Z10pass_valuei
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_Z12pass_pointerPi
	leaq	-28(%rbp), %rax
	movq	%rax, %rdi
	call	_Z14pass_referenceRi
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_Z10pass_arrayPi
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
