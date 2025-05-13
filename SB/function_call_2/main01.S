.section .rodata

fmt1: .string "'a' maior do que 'b'\n"
fmt2: .string "Valor de 'b': %d\n"

.data

  .globl a
  .align 1
  a: .byte 110

  .globl b
  .align 1
  b: .byte 110

.text

.globl main

main:

   pushq %rbp

   movq  %rsp, %rbp

   movb a, %dil
   movb b, %sil
   call maximo
   movl %eax, %r10d

   movsbl a, %eax
   cmpl %eax, %r10d
   jne bloco_else

   movq $fmt1, %rdi
   movl $0, %eax
   call printf

   jmp end_else

bloco_else:
   
   movq $fmt2, %rdi
   movsbl b, %esi
   movl $0, %eax
   call printf

end_else:

   movl $0, %eax

   leave

   ret