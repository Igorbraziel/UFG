.section .rodata

fmt: .string "Soma: %ld\n"

.data

  .globl sum
  .align 8
  sum: .quad 0

  .globl vet
  .align 8
  vet: .quad 10, 20, 30, 40, 50

.text

.globl main
main:
  pushq %rbp
  movq %rsp, %rbp

  movl $0, %ecx

  movq $vet, %r8

begin_while:
  cmpl $5, %ecx
  jge end_while

  movq (%r8), %rax
  addq %rax, sum

  addq $8, %r8

  incl %ecx

  jmp begin_while

end_while:

  movq $fmt, %rdi
  movq sum, %rsi
  movl $0, %eax
  call printf

  movl $0, %eax
  leave
  ret