section .bss
    year_start resb 5      ; Starting year buffer
    year_end resb 5        ; Ending year buffer
    year_str resb 5        ; Year string buffer

section .data
    prompt1 db "Enter start year: ", 0
    len1 equ $ - prompt1
    prompt2 db "Enter end year: ", 0
    len2 equ $ - prompt2
    newline db 10

section .text
    global _start

_start:
    ; Print first prompt
    mov eax, 4          ; sys_write
    mov ebx, 1          ; stdout
    mov ecx, prompt1    
    mov edx, len1
    int 80h

    ; Read start year
    mov eax, 3          ; sys_read
    mov ebx, 0          ; stdin
    mov ecx, year_start
    mov edx, 5          ; 4 digits + newline
    int 80h

    ; Convert start year to number
    mov ecx, year_start
    call str_to_int
    mov esi, eax        ; Store start year in esi

    ; Print second prompt
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt2
    mov edx, len2
    int 80h

    ; Read end year
    mov eax, 3
    mov ebx, 0
    mov ecx, year_end
    mov edx, 5
    int 80h

    ; Convert end year to number
    mov ecx, year_end
    call str_to_int
    mov edi, eax        ; Store end year in edi

year_loop:
    cmp esi, edi        ; Compare current year with end year
    jg exit_program     ; If current > end, exit

    ; Check if current year is leap year
    mov eax, esi
    call is_leap_year
    test eax, eax
    jnz skip_year       ; If leap year, skip printing

    ; Convert current year to string and print
    mov eax, esi
    call int_to_str
    
    ; Print year
    mov eax, 4
    mov ebx, 1
    mov ecx, year_str
    mov edx, 4
    int 80h

    ; Print newline
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 80h

skip_year:
    inc esi             ; Increment current year
    jmp year_loop

exit_program:
    mov eax, 1          ; sys_exit
    xor ebx, ebx        ; return 0
    int 80h

; Function to convert string to integer
; Input: string pointer in ecx
; Output: integer in eax
str_to_int:
    push ebx            ; Save registers
    push edx
    xor eax, eax        ; Clear result
    mov ebx, 10         ; Base 10

.convert_loop:
    movzx edx, byte [ecx]  ; Get current character
    cmp dl, 10             ; Check for newline
    je .done
    cmp dl, 0              ; Check for null
    je .done
    sub dl, '0'            ; Convert ASCII to number
    imul eax, 10          ; Multiply current result by 10
    add eax, edx          ; Add current digit
    inc ecx               ; Next character
    jmp .convert_loop

.done:
    pop edx              ; Restore registers
    pop ebx
    ret

; Function to convert integer to string
; Input: integer in eax
; Output: string in year_str
int_to_str:
    push ebx            ; Save registers
    push edx
    push edi
    
    mov edi, year_str
    add edi, 4           ; Start from end of buffer
    mov byte [edi], 0    ; Null terminate
    mov ebx, 10          ; Divisor

.convert_loop:
    dec edi              ; Move pointer back
    xor edx, edx         ; Clear for division
    div ebx              ; Divide by 10
    add dl, '0'          ; Convert to ASCII
    mov [edi], dl        ; Store digit
    test eax, eax        ; Check if done
    jnz .convert_loop   

    ; Pad with zeros if needed
    mov ecx, year_str
    add ecx, 4           ; End of buffer
    sub ecx, edi         ; Get length
    cmp ecx, 4           ; Need padding?
    jge .done           ; No padding needed

.pad_zeros:
    dec edi
    mov byte [edi], '0'  ; Add zero
    inc ecx
    cmp ecx, 4
    jl .pad_zeros

.done:
    ; Copy result to start of buffer if needed
    cmp edi, year_str
    je .exit
    mov ecx, year_str    ; Destination
    mov edx, 4           ; Length to copy
    push edi            ; Save source pointer
    push ecx            ; Save destination pointer
    push edx            ; Save length
    
    rep movsb           ; Copy string

.exit:
    pop edi             ; Restore registers
    pop edx
    pop ebx
    ret

; Function to check if year is leap year
; Input: year in eax
; Output: 1 in eax if leap year, 0 if not
is_leap_year:
    push ebx            ; Save registers
    push ecx
    push edx
    
    mov ebx, eax        ; Save original year
    
    ; Check if divisible by 4
    mov ecx, 4
    xor edx, edx
    div ecx
    test edx, edx
    jnz .not_leap
    
    ; Check if divisible by 100
    mov eax, ebx
    mov ecx, 100
    xor edx, edx
    div ecx
    test edx, edx
    jnz .is_leap
    
    ; Check if divisible by 400
    mov eax, ebx
    mov ecx, 400
    xor edx, edx
    div ecx
    test edx, edx
    jnz .not_leap

.is_leap:
    mov eax, 1
    jmp .done

.not_leap:
    xor eax, eax

.done:
    pop edx             ; Restore registers
    pop ecx
    pop ebx
    ret