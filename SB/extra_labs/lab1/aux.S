.section .rodata

.data

  .globl str
  .align 1
  str: .string "BEBAMUITOCAFE"

.text

.globl process
process:
  pushq %rbp
  movq %rsp, %rbp

  movq $str, %r8

begin_while:
  cmpb $0, (%r8)
  jz end_while

  addb $32, (%r8)
  
  incq %r8

  jmp begin_while
end_while:

  leave 
  ret