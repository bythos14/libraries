/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_COMMON_KERNEL_PROCESS_PARAM_H
#define _VDSUITE_COMMON_KERNEL_PROCESS_PARAM_H

#include_next <kernel/process_param.h>

SCE_CDECL_BEGIN

#define SCE_PROCESS_PRELOAD_DISABLED_LIBC				0x00010000
#define SCE_PROCESS_PRELOAD_DISABLED_LIBDBG				0x00020000
#define SCE_PROCESS_PRELOAD_DISABLED_LIBSHELLSVC		0x00080000
#define SCE_PROCESS_PRELOAD_DISABLED_LIBCDLG			0x00100000
#define SCE_PROCESS_PRELOAD_DISABLED_LIBFIOS2			0x00200000
#define SCE_PROCESS_PRELOAD_DISABLED_APPUTIL			0x00400000
#define SCE_PROCESS_PRELOAD_DISABLED_LIBSCEFT2			0x00800000
#define SCE_PROCESS_PRELOAD_DISABLED_LIBPVF				0x01000000
#define SCE_PROCESS_PRELOAD_DISABLED_LIBPERF			0x02000000

/* extern unsigned int	sce_process_preload_disabled; */

SCE_CDECL_END

#endif	/* _VDSUITE_COMMON_KERNEL_PROCESS_PARAM_H */