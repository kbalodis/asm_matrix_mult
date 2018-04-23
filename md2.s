.text
.global matmul
matmul:
  STMDB SP!, { R4 - R12, LR } 
    
  @ielade mainigo vertibas registros r4 - r10
  mov r4, r0 @h1
  mov r5, r1 @w1
  mov r6, r2 @matrix1
  mov r7, r3 @h2
  ldr r8, [sp, #40] @w2
  ldr r9, [sp, #44] @matrix2
  ldr r10, [sp, #48] @matrix3

  @parbauda, vai matricas1 platums w1 ir vienads ar matricas2 augstumu h2
  cmp r5, r7
  bne abort

  @veic matricu reizinasanu
  mov r0, #0 @salidzinashanai cik rindas no m1 jau izmantotas h1 
  forh1:
    cmp r0, r4 @sheit notiek salidzinashana, cik rinas no m1 jau izmantotas
    bge endforh1
    mov r1, #0 @mainigais m2 izmantoto kolonnu glabashanai w2
    forw2:
      cmp r1, r8 @salidzinam cik izmantotas m2 kolonnas w2
      bge endforw2
      mov r2, #0 @mainīgais papildus w1 un h2
      reizina:
        cmp r2, r5
        bge endreizina
        mul r3, r0, r7
        mov r3, r3, LSL #2
        mov r11, r2, LSL #2
        add r3, r3, r11 @offset matrix1
        ldr r12, [r6, r3]
        mov r3, r1, LSL #2
        mul r11, r2, r8
        mov r11, r11, LSL #2
        add r11, r11, r3 @offset matrix2
        ldr r11, [r9, r11]
        mul r3, r12, r11 @m1 un m2 attiecigo elementu reizinajums
        mov r11, r1, LSL #2
        mul r12, r8, r0
        mov r12, r12, LSL #2
        add r11, r11, r12 @offset matrix3
        ldr r12, [r10, r11] @ielade vajadzigo elementu no m3
        add r12, r12, r3 @pieskaita shim elementam tekosho reizinajumu
        str r12, [r10, r11] @ieraksta atpakalj attiecigjaa elementaa
        add r2, r2, #1 @incremente 
        b reizina
      endreizina:
      mov r2, #0
      add r1, r1, #1
      b forw2
    endforw2:
    mov r2, #0
    add r0, r0, #1
    b forh1
  endforh1:        
  b end

  abort:
    mov r0, #1
    LDMIA SP!, { R4 - R12, PC }

  end:
    mov r0, #0
    LDMIA SP!, { R4 - R12, PC }
         