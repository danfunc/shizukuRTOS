MEMORY
{
    SRAM(rw) : ORIGIN =  0x20000000, LENGTH = 256k
}

SECTIONS{
    .shizuku_RTOS_root_system_stack_section　:　{
        . = ALIGN(8);
        __shizuku_RTOS_root_system_stack_section_start__ = .;
        *(.shizuku_RTOS_root_system_stack_section)
        . = ALIGN(8);
        __shizuku_RTOS_root_system_stack_section_end__ = .;
        . += 8;
        . = ALIGN(8);
    } > SRAM
}