	.file	"stack.c"
	.text
	.globl	DestroyStack
	.type	DestroyStack, @function
DestroyStack:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	DestroyStack, .-DestroyStack
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	InitStack
	.type	InitStack, @function
InitStack:
.LFB6:
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
	movl	$4100, %edi
	call	malloc@PLT
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	$-1, 4096(%rax)
.L6:
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-20(%rbp), %eax
	testl	%eax, %eax
	jne	.L3
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L7
	jmp	.L8
.L3:
	movq	-16(%rbp), %rax
	movl	4096(%rax), %eax
	cmpl	$1024, %eax
	je	.L6
	movq	-16(%rbp), %rax
	movl	4096(%rax), %eax
	leal	1(%rax), %edx
	movl	-20(%rbp), %ecx
	movq	-16(%rbp), %rax
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	movq	-16(%rbp), %rax
	movl	4096(%rax), %eax
	leal	1(%rax), %edx
	movq	-16(%rbp), %rax
	movl	%edx, 4096(%rax)
	jmp	.L6
.L8:
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	InitStack, .-InitStack
	.section	.rodata
.LC1:
	.string	"%d "
	.text
	.globl	printlist
	.type	printlist, @function
printlist:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	jmp	.L10
.L11:
	movq	-8(%rbp), %rax
	movl	4096(%rax), %eax
	leal	1(%rax), %edx
	movq	-8(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movl	4096(%rax), %eax
	leal	1(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 4096(%rax)
.L10:
	movq	-8(%rbp), %rax
	movl	4096(%rax), %eax
	cmpl	$-1, %eax
	jne	.L11
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	printlist, .-printlist
	.globl	ClearStack
	.type	ClearStack, @function
ClearStack:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L14
	movq	-8(%rbp), %rax
	movl	$-1, 4096(%rax)
.L14:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	ClearStack, .-ClearStack
	.globl	StackIsEmpty
	.type	StackIsEmpty, @function
StackIsEmpty:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L16
	movq	-8(%rbp), %rax
	movl	4096(%rax), %eax
	cmpl	$-1, %eax
	sete	%al
	movzbl	%al, %eax
	jmp	.L15
.L16:
.L15:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	StackIsEmpty, .-StackIsEmpty
	.globl	StackLength
	.type	StackLength, @function
StackLength:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L19
	movq	-8(%rbp), %rax
	movl	4096(%rax), %eax
	addl	$1, %eax
	jmp	.L18
.L19:
.L18:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	StackLength, .-StackLength
	.globl	GetTop
	.type	GetTop, @function
GetTop:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L22
	movq	-8(%rbp), %rax
	movl	4096(%rax), %eax
	leal	1(%rax), %edx
	movq	-8(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	jmp	.L21
.L22:
.L21:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	GetTop, .-GetTop
	.globl	Pop
	.type	Pop, @function
Pop:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	4096(%rax), %eax
	cmpl	$-1, %eax
	je	.L25
	movq	-24(%rbp), %rax
	movl	4096(%rax), %edx
	movq	-24(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	movl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	movl	4096(%rax), %eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 4096(%rax)
	movl	-4(%rbp), %eax
	jmp	.L24
.L25:
.L24:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	Pop, .-Pop
	.globl	Push
	.type	Push, @function
Push:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	4096(%rax), %eax
	cmpl	$1024, %eax
	je	.L29
	movq	-8(%rbp), %rax
	movl	4096(%rax), %eax
	leal	1(%rax), %edx
	movq	-8(%rbp), %rax
	movslq	%edx, %rdx
	movl	-12(%rbp), %ecx
	movl	%ecx, (%rax,%rdx,4)
	movq	-8(%rbp), %rax
	movl	4096(%rax), %eax
	leal	1(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 4096(%rax)
.L29:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	Push, .-Push
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
