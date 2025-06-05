.text

.globl compare_guid
compare_guid:
  pushq %rbp
  movq %rsp, %rbp

  movl (%rdi), %eax
  movl (%rsi), %ecx

  cmpl %ecx, %eax
  jz end_if_1

  movl $0, %eax
  leave
  ret

end_if_1:
  movw 4(%rdi), %ax
  movw 4(%rsi), %cx

  cmpw %cx, %ax
  jz end_if_2

  movl $0, %eax
  leave
  ret

end_if_2:
  movw 6(%rdi), %ax
  movw 6(%rsi), %cx

  cmpw %cx, %ax
  jz end_if_3

  movl $0, %eax
  leave
  ret

end_if_3:

  movl $0, %r8d
bloco_for:
  cmpl $8, %r8d
  jge end_for

  #id1->part4[i]
  leaq 8(%rdi), %r9
  movslq %r8d, %rcx
  addq %rcx, %r9
  movb (%r9), %al

  #id2->part4[i]
  leaq 8(%rsi), %r10
  movslq %r8d, %rcx
  addq %rcx, %r10
  movb (%r10), %cl

  cmpb %cl, %al
  jz end_if_do_for

  movl $0, %eax
  leave
  ret

end_if_do_for:

  incl %r8d
  jmp bloco_for

end_for:

  movl $1, %eax

  leave
  ret