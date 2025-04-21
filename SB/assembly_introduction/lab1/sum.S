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

   movq  %rsp, %rbp



   # Inicializações de 'i' e 'ptr' aqui

   # Obs: utilize %ecx para 'i' e %r8 para 'ptr'

   # int i = 0;
   movl $0, %ecx

   # long *ptr = vet;
   movq $vet, %r8



beginwhile:

   cmpl $5, %ecx

   jge  endwhile      # while() {



   # Bloco do while aqui...
   # sum = sum + *ptr;
   movq (%r8), %r9
   addq %r9, sum

   # ptr++;
   addq $8, %r8   # Cada 'long' ocupa 8 bytes (aritmética de ponteiro) 

   # i++;
   incl %ecx


   jmp beginwhile     # }

endwhile:



   movq $fmt, %rdi    # printf()

   movq sum, %rsi

   movl $0, %eax

   call printf



   movl $0, %eax      # return 0

   leave

   ret