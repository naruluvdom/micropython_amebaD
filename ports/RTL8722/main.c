/*****************************************************************************
 *                              Header includes
 * ***************************************************************************/
/*#include "section_config.h"
#include "ameba_soc.h"
#include "FreeRTOS.h"
#include "task.h"
#include "osdep_service.h"
*/
//#include "main.h"

extern int                          _rtl_printf(const char *fmt, ...);
#ifndef printf
//#error
#define printf                      _rtl_printf
#endif

#if 0
#include "py/mpconfig.h"
#include "py/obj.h"
#include "py/runtime.h"
#include "py/compile.h"
#include "py/gc.h"
#include "lib/utils/pyexec.h"
#include "gccollect.h"
#include "exception.h"
#include "section_config.h"
#include "FreeRTOS.h"
#include "task.h"
#include "osdep_service.h"
#include "ameba_soc.h"
#include "main.h"

uint8_t mpHeap[MP_HEAP_SIZE];

void micropython_task(void const *arg) {
    printf("--Test 01--\n");
    mp_stack_ctrl_init();
#if MICROPY_ENABLE_GC
    gc_init(mpHeap, mpHeap + sizeof(mpHeap));
    printf("--Test gc--\n");
#endif
    printf("--Test 02--\n");
    // Init micropython basic system
    mp_init();
    printf("--Test 03--\n");
    mp_obj_list_init(mp_sys_path, 0);
    mp_obj_list_init(mp_sys_argv, 0);
    printf("--Test 04--\n");
    modmachine_init();
    printf("--Test 05--\n");
    //modnetwork_init();
    printf("--Test 06--\n");
    //modwireless_init();
    printf("--Test 07--\n");
    modterm_init();
    printf("--Test 08--\n");
    pyexec_frozen_module("_boot.py");
#if MICROPY_REPL_EVENT_DRIVEN
    pyexec_event_repl_init();
    printf("--Test REPL--\n");
#endif
    for ( ; ; ) {
        if (pyexec_mode_kind == PYEXEC_MODE_RAW_REPL) {
            if (pyexec_raw_repl() != 0)
                mp_printf(&mp_plat_print, "soft reboot\n");
        } else {
            if (pyexec_friendly_repl() != 0) 
                mp_printf(&mp_plat_print, "soft reboot\n");
        }
    }
    rtw_thread_exit();
}

#endif

//default main
int main(void)
{
	printf("--Test main()--\n");
	int count = 0;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;
	printf("--XM--test--at--%d--\n",count);
	count ++;

#if 0
    struct task_struct stUpyTask;
    BaseType_t xReturn = rtw_create_task(&stUpyTask, MICROPY_TASK_NAME,
            MICROPY_TASK_STACK_DEPTH, MICROPY_TASK_PRIORITY, micropython_task, NULL);
    vTaskStartScheduler();
#endif
    for(;;);
   
    return 0;
}

#if 0
#if !MICROPY_VFS
mp_lexer_t *mp_lexer_new_from_file(const char *filename) {
    return NULL;
}

mp_import_stat_t mp_import_stat(const char *path) {
    (void)path;
    return MP_IMPORT_STAT_NO_EXIST;
}

mp_obj_t mp_builtin_open(uint n_args, const mp_obj_t *args, mp_map_t *kwargs) {
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(mp_builtin_open_obj, 1, mp_builtin_open);
#endif

void nlr_jump_fail(void *val) {
    mp_printf(&mp_plat_print, "FATAL: uncaught exception %p\r\n", val);
    while(1);
}
#endif