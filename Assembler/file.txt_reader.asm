section .data
    filename db 'jjl.txt', 0    ; Null-terminated filename
    error_msg db 'Error opening file', 10, 0
    success_msg db 'File read successfully', 10, 0
    
section .bss
    file_handle resq 1           ; File handle storage
    buffer resb 1024            ; Buffer to store file content
    bytes_read resq 1           ; Number of bytes read

section .text
    global _start

_start:
    ; Open the file
    mov rax, 2                  ; syscall number for open
    mov rdi, filename          ; filename pointer
    mov rsi, 0                  ; O_RDONLY flag
    mov rdx, 0644o             ; File permissions (not used for reading)
    syscall
    
    ; Check if file opened successfully
    cmp rax, 0
    jl error_handler           ; Jump if error (rax < 0)
    
    ; Store file handle
    mov [file_handle], rax
    
    ; Read from file
    mov rax, 0                  ; syscall number for read
    mov rdi, [file_handle]     ; file handle
    mov rsi, buffer           ; buffer to store data
    mov rdx, 1024             ; number of bytes to read
    syscall
    
    ; Store number of bytes read
    mov [bytes_read], rax
    
    ; Print success message
    mov rax, 1                  ; syscall number for write
    mov rdi, 1                  ; file descriptor (stdout)
    mov rsi, success_msg       ; message to write
    mov rdx, 22               ; message length
    syscall
    
    ; Print file contents
    mov rax, 1                  ; syscall number for write
    mov rdi, 1                  ; file descriptor (stdout)
    mov rsi, buffer           ; buffer containing file data
    mov rdx, [bytes_read]      ; number of bytes to write
    syscall
    
    ; Close the file
    mov rax, 3                  ; syscall number for close
    mov rdi, [file_handle]     ; file handle
    syscall
    
    ; Exit program
    mov rax, 60                 ; syscall number for exit
    mov rdi, 0                  ; exit code 0
    syscall
    
error_handler:
    ; Print error message
    mov rax, 1                  ; syscall number for write
    mov rdi, 1                  ; file descriptor (stdout)
    mov rsi, error_msg         ; error message
    mov rdx, 18               ; message length
    syscall
    
    ; Exit with error code
    mov rax, 60                 ; syscall number for exit
    mov rdi, 1                  ; exit code 1
    syscall
