.section .rodata

fmt: .string "%d\n"

.text


.globl show
show:
    pushq %rbp
    movq %rsp, %rbp

    # Alocando 32 bytes no RA
    subq $32, %rsp

    # salvando no RA (callee-saved)
    movq %rbx, -8(%rbp)

    movl $0, %ebx
bloco_for:
    cmpl %esi, %ebx
    jge end_for

    # Salvando no RA (caller-saved)
    movq %rdi, -16(%rbp)
    movq %rsi, -24(%rbp)
    
    # v[i]
    movslq %ebx, %r13
    imulq $4, %r13
    addq %r13, %rdi

    movl (%rdi), %esi
    movq $fmt, %rdi
    movl $0, %eax

    call printf

    # Recuperando do RA (caller-saved)
    movq -16(%rbp), %rdi
    movq -24(%rbp), %rsi

    incl %ebx
    jmp bloco_for

end_for:

    # recuperando do RA
    movq -8(%rbp), %rbx

    leave 
    ret