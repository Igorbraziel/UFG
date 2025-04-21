.data

  # char str[] = "BEBAMUITOCAFE";
  .globl str
  .align 1
  str: .string "BEBAMUITOCAFE"

.text

.globl process

process:

   pushq %rbp

   movq  %rsp, %rbp



   # Inicialização de 'ptr' aqui (Obs: utilize %r8 como sendo 'ptr')
   # ptr = str
   movq $str, %r8



beginwhile:

   cmpb $0, (%r8)

   je endwhile            # while() {



   # Bloco do while

   #*ptr = *ptr + 32;
   movb (%r8), %r9b
   addb $32, %r9b
   movb %r9b, (%r8)

   #ptr++;
   incq %r8

   jmp beginwhile         # }

endwhile:



   leave

   ret