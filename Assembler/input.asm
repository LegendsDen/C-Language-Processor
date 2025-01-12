section .data
    prompt db 'Enter a number: ', 0xa
    prompt_len equ $ - prompt
    newline db 0xa
    ten dd 10

section .bss
    input_buf resb 120   ; Buffer for input string
    number resd 10  ; 32-bit number storage

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
    push edx



convert_loop:
    movzx eax, byte [ecx]  ; Get current character
    cmp al, 0xa            ; Check for newline
    je done_converting
    cmp al,0x20
    je number_finshed
    cmp al, '0'            ; Check if less than '0'
    jl done_converting
    cmp al, '9'            ; Check if greater than '9'
    jg done_converting



    sub al, '0'            ; Convert ASCII to number
    push eax               ; Save current digit

    mov eax, ebx          ; Get current result
    mul dword [ten]       ; Multiply by 10
    mov ebx, eax          ; Store back in result

    pop eax               ; Restore current digit
    add ebx, eax          ; Add to result

    inc ecx               ; Move to next character
    jmp convert_loop

number_finshed:
    pop edx
    mov [number+4*edx],ebx
    inc edx
    push edx
    xor ebx,ebx
    inc ecx
    jmp convert_loop 



done_converting:
    pop edx
    mov [number+4*edx], ebx   ; Store final result

    ; Exit program
    mov eax, 1            ; sys_exit
    mov ebx, 0            ; exit code 0
    int 0x80