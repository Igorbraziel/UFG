.section .rodata

.data

  .globl i
  .align 4
  i: .long 0

  .globl bias
  .align 8
  bias: .quad 256

  .globl vet
  .align 1
  vet: .byte 12, 3, 20, 8

.text

.globl main

main:

   pushq %rbp

   movq  %rsp, %rbp

   movl $0, i
for_block:
   cmpl $4, i
   jge end_for

   movq $vet, %rcx
   movslq i, %r8
   imulq $1, %r8
   addq %r8, %rcx #rcx contem o valor

   movb (%rcx), %dil
   movw $10, %si
   movq bias, %rdx
   call filtro
   movq %rax, bias

   incl i
   jmp for_block

end_for:
   movl $0, %eax 

   leave
   ret