.section .rodata

.data

  .globl v1
  .align 2
  v1: .word 1, 2

  .globl v2
  .align 8
  v2: .quad 1, 2, 3

.text

.globl aux
aux:
  pushq %rbp
  movq %rsp, %rbp

  subq $32, %rsp

  movq %rbx, -8(%rbp) # Salvei, agora posso usar o %rbx

  movl $2, %ebx # %ebx representa o i

bloco_for:
  cmpl $0, %ebx
  jl end_for

  movq %rdi, -16(%rbp)
  movq %rsi, -24(%rbp)

  movq $v2, %rdx
  movl %ebx, %ecx
  call sum

  movq -16(%rbp), %rdi
  movq -24(%rbp), %rsi

  decl %ebx
  jmp bloco_for

end_for:

  movq -8(%rbp), %rbx

  leave
  ret

.globl main
main: 
  pushq %rbp
  movq %rsp, %rbp

  subq $16, %rsp

  movq %rbx, -8(%rbp)

  movl $0, %ebx

begin_while:
  cmpl $2, %ebx
  jge end_while

  movq $v1, %rdi
  movl %ebx, %esi
  call aux

  incl %ebx
  jmp begin_while

end_while:

  movq -8(%rbp), %rbx

  movl $0, %eax
  leave
  ret

