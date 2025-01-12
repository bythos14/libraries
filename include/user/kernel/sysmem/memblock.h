/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_KERNEL_SYSMEM_MEMBLOCK_H
#define _VDSUITE_USER_KERNEL_SYSMEM_MEMBLOCK_H

#include_next <kernel/sysmem/memblock.h>

SCE_CDECL_BEGIN

#if !defined(_LANGUAGE_ASSEMBLY)

typedef struct SceKernelAllocMemBlockOptInternal {
	SceSize		size;
	SceUInt32	attr;
	SceSize		alignment;
	SceUID		uidBaseBlock;
	const char	*strBaseBlockName;
	SceUInt32	flags;					//! Unknown flags 0x10 or 0x30 for ::sceKernelOpenMemBlock
	SceUInt32	reserved[10];
} SceKernelAllocMemBlockOptInternal;

#endif	/* !defined(_LANGUAGE_ASSEMBLY) */

SCE_CDECL_END

#endif  /* _VDSUITE_USER_KERNEL_SYSMEM_MEMBLOCK_H */
