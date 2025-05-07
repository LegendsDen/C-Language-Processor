;Sushant Kumar


section .data
    mes db "Enter (1-->Read  2-->Write   3-->Exit): "
    len equ $-mes
    Cache_Hit db 0xa,"Cache Hit !", 0xa

    len_cache_hit equ $ - Cache_Hit
    Cache  db "Set 1(top row), Set 4(bottom row) ", 0xa
    len1 equ $-Cache
    Desc db "Each Row has 2 block ,with each block storing address and corresponding value at that memory address ",0xa
    len2 equ $-Desc
    Address db "Address is in form of index of an array arr of size 100, so address can be from (0 to 99)",0xa
    len3 equ $-Address
    Empty db "100 in cache indicates empty block",0xa
    len4 equ $-Empty 
    Read db "Enter address(0-99) to read: "
    len5 equ $-Read
    Write db "Enter address(0-99) and value to write: "
    len6 equ $-Write
    Debug db "debug",0xa
    len7 equ $-Debug
    Cache_Miss db 0xa,"Cache Miss !", 0xa
    len_cache_miss equ $ - Cache_Miss
    newline db " " 0xa
    ten dd 10
    arr dd 100 dup(0)
    cache dd 16 dup(100)




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
    mov eax, 4
    mov ebx, 1
    mov ecx, Cache
    mov edx, len1
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, Desc
    mov edx, len2
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, Address
    mov edx, len3
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, Empty
    mov edx, len4
    int 80h






alpha:
; Print prompt for document
    mov eax, 4
    mov ebx, 1
    mov ecx, mes
    mov edx, len
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
    cmp al,'3'
    je exit
    jmp write
    

    

read:

    mov eax, 4
    mov ebx, 1
    mov ecx, Read
    mov edx, len5
    int 80h

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
    imul ebx,16
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






write:
    mov eax, 4
    mov ebx, 1
    mov ecx, Write
    mov edx, len6
    int 80h

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

    mov ebx,[number]
    and ebx,3
    imul ebx,16
    xor eax,eax

    mov eax,arr
    mov ecx,[number]
    mov edx, ecx
    imul edx,4
    add eax,edx
    mov edx,[number+4]
    mov[eax],edx




    


    mov eax,cache
    add eax,ebx
    cmp [eax],ecx
    je cache_hits

    cmp dword[eax],100
    je cache_add

    add eax,8
    cmp [eax],ecx
    je cache_hits

    cmp dword [eax],100
    je cache_add

    jmp fifo





fifo:
    push ecx

    mov ebx,eax
    mov ecx,[eax]
    mov[ebx-8],ecx
    mov ecx,[eax+4]
    mov[ebx-4],ecx

    pop ecx

    jmp cache_add



cache_add:

    mov [eax],ecx
    mov ecx,[number+4]
    add eax,4
    mov [eax],ecx

    mov eax, 4
    mov ebx, 1
    mov ecx, Cache_Miss
    mov edx, len_cache_miss
    int 0x80
    jmp finished





cache_hits:
    add eax,4
    mov edx,[number+4]
    mov[eax],edx

    mov eax, 4 
    mov ebx, 1
    mov ecx, Cache_Hit
    mov edx, len_cache_hit
    int 0x80
    jmp finished



finished:
    xor ebx, ebx       
    xor eax,eax
    mov ebx, cache 
    xor ecx, ecx     
    xor edx,edx

print_arr:
    inc ecx
    cmp ecx,17
    je final
    jmp convert_number

convert_number: 
    mov eax ,[ebx]
    mov edi, iterations
    add edi, 7
    test ecx,3
    jz is_divisible_by4
    mov byte [edi], 0x20
now:
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

final:
    jmp alpha



exit:

    mov eax,1
    xor ebx,ebx
    int 80h



is_divisible_by4:
    mov byte [edi], 0xa
    jmp now