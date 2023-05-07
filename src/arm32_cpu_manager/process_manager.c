#include "process_manager.h"
#include "shizukuRTOS/fatalError.h"
#include "stdlib.h"
#include "stdnoreturn.h"

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

void noreturn shizuku_RTOS_System() {
  while (1) {
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
      // 新規プロセスの開始処理

      entrypoint(argc, argv);
      // プロセス終了処理（プロセスリングから現プロセスを削除）
      currentProcess->after->before = currentProcess->before;
      currentProcess->before->after = currentProcess->after;
      // 別プロセスへコンテキストスイッチ
      currentProcess = currentProcess->after;
      loadContext(&currentProcess->context);
    }
  } else {
    fatalError("new_Process_failed");
  }
}
void shizuku_RTOS_contextSwich() {
  if (saveContext(&(currentProcess->context), 1) == 0) {
    currentProcess = currentProcess->after;
    loadContext(&(currentProcess->context));
  } else {
    return;
  }
}
