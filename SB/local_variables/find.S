.section .rodata

fmt1: .string "Objeto local [1] igual!\n"
fmt2: .string "Objeto global igual!\n"

.data

  .globl gObj
  .align 4
  gObj: .zero 24

.text

.globl find
find:
  pushq %rbp
  movq %rsp, %rbp

  subq $80, %rsp

  movl $0, -12(%rbp)

  movq %rdi, -8(%rbp)

  movq $gObj, %rdi
  movl $0, %esi
  call init_obj

  leaq -60(%rbp), %rdi
  movl $1, %esi
  call init_obj

  leaq -36(%rbp), %rdi
  movl $2, %esi
  call init_obj

  leaq -70(%rbp), %rdi
  call init_pins

  movq -8(%rbp), %rdi

  movq %rdi, -8(%rbp)

  movq %rdi, %rsi
  leaq -32(%rbp), %rdi
  call compare_guid

  movq -8(%rbp), %rdi

  cmpl $0, %eax
  jz end_if

  movq %rdi, -8(%rbp)

  movq $fmt1, %rdi
  movl $0, %eax
  call printf

  movq -8(%rbp), %rdi

end_if:

  movq %rdi, -8(%rbp)
  
  movq $gObj, %r8
  leaq 4(%r8), %rsi
  call compare_guid

  movq -8(%rbp), %rdi

  cmpl $0, %eax
  jz end_if_2

  movq %rdi, -8(%rbp)

  movq $fmt2, %rdi
  movl $0, %eax
  call printf

  movq -8(%rbp), %rdi

end_if_2:

  movl $0, %r9d
bloco_for_outside:
  cmpl $2, %r9d
  jge end_for_outside

  movl $0, %r10d
bloco_for_inside:
  cmpl $5, %r10d
  jge end_for_inside

  # pins[j]
  leaq -70(%rbp), %r11
  movslq %r10d, %r8
  addq %r8, %r11 # &pins[j]

  leaq -60(%rbp), %rax
  movslq %r9d, %r8
  addq %r8, %rax
  movw 20(%rax), %cx # lObj[i].pin

  cmpw %cx, (%r11)
  jnz end_if_for

  movl $1, -12(%rbp)
  jmp saida

end_if_for:

  incl %r10d
  jmp bloco_for_inside

end_for_inside:

  incl %r9d
  jmp bloco_for_outside

end_for_outside:

saida:

  movl -12(%rbp), %eax

  leave
  ret

