	.file	"c1-1.cpp"
	.text
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt5ctypeIcE8do_widenEc
	.type	_ZNKSt5ctypeIcE8do_widenEc, @function
_ZNKSt5ctypeIcE8do_widenEc:
.LFB1517:
	.cfi_startproc
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE1517:
	.size	_ZNKSt5ctypeIcE8do_widenEc, .-_ZNKSt5ctypeIcE8do_widenEc
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB1764:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %r14
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	leaq	_ZSt4cout(%rip), %r12
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$104, %rsp
	.cfi_def_cfa_offset 160
	movq	%fs:40, %rax
	movq	%rax, 88(%rsp)
	xorl	%eax, %eax
	movq	%rsp, %rbx
	leaq	80(%rsp), %r13
	jmp	.L7
	.p2align 4,,10
	.p2align 3
.L14:
	movsbl	67(%r15), %esi
.L6:
	movq	%rbp, %rdi
	addq	$8, %rbx
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	cmpq	%r13, %rbx
	je	.L12
.L7:
	movq	(%rbx), %rsi
	movq	%r12, %rdi
	call	_ZNSo9_M_insertIlEERSoT_@PLT
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %r15
	testq	%r15, %r15
	je	.L13
	cmpb	$0, 56(%r15)
	jne	.L14
	movq	%r15, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r15), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%r14, %rax
	je	.L6
	movq	%r15, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L6
	.p2align 4,,10
	.p2align 3
.L12:
	movq	88(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L15
	addq	$104, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L13:
	.cfi_restore_state
	call	_ZSt16__throw_bad_castv@PLT
.L15:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1764:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2252:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	_ZStL8__ioinit(%rip), %rbp
	movq	%rbp, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	movq	%rbp, %rsi
	popq	%rbp
	.cfi_def_cfa_offset 8
	leaq	__dso_handle(%rip), %rdx
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE2252:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
