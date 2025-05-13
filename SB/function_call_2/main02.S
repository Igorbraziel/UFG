.section .rodata

fmt: .string "Iteração %d, v = %d\n"

.data

  .globl i
  .align 4
  i: .long 0

  .globl v
  .align 2
  v: .word 0

  .globl vetA
  .align 2
  vetA: .word 28, 42, 16, 23, 47

  .globl vetB
  .align 4
  vetB: .long 0, 0, 0, 0, 0

.text



.globl main

main:

   pushq %rbp

   movq  %rsp, %rbp

bloco_while:
    cmpl $5, i
    jge end_while

    # vetA[i]
    movq $vetA, %r8
    movslq i, %r9
    imulq $2, %r9
    addq %r9, %r8

    # shift left
    shlw $2, (%r8)
    movw (%r8), %r10w
    movw %r10w, v

    movq $fmt, %rdi
    movl i, %esi
    movswl v, %edx
    movl $0, %eax
    call printf

    movl i, %edi
    movw v, %si
    # &vetB[i]
    movq $vetB, %r10
    movslq i, %r11
    imulq $4, %r11
    addq %r11, %r10
    movq %r10, %rdx
    call process

    incl i
    jmp bloco_while

end_while:

    movq $vetB, %rdi
    movq $5, %rsi
    call show

   movl $0, %eax

   leave

   ret