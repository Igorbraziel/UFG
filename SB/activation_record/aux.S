.section .rodata

fmt: .string "Valor: x = %ld, i = %d\n"

.data

  .globl x
  .align 8
  x: .quad 10

.text

.globl aux
aux:
  pushq %rbp
  movq %rsp, %rbp

  # Alocando 16 bytes no RA
  subq $16, %rsp

  movq $5, x

  # Copiei o i para %eax
  movl %edi, %eax

  movq %rdi, -8(%rbp)
  movq %rsi, -16(%rbp)

  movq $fmt, %rdi
  movq x, %rsi
  movl %eax, %edx
  movl $0, %eax

  call printf

  movq -8(%rbp), %rdi
  movq -16(%rbp), %rsi

  movslq %edi, %rcx
  addq x, %rcx
  addq (%rsi), %rcx

  movq %rcx, %rax

  leave
  ret