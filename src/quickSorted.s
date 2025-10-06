	.file	"quickSorted.c"
	.text
	.globl	sort_array
	.type	sort_array, @function
sort_array:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	cmpl	$1, -44(%rbp)
	jg	.L2
	movl	$0, %eax
	jmp	.L3
.L2:
	movl	$0, -20(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L4
.L9:
	movl	-16(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	.L5
.L7:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L6
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
.L6:
	addl	$1, -8(%rbp)
.L5:
	movl	-8(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L7
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	je	.L8
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-40(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	movl	%eax, (%rdx)
	addl	$1, -20(%rbp)
.L8:
	addl	$1, -16(%rbp)
.L4:
	movl	-44(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -16(%rbp)
	jl	.L9
	movl	-20(%rbp), %eax
.L3:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	sort_array, .-sort_array
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits
