.section .rodata

.data

.text

.globl fat
fat:
  pushq %rbp
  movq %rsp, %rbp

  subq $16, %rsp

  cmpl $0, %edi
  jle return_2

return_1:
  movq %rdi, -8(%rbp)

  subl $1, %edi
  call fat

  movq -8(%rbp), %rdi

  imull %edi, %eax
  
  leave
  ret

return_2:
  movl $1, %eax

  leave
  ret