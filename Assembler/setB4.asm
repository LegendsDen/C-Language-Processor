section .data
    prompt db "Enter a string: ", 0      ; Prompt for input
    prompt_len equ $ - prompt            ; Length of the prompt
    input_buffer db 255                  ; Buffer for user input
    newline db 10                        ; Newline character

section .bss
    input resb 256                       ; Reserve space for input string

section .text
    global _start

_start:
    ; Print prompt
    mov eax, 4                          ; sys_write
    mov ebx, 1                          ; file descriptor (stdout)
    mov ecx, prompt                     ; pointer to prompt
    mov edx, prompt_len                 ; prompt length
    int 0x80                             ; make system call

    ; Read input string
    mov eax, 3                          ; sys_read
    mov ebx, 0                          ; file descriptor (stdin)
    mov ecx, input_buffer               ; buffer to store input
    mov edx, 256                        ; max number of bytes to read
    int 0x80                             ; make system call

    ; Process the string
    mov esi, input_buffer               ; point to the input string
process_char:
    mov al, byte [esi]                  ; load the current character
    cmp al, 10                           ; check if it's a newline
    je print_result                     ; if newline, end the loop

    ; Check if character is an alphabet
    cmp al, 'a'                          ; check if it's 'a'
    jl not_alpha
    cmp al, 'z'                          ; check if it's 'z'
    jg not_alpha
    inc al                               ; increment lowercase letter
    cmp al, 'a' + 26                     ; check if it exceeds 'z'
    jl not_alpha
    mov al,'A'
    mov byte [esi], al                   
    inc esi                              
    jmp process_char

not_alpha:
    cmp al, 'A'                          ; check if it's 'A'
    jl not_alpha_upper
    cmp al, 'Z'                          ; check if it's 'Z'
    jg not_alpha_upper
    inc al                               ; increment uppercase letter
    cmp al, 'A' + 26                     ; check if it exceeds 'Z'
    jl not_alpha_upper
    mov al,'a'
    mov byte [esi], al                  
    inc esi                           
    jmp process_char

not_alpha_upper:
    mov byte [esi], al                   ; store the updated character
    inc esi                               ; move to next character
    jmp process_char

print_result:
    ; Print the updated string
    mov eax, 4                          ; sys_write
    mov ebx, 1                          ; file descriptor (stdout)
    mov ecx, input_buffer               ; pointer to input buffer (updated string)
    mov edx, 256                        ; length of the string (max 256)
    int 0x80                             ; make system call

    ; Print newline
    mov eax, 4                          ; sys_write
    mov ebx, 1                          ; file descriptor (stdout)
    mov ecx, newline                    ; newline character
    mov edx, 1                          ; length of newline
    int 0x80                             ; make system call

    ; Exit
    mov eax, 1                          ; sys_exit
    xor ebx, ebx                        ; status 0
    int 0x80                             ; make system call
