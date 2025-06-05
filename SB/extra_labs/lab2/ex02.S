.section .rodata

.data

  .globl a
  .align 4
  a: .long 0

  .globl b
  .align 8
  b: .quad 2

.text

.globl ex02
ex02:
  pushq %rbp
  movq %rsp, %rbp

  # external if
  movl a, %eax
  cmpl $0, %eax
  jz end_if1

  movq b, %rdx
  cmpq $5, %rdx
  jge begin_else1

  movl a, %eax
  shll $1, %eax

  movslq a, %rcx
  imulq b, %rcx
  
  movslq %eax, %rax

  addq %rax, %rcx
  movq %rcx, b

  jmp end_if1

begin_else1:
    movq b, %r9
    xorq $0x1F, %r9
    movl %r9d, a

end_if1:

  leave
  ret