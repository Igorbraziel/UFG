.section .rodata

fmt: .string "%d, %ld\n"

.data

  .globl values
  .align 4
  values: .long 10,20,10,40,20,50,30,10

.text

.globl process
process:
  pushq %rbp
  movq %rsp, %rbp

  subq $32, %rsp

  movq %rbx, -8(%rbp)

  movl $7, %ebx
bloco_for:
  cmpl $0, %ebx
  jl end_for

  # values[i]
  movq $values, %r10
  movslq %ebx, %rax
  imulq $4, %rax
  addq %rax, %r10

  cmpl (%r10), %edi
  jle bloco_else

  # 2 * limit
  movq %rsi, %r10
  imulq $2, %r10

  # Salvando do RA
  movq %rdi, -16(%rbp)
  movq %rsi, -24(%rbp)

  # aux((short)i, (values + i))
  movw %bx, %di
  movq $values, %r11
  movslq %ebx, %r9
  addq %r11, %r9
  movq %r9, %rsi
  call aux

  # Recuperando do RA
  movq -16(%rbp), %rdi
  movq -24(%rbp), %rsi

  addq %rax, %r10
  movq %r10, %rsi

  jmp end_else

bloco_else:
  # Salvando do RA
  movq %rdi, -16(%rbp)
  movq %rsi, -24(%rbp)
  movq %rdx, -32(%rbp)

  movq %rsi, %rdx
  movl %edi, %esi
  movq $fmt, %rdi
  movl $0, %eax
  call printf

  # Recuperando do RA
  movq -16(%rbp), %rdi
  movq -24(%rbp), %rsi
  movq -32(%rbp), %rdx

end_else:

  decl %ebx
  jmp bloco_for
end_for:

  movq -8(%rbp), %rbx
  
  movq %rsi, %rax

  leave
  ret