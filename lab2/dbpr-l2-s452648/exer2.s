	.file	"main.cpp"; nazwa pliku źródłowego
	.text; sekcja - text
	.globl	c; nazwa globalnego symbolu c
	.data; sekcja - data
	.align 4
	.type	c, @object; typ symbolu c - obiekt
	.size	c, 4; rozmiar symbolu c
c:
	.long	16; generuje long integer o wartości 16
	.text; sekcja - text
	.globl	main; nazwa symbolu main
	.type	main, @function; typ symbolu main - funkcja
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp; zapisuje adres poprzedniej ramki stosu
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp; przemieszcza rbp do rsp (adres aktualnej ramki stosu)
	.cfi_def_cfa_register 6
	movq	$5, -16(%rbp); zapisuje na stosie wartość 5
	movq	$16, -8(%rbp); zapisuje na stosie wartość 16
	movq	-16(%rbp), %rax; wartość w returnie powinna być w registrze rax, przemieszcza 16 do rax
	movl	%eax, %edx; przemieszcza edx do eax
	movq	-8(%rbp), %rax; wartość w returnie powinna być w registrze rax, przemieszcza 5 do rax
	addl	%edx, %eax; dodaje zmienne o wartości 5 i 16
	popq	%rbp; pobiera ze stosu 5+16
	.cfi_def_cfa 7, 8
	ret; return 21
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
