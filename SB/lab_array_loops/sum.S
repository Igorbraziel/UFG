.data

  .globl s
  .align 4
  s: .long 0

  .globl nums
  .align 4
  nums: .long 65, -105, 111, 34

.text



.globl sum

sum:

    pushq %rbp

    movq  %rsp, %rbp

    movl $0, %eax

bloco_while:
    cmpl $4, %eax
    jge end_while

    #bloco while
    movq $nums, %rcx
    movslq %eax, %rax
    movq %rax, %rdx
    imulq $4, %rdx
    addq %rcx, %rdx
    movl s, %r8d
    addl (%rdx), %r8d
    movl %r8d, s
    incl %eax

    jmp bloco_while 

end_while:

    leave

    ret