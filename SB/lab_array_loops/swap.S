.data

  .globl last
  .align 8
  last: .quad 0

  .globl values
  .align 8
  values: .quad 50, -10, 60, -20, 70

.text

.globl swap

swap:

    pushq %rbp

    movq  %rsp, %rbp

    movl $0, %eax
    movl $4, %ecx

for_loop:
    # test
    cmpl %ecx, %eax
    jge end_for
    # test

    # long tmp = values[i];
    movq $values, %rdx
    movslq %eax, %r8
    imulq $8, %r8
    addq %r8, %rdx
    movq (%rdx), %r8

    # values[i] = values[j];
    movq $values, %r9
    movslq %ecx, %r10
    imulq $8, %r10
    addq %r9, %r10
    movq (%r10), %r11
    movq %r11, (%rdx)

    #values[j] = tmp;
    movq %r8, (%r10)

    # upgrade
    incl %eax
    decl %ecx
    # upgrade

    jmp for_loop

end_for:

    movq $values, %rdx
    movq 32(%rdx), %r11
    movq %r11, last

    leave

    ret