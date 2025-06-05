.section .rodata

.data

  .globl v1
  .align 2
  v1: .word 32, 34, 27, 4

  .globl v2
  .align 4
  v2: .long 12, 22, 31, 23, 6

  .globl v3
  .align 1
  v3: .byte 0, 0, 0, 0

  .globl v4
  .align 8
  v4: .quad 0, 0, 0, 0, 0, 0, 0, 0

  .globl i
  .align 4
  i: .long 0

  .globl j
  .align 2
  j: .word 0

.text

.globl aux
aux:
  pushq %rbp
  movq %rsp, %rbp

  movl $0, i
begin_for:
  cmpl $4, i
  jge end_for

  movw $0, j

begin_while:

  cmpw $5, j
  jge end_while

  movswl j, %eax
  cmpl %eax, i
  jnz begin_else

  # v3[i]
  movq $v3, %r8
  movslq i, %rdi
  imulq $1, %rdi
  addq %rdi, %r8  

  # v1[i]
  movq $v1, %r9
  movslq i, %rdi
  imulq $2, %rdi
  addq %rdi, %r9

  # v2[j]
  movq $v2, %r10
  movswq j, %rsi
  imulq $4, %rsi
  addq %rsi, %r10

  movswl (%r9), %r11d
  addl (%r10), %r11d

  movb %r11b, (%r8)

  jmp end_else

begin_else:

  # v4[i + j]
  movq $v4, %rdx
  movswl j, %eax
  addl i, %eax
  movslq %eax, %rax
  imulq $8, %rax
  addq %rax, %rdx

  # v1[i]
  movq $v1, %r9
  movslq i, %rdi
  imulq $2, %rdi
  addq %rdi, %r9

  # v2[j]
  movq $v2, %r10
  movswq j, %rsi
  imulq $4, %rsi
  addq %rsi, %r10

  movswl (%r9), %r11d
  addl (%r10), %r11d

  movslq %r11d, %r11
  addq %r11, (%rdx)

end_else:

  incw j
  jmp begin_while

end_while:

  incl i
  jmp begin_for

end_for:

  leave
  ret