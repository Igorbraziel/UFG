.section .rodata

hello: .string "Hello"

.data

  .globl val
  .align 4
  val: .long 432

  .globl age
  .align 2
  age: .word 4

  .globl rbp
  .align 4
  r: .long 0

  .globl err
  .align 8
  err: .quad 2048

.text



.globl main

main:

   pushq %rbp

   movq  %rsp, %rbp

   movq $hello, %rdi
   movl val, %esi
   movw age, %dx
   movq $r, %rcx
   call sum

   movl %eax, val

   movq err, %rdi
   movl val, %esi
   movl r, %edx
   call show

   leave

   movl $0, %eax
   ret