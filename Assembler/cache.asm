section .data
    prompt_doc db "Enter: ", 0xa
    Cache_Hit db 0xa,"Cache Hit !", 0xa
    len_cache_hit equ $ - Cache_Hit
    Cache_Miss db 0xa,"Cache Miss !", 0xa
    len_cache_miss equ $ - Cache_Miss
    newline db 0xa
    ten dd 10
    arr dd 50 dup(0)
    cache dd 16 dup(99)




section .bss
    document resb 1000      ; Buffer for document text
    address resb 1000
    value resb 120   ; Buffer for input string
    number resd 2  ; 32-bit number storage
    iterations resb 8 
    index resb 1

section .text
    global _start

_start:
; Print prompt for document
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt_doc
    mov edx, 7
    int 80h

    ; Read document
    mov eax, 3
    mov ebx, 0
    mov ecx, document
    mov edx, 1000
    int 80h

    dec eax         ; Subtract 1 to exclude newline
    mov edi, eax    ; Store length in edi


    mov esi,document
;read_or_write :
    mov al,[esi]
    cmp al, '1'
    je read
    jmp write
    

    

read:
     ; Read input
    mov eax, 3         
    mov ebx, 0         
    mov ecx, address 
    mov edx, 120         
    int 0x80

    xor ebx, ebx
    mov ecx, address
    xor edx, edx  

convrt_loop:
    movzx eax,byte[ecx]
    cmp al,0xa
    je  halwa

    sub al, '0'            ; Convert ASCII to number
    push eax               ; Save current digit

    mov eax, ebx          ; Get current result
    mul dword [ten]       ; Multiply by 10
    mov ebx, eax          ; Store back in result

    pop eax               ; Restore current digit
    add ebx, eax          ; Add to result

    inc ecx               ; Move to next character
    jmp convrt_loop

halwa:
    mov [number],ebx
    and ebx,3
    imul ebx,4
    xor eax,eax
    
    mov eax,cache
    add eax,ebx
    mov ecx,[number]
    cmp [eax],ecx
    je cache_hit
    add eax,8
    cmp [eax],ecx
    je cache_hit
    jmp cache_miss


cache_hit:
    mov eax, 4
    mov ebx, 1
    mov ecx, Cache_Hit
    mov edx, len_cache_hit
    int 0x80
    jmp finished


cache_miss:

    mov eax, 4
    mov ebx, 1
    mov ecx, Cache_Miss
    mov edx, len_cache_miss
    int 0x80
    jmp finished




















    jmp finished






    





    
    










write:

    mov eax, 3         
    mov ebx, 0         
    mov ecx, address 
    mov edx, 120         
    int 0x80

    xor ebx, ebx
    mov ecx, address
    xor edx, edx  
    xor edi,edi

convrt_loop_again:
    movzx eax,byte[ecx]
    cmp al,0xa
    je  gajar
    cmp al, 0x20
    je space

    sub al, '0'            ; Convert ASCII to number
    push eax               ; Save current digit

    mov eax, ebx          ; Get current result
    mul dword [ten]       ; Multiply by 10
    mov ebx, eax          ; Store back in result

    pop eax               ; Restore current digit
    add ebx, eax          ; Add to result

    inc ecx               ; Move to next character
    jmp convrt_loop_again

space:
    mov [number],ebx
    inc ecx
    inc edi
    xor ebx,ebx
    jmp convrt_loop_again
gajar :
    mov [number+4*edi],ebx
    






















    







finished:
    xor ebx, ebx       
    xor eax,eax
    mov ebx, cache 
    xor ecx, ecx     
    xor edx,edx

print_arr:
    inc ecx
    cmp ecx,17
    je exit
    jmp convert_number

convert_number: 
    mov eax ,[ebx]
    mov edi, iterations
    add edi, 7
    
    mov byte [edi], 0xa
    dec edi
    mov esi,10

convert_loop:
    xor edx, edx
    div esi
    add dl, '0'    
    mov [edi], dl
    dec edi
    test eax, eax
    jnz convert_loop

    push ebx
    push ecx

    inc edi       
    mov eax, 4
    mov ebx, 1
    mov ecx, edi
    mov edx, iterations
    add edx, 8
    sub edx, edi
    int 80h

    pop ecx
    pop ebx
    add ebx,4
    jmp print_arr

exit:
    mov eax,1
    xor ebx,ebx
    int 80h



