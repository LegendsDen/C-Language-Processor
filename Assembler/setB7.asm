section .data
    prompt_size db "Enter matrix size (2 or 3): ", 0
    prompt_2x2 db "Enter elements for 2x2 matrix (4 numbers):", 10, 0
    prompt_3x3 db "Enter elements for 3x3 matrix (9 numbers):", 10, 0
    format_in db "%lf", 0
    format_int db "%d", 0
    format_out db "%lf ", 0
    newline db 10, 0
    det_zero_msg db "Matrix is not invertible (determinant = 0)", 10, 0
    invalid_size db "Invalid size. Please enter 2 or 3.", 10, 0
section .note.GNU-stack noalloc noexec nowrite progbits
section .bss
    matrix_size resd 1  ; Store matrix size (n)
    matrix2x2 resq 4    ; 2x2 matrix (8 bytes * 4 elements)
    inverse2x2 resq 4   ; inverse of 2x2 matrix
    matrix3x3 resq 9    ; 3x3 matrix (8 bytes * 9 elements)
    inverse3x3 resq 9   ; inverse of 3x3 matrix
    determinant resq 1  ; store determinant

section .text
    global main
    extern printf
    extern scanf

main:
    push rbp
    mov rbp, rsp

    ; Get matrix size
.get_size:
    mov rdi, prompt_size
    xor eax, eax
    call printf

    mov rdi, format_int
    mov rsi, matrix_size
    xor eax, eax
    call scanf

    ; Validate size (must be 2 or 3)
    mov eax, [matrix_size]
    cmp eax, 2
    je .size_2
    cmp eax, 3
    je .size_3

    ; Invalid size
    mov rdi, invalid_size
    xor eax, eax
    call printf
    jmp .get_size

.size_2:
    call get_2x2_matrix
    call calculate_2x2_inverse
    call print_2x2_result
    jmp .end

.size_3:
    call get_3x3_matrix
    call calculate_3x3_inverse
    call print_3x3_result

.end:
    mov rsp, rbp
    pop rbp
    xor eax, eax
    ret

get_2x2_matrix:
    push rbp
    mov rbp, rsp

    ; Print prompt
    mov rdi, prompt_2x2
    xor eax, eax
    call printf

    ; Get matrix elements
    xor r12, r12        ; Counter
.input_loop:
    mov rdi, format_in
    lea rsi, [matrix2x2 + r12*8]
    xor eax, eax
    call scanf
    inc r12
    cmp r12, 4
    jl .input_loop

    mov rsp, rbp
    pop rbp
    ret

calculate_2x2_inverse:
    push rbp
    mov rbp, rsp

    ; Calculate determinant (ad - bc)
    movsd xmm0, [matrix2x2]      ; a
    mulsd xmm0, [matrix2x2 + 24] ; a*d
    movsd xmm1, [matrix2x2 + 8]  ; b
    mulsd xmm1, [matrix2x2 + 16] ; b*c
    subsd xmm0, xmm1             ; det = ad - bc
    
    ; Check if determinant is zero
    xorpd xmm1, xmm1
    ucomisd xmm0, xmm1
    je .det_zero

    ; Store determinant
    movsd [determinant], xmm0

    ; Calculate inverse elements
    ; [d  -b]
    ; [-c  a] / det
    movsd xmm1, [matrix2x2 + 24] ; d
    divsd xmm1, xmm0
    movsd [inverse2x2], xmm1

    movsd xmm1, [matrix2x2 + 8]  ; b
    xorpd xmm2, xmm2
    subsd xmm2, xmm1
    divsd xmm2, xmm0
    movsd [inverse2x2 + 8], xmm2

    movsd xmm1, [matrix2x2 + 16] ; c
    xorpd xmm2, xmm2
    subsd xmm2, xmm1
    divsd xmm2, xmm0
    movsd [inverse2x2 + 16], xmm2

    movsd xmm1, [matrix2x2]      ; a
    divsd xmm1, xmm0
    movsd [inverse2x2 + 24], xmm1

    jmp .end

.det_zero:
    mov rdi, det_zero_msg
    xor eax, eax
    call printf

.end:
    mov rsp, rbp
    pop rbp
    ret

print_2x2_result:
    push rbp
    mov rbp, rsp

    ; Check if determinant is zero
    movsd xmm0, [determinant]
    xorpd xmm1, xmm1
    ucomisd xmm0, xmm1
    je .end

    ; Print inverse matrix
    xor r12, r12        ; Row counter
.row_loop:
    xor r13, r13        ; Column counter
.col_loop:
    mov rdi, format_out
    mov rax, r12
    imul rax, 2
    add rax, r13
    movsd xmm0, [inverse2x2 + rax*8]
    mov eax, 1
    call printf

    inc r13
    cmp r13, 2
    jl .col_loop

    mov rdi, newline
    xor eax, eax
    call printf

    inc r12
    cmp r12, 2
    jl .row_loop

.end:
    mov rsp, rbp
    pop rbp
    ret

get_3x3_matrix:
    push rbp
    mov rbp, rsp

    ; Print prompt
    mov rdi, prompt_3x3
    xor eax, eax
    call printf

    ; Get matrix elements
    xor r12, r12        ; Counter
.input_loop:
    mov rdi, format_in
    lea rsi, [matrix3x3 + r12*8]
    xor eax, eax
    call scanf
    inc r12
    cmp r12, 9
    jl .input_loop

    mov rsp, rbp
    pop rbp
    ret

calculate_3x3_inverse:
    push rbp
    mov rbp, rsp

    ; Calculate determinant
    call calculate_3x3_determinant
    
    ; Check if determinant is zero
    xorpd xmm1, xmm1
    ucomisd xmm0, xmm1
    je .det_zero

    ; Store determinant
    movsd [determinant], xmm0

    ; Calculate cofactor matrix
    call calculate_3x3_cofactors

    ; Divide by determinant
    mov rcx, 9
    xor r12, r12
.divide_loop:
    movsd xmm0, [inverse3x3 + r12*8]
    divsd xmm0, [determinant]
    movsd [inverse3x3 + r12*8], xmm0
    inc r12
    loop .divide_loop

    jmp .end

.det_zero:
    mov rdi, det_zero_msg
    xor eax, eax
    call printf

.end:
    mov rsp, rbp
    pop rbp
    ret

calculate_3x3_determinant:
    ; Using the formula: a(ei-fh) - b(di-fg) + c(dh-eg)
    movsd xmm0, [matrix3x3]      ; a
    movsd xmm1, [matrix3x3 + 32] ; e
    mulsd xmm1, [matrix3x3 + 64] ; ei
    movsd xmm2, [matrix3x3 + 40] ; f
    mulsd xmm2, [matrix3x3 + 56] ; fh
    subsd xmm1, xmm2             ; (ei-fh)
    mulsd xmm0, xmm1             ; a(ei-fh)

    movsd xmm1, [matrix3x3 + 8]  ; b
    movsd xmm2, [matrix3x3 + 24] ; d
    mulsd xmm2, [matrix3x3 + 64] ; di
    movsd xmm3, [matrix3x3 + 40] ; f
    mulsd xmm3, [matrix3x3 + 48] ; fg
    subsd xmm2, xmm3             ; (di-fg)
    mulsd xmm1, xmm2             ; b(di-fg)
    subsd xmm0, xmm1             ; a(ei-fh) - b(di-fg)

    movsd xmm1, [matrix3x3 + 16] ; c
    movsd xmm2, [matrix3x3 + 24] ; d
    mulsd xmm2, [matrix3x3 + 56] ; dh
    movsd xmm3, [matrix3x3 + 32] ; e
    mulsd xmm3, [matrix3x3 + 48] ; eg
    subsd xmm2, xmm3             ; (dh-eg)
    mulsd xmm1, xmm2             ; c(dh-eg)
    addsd xmm0, xmm1             ; final determinant

    ret

calculate_3x3_cofactors:
    push rbp
    mov rbp, rsp
    
    ; Calculate cofactor (0,0): (ei-fh)
    movsd xmm0, [matrix3x3 + 32] ; e
    mulsd xmm0, [matrix3x3 + 64] ; ei
    movsd xmm1, [matrix3x3 + 40] ; f
    mulsd xmm1, [matrix3x3 + 56] ; fh
    subsd xmm0, xmm1             ; ei-fh
    movsd [inverse3x3], xmm0

    ; Calculate cofactor (0,1): -(di-fg)
    movsd xmm0, [matrix3x3 + 24] ; d
    mulsd xmm0, [matrix3x3 + 64] ; di
    movsd xmm1, [matrix3x3 + 40] ; f
    mulsd xmm1, [matrix3x3 + 48] ; fg
    subsd xmm0, xmm1             ; di-fg
    xorpd xmm2, xmm2
    subsd xmm2, xmm0             ; -(di-fg)
    movsd [inverse3x3 + 8], xmm2

    ; Calculate cofactor (0,2): (dh-eg)
    movsd xmm0, [matrix3x3 + 24] ; d
    mulsd xmm0, [matrix3x3 + 56] ; dh
    movsd xmm1, [matrix3x3 + 32] ; e
    mulsd xmm1, [matrix3x3 + 48] ; eg
    subsd xmm0, xmm1             ; dh-eg
    movsd [inverse3x3 + 16], xmm0

    ; Calculate cofactor (1,0): -(bi-ch)
    movsd xmm0, [matrix3x3 + 8]  ; b
    mulsd xmm0, [matrix3x3 + 64] ; bi
    movsd xmm1, [matrix3x3 + 16] ; c
    mulsd xmm1, [matrix3x3 + 56] ; ch
    subsd xmm0, xmm1             ; bi-ch
    xorpd xmm2, xmm2
    subsd xmm2, xmm0             ; -(bi-ch)
    movsd [inverse3x3 + 24], xmm2

    ; Calculate cofactor (1,1): (ai-cg)
    movsd xmm0, [matrix3x3]      ; a
    mulsd xmm0, [matrix3x3 + 64] ; ai
    movsd xmm1, [matrix3x3 + 16] ; c
    mulsd xmm1, [matrix3x3 + 48] ; cg
    subsd xmm0, xmm1             ; ai-cg
    movsd [inverse3x3 + 32], xmm0

    ; Calculate cofactor (1,2): -(ah-bg)
    movsd xmm0, [matrix3x3]      ; a
    mulsd xmm0, [matrix3x3 + 56] ; ah
    movsd xmm1, [matrix3x3 + 8]  ; b
    mulsd xmm1, [matrix3x3 + 48] ; bg
    subsd xmm0, xmm1             ; ah-bg
    xorpd xmm2, xmm2
    subsd xmm2, xmm0             ; -(ah-bg)
    movsd [inverse3x3 + 40], xmm2

    ; Calculate cofactor (2,0): (bf-ce)
    movsd xmm0, [matrix3x3 + 8]  ; b
    mulsd xmm0, [matrix3x3 + 40] ; bf
    movsd xmm1, [matrix3x3 + 16] ; c
    mulsd xmm1, [matrix3x3 + 32] ; ce
    subsd xmm0, xmm1             ; bf-ce
    movsd [inverse3x3 + 48], xmm0

    ; Calculate cofactor (2,1): -(af-cd)
    movsd xmm0, [matrix3x3]      ; a
    mulsd xmm0, [matrix3x3 + 40] ; af
    movsd xmm1, [matrix3x3 + 16] ; c
    mulsd xmm1, [matrix3x3 + 24] ; cd
    subsd xmm0, xmm1             ; af-cd
    xorpd xmm2, xmm2
    subsd xmm2, xmm0             ; -(af-cd)
    movsd [inverse3x3 + 56], xmm2

    ; Calculate cofactor (2,2): (ae-bd)
    movsd xmm0, [matrix3x3]      ; a
    mulsd xmm0, [matrix3x3 + 32] ; ae
    movsd xmm1, [matrix3x3 + 8]  ; b
    mulsd xmm1, [matrix3x3 + 24] ; bd
    subsd xmm0, xmm1             ; ae-bd
    movsd [inverse3x3 + 64], xmm0

    mov rsp, rbp
    pop rbp
    ret


print_3x3_result:
    push rbp
    mov rbp, rsp

    ; Check if determinant is zero
    movsd xmm0, [determinant]
    xorpd xmm1, xmm1
    ucomisd xmm0, xmm1
    je .end

    ; Print inverse matrix
    xor r12, r12        ; Row counter
.row_loop:
    xor r13, r13        ; Column counter
.col_loop:
    mov rdi, format_out
    mov rax, r12
    imul rax, 3
    add rax, r13
    movsd xmm0, [inverse3x3 + rax*8]
    mov eax, 1
    call printf

    inc r13
    cmp r13, 3
    jl .col_loop

    mov rdi, newline
    xor eax, eax
    call printf

    inc r12
    cmp r12, 3
    jl .row_loop

.end:
    mov rsp, rbp
    pop rbp
    ret