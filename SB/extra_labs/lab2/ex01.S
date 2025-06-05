.section .rodata

.data

  .globl a
  .align 4
  a: .long 30

  .globl b
  .align 4
  b: .long 45

  .globl c
  .align 4
  c: .long -60

  .globl d
  .align 4
  d: .long 25

.text

.globl ex01
ex01:
  pushq %rbp
  movq %rsp, %rbp

  movl a, %eax
  cmpl b, %eax
  jle end_if_1

  movl c, %eax
  negl %eax
  movl %eax, c 

  movl c, %eax				# eax = c
	cltd							# edx = sinal(eax)
	movl $3, %ecx
	idivl %ecx				# c / 3
	movl %eax, d
end_if_1:
  movl a, %eax
  cmpl %eax, b
  jl end_if_2

  movl a, %r8d
  addl b, %r8d
  movl c, %ecx
  imull %r8d, %ecx
  movl %ecx, c

  movl $1024, d

end_if_2:

  leave
  ret