#include "process_manager.h"
#include "shizukuRTOS/fatalError.h"
#include "stdio.h"
#include "stdlib.h"

char __attribute__((section(".shizuku_RTOS_root_system_stack_section")))
rootSystemProcess_Stack[1024];
extern int __shizuku_RTOS_root_system_stack_section_end__;

shizuku_RTOS_process rootSystemProcess = {
    .before = &rootSystemProcess,
    .after = &rootSystemProcess,
    .context = {.lr = shizuku_RTOS_System,
                .sp = &__shizuku_RTOS_root_system_stack_section_end__,
                0}};

shizuku_RTOS_process *currentProcess = &rootSystemProcess;

void shizuku_RTOS_System() {
  while (1) {
    printf("systemCalled");
    shizuku_RTOS_contextSwich();
  }
}
void new_process(void (*entrypoint)(int, char **), int argc, char *argv[]) {
  shizuku_RTOS_process *process;
  int result;
  if ((process = malloc(sizeof(shizuku_RTOS_process)))) {
    if ((result = saveContext(&(process->context), 1)) == 0) {
      // 呼び出し元プロセス向け処理
      process->after = currentProcess->after;
      process->before = currentProcess;
      currentProcess->after->before = process;
      currentProcess->after = process;
      return;
    } else {
      // スタック確保
      currentProcess->stack_space = aligned_alloc(8, 1032);
      if ((currentProcess->stack_space = aligned_alloc(8, 1032)) != 0) {
        shizuku_RTOS_process *self;
        // スタックポインタの設定
        void *sp = (currentProcess->stack_space + 1024);
        asm("mov sp, %0" : : "r"(sp));
        // 新規プロセスの開始処理
        entrypoint(argc, argv);
        // 終了プロセスのアドレスを保存
        self = currentProcess;
        // プロセス終了処理（プロセスリングから現プロセスを削除し、次のプロセスへ移動）
        currentProcess->after->before = currentProcess->before;
        currentProcess->before->after = currentProcess->after;
        currentProcess = currentProcess->after;
        // スタック領域とプロセス領域を開放
        free(self->stack_space);
        free(self);
        // 別プロセスへコンテキストスイッチ
        loadContext(&currentProcess->context);
      } else {
        fatalError("new_Process_Start_failed_(SP_ALLOC_FAIL)");
      }
    }
  } else {
    fatalError("new_Process_failed");
  }
}
void shizuku_RTOS_contextSwich() {
  void *sp;
  asm("mov %0, sp" : "=r"(sp));
  if (sp < currentProcess->stack_space) {
    if (saveContext(&(currentProcess->context), 1) == 0) {
      currentProcess = currentProcess->after;
      loadContext(&(currentProcess->context));
    } else {
      return;
    }
  } else {
    fatalError("stackOverFlowed");
  }
}