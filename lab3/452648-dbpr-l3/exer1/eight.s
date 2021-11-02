	.file	"eight.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Przed wykonaniem instrukcji a[0]=%d, a[1]=%d"
	.align 8
.LC1:
	.string	"Po wykonaniu instrukcji c[0]=%d, c[1]=%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$11, -24(%rbp)
	movl	$12, -20(%rbp)
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
#APP
# 8 "eight.c" 1
	leal -24(%rbp),%edx
	leal -16(%rbp),%ebx
	movl $1,%eax
	movl $2,%ecx
	petla1:
	pushl %eax
	pushl %ecx
	movl $2,%ecx
	pushl %edx
	mull %ecx
	popl %edx
	movl (%edx,%eax,2),%ecx
	pushl %ebx
	movl $2,%ebx
	subl %eax,%ebx
	movl %ebx,%eax
	popl %ebx
	movl %ecx,(%ebx,%eax,2)
	popl %ecx
	popl %eax
	decl %eax
	loop petla1
	
# 0 "" 2
#NO_APP
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L2
	call	__stack_chk_fail@PLT
.L2:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
