section .data
    prompt db 'Enter a string(eg:abcs56$#@gAFK): ', 0xa
    prompt_len equ $ - prompt
    msg_alphabets db 0xa,"Alphabets: ", 0
    len_msg_alphabets equ $ - msg_alphabets
    msg_digits db 0xa,"Digits: ", 0
    len_msg_digits equ $ - msg_digits
    msg_specials db 0xa,"Special symbols: ", 0
    len_msg_specials equ $ - msg_specials
    newline db 0xa
    ten dd 10

section .bss
    input_buf resb 120   ; Buffer for input string
    number resd 1  ; 32-bit number storage
    alphabets resd 1
    special_characters resd 1

    buffer_result resb 12 


section .text
    global _start

_start:
    ; Print prompt
    mov eax, 4          ; sys_write
    mov ebx, 1          ; stdout
    mov ecx, prompt     ; message
    mov edx, prompt_len ; length
    int 0x80

    ; Read input
    mov eax, 3          ; sys_read
    mov ebx, 0          ; stdin
    mov ecx, input_buf  ; buffer
    mov edx, 120          ; max length
    int 0x80

    ; Convert string to number
    xor ebx, ebx        ; Clear result register
    mov ecx, input_buf  ; Point to start of buffer
    xor edx, edx        ; Clear counter
    xor esi,esi
    xor edi,edi
    ;esi--->apha  edi --->number    edx --->characterspecial
    
convert_loop:
    movzx eax, byte [ecx]  ; Get current character
    cmp al, 0xa            ; Check for newline
    je done_converting
    cmp al, '0'            ; Check if less than '0'
    jl sp_character
    cmp al, '9'            ; Check if greater than '9'
    jg no_number
    inc edi
    inc ecx               ; Move to next character
    jmp convert_loop

no_number:
    cmp al,'Z'
    jg no_upper
    cmp al,'A'
    jl sp_character
    inc esi
    inc ecx
    jmp convert_loop

no_upper:
    cmp al,'a'
    jl sp_character
    cmp al,'z'
    jg sp_character
    inc esi
    inc ecx
    jmp convert_loop
 
sp_character:
    inc edx
    inc ecx
    jmp convert_loop

done_converting:
    mov [number],edi
    mov [alphabets], esi
    mov [special_characters], edx

print_results:
    ; Print Alphabets
    mov eax, 4
    mov ebx, 1
    mov ecx, msg_alphabets
    mov edx, len_msg_alphabets
    int 0x80

    movzx eax, byte [alphabets]
    call print_number

    ; Print Digits
    mov eax, 4
    mov ebx, 1
    mov ecx, msg_digits
    mov edx, len_msg_digits
    int 0x80

    movzx eax, byte [number]
    call print_number

    ; Print Special Symbols
    mov eax, 4
    mov ebx, 1
    mov ecx, msg_specials
    mov edx, len_msg_specials
    int 0x80

    movzx eax, byte [special_characters]
    call print_number

    ; Exit
    mov eax, 1
    xor ebx, ebx
    int 0x80




print_number:
    mov ecx, buffer_result
    mov ebx, 10
    xor edx, edx
    add ecx,11
    mov byte [ecx], 0    
    dec ecx              
    mov byte [ecx], 10 
    dec ecx


convert_loops:
    xor edx, edx        ; Clear edx for division
    div ebx             ; Divide eax by 10
    add dl, '0'         ; Convert remainder to ASCII
    mov [ecx], dl       ; Store ASCII digit
    test eax, eax       ; Check if quotient is 0
    jz final    ; If zero, we're done
    dec ecx             ; Move back one position
    jmp convert_loops    ; Continue converting

final:
    mov edx, buffer_result
    sub edx, ecx
    mov eax, 4
    mov ebx, 1
    mov ecx, ecx
    int 0x80
    ret