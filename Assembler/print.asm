section .data
    newline db 10    ; ASCII code for newline
    number dd 11  ; The number to print
    numbers db 'Number: ', 0      
    number_len equ $ - number

section .bss
    buffer resb 12   ; Buffer to store the ASCII string (max 32-bit int is 10 digits + sign + null)

section .text
global _start

_start:
    mov eax, [number]    ; Load the number into eax
    mov ecx, buffer      ; Point ecx to the buffer 
    add ecx, 11          ; Move to end of buffer
    mov byte [ecx], 0    ; Null terminate the string
    dec ecx              ; Move back one position
    mov byte [ecx], 10   ; Add newline

    ; Check if number is negative
    test eax, eax
    jns convert_digits   ; If not negative, start converting
    neg eax             ; Make positive
    push eax            ; Save eax
    mov al, '-'         ; Load minus sign
    mov [buffer], al    ; Store it at start of buffer
    pop eax             ; Restore number

convert_digits:
    mov ebx, 10         ; Divisor = 10
    dec ecx             ; Move back one position

convert_loop:
    xor edx, edx        ; Clear edx for division
    div ebx             ; Divide eax by 10
    add dl, '0'         ; Convert remainder to ASCII
    mov [ecx], dl       ; Store ASCII digit
    test eax, eax       ; Check if quotient is 0
    jz write_output    ; If zero, we're done
    dec ecx             ; Move back one position
    jmp convert_loop    ; Continue converting


write_output:
    ; Print the prefix "Number: "
    mov eax, 4                   ; sys_write
    mov ebx, 1                   ; stdout
    mov ecx, numbers              ; Address of "Number: "
    mov edx, number_len          ; Length of "Number: "
    int 0x80                     ; Make system call


print_number:
    ; Calculate string length
    mov edx, buffer
    mov ecx, buffer
    add edx, 12         ; Point to end of buffer
    sub edx, ecx        ; Calculate length
    mov eax, 4          ; sys_write
    mov ebx, 1          ; stdout
    int 0x80            ; Make system call

exit:
    mov eax, 1          ; sys_exit
    xor ebx, ebx        ; Return 0
    int 0x80            ; Make system call
    