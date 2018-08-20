#ifndef _PSP2_KERNEL_MODULEMGR_H_
#define _PSP2_KERNEL_MODULEMGR_H_

#include <psp2kern/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief      Return values for plugins `module_start` and `module_stop`
 */
/** @{ */
#define SCE_KERNEL_START_SUCCESS      (0)
#define SCE_KERNEL_START_RESIDENT     SCE_KERNEL_START_SUCCESS
#define SCE_KERNEL_START_NO_RESIDENT  (1)
#define SCE_KERNEL_START_FAILED       (2)

#define SCE_KERNEL_STOP_SUCCESS       (0)
#define SCE_KERNEL_STOP_FAIL          (1)
#define SCE_KERNEL_STOP_CANCEL        SCE_KERNEL_STOP_FAIL
/** @} */

typedef struct
{
  SceUInt size;   //!< this structure size (0x18)
  SceUInt perms;  //!< probably rwx in low bits
  void *vaddr;    //!< address in memory
  SceUInt memsz;  //!< size in memory
  SceUInt flags;  //!< meaning unknown
  SceUInt res;    //!< unused?
} SceKernelSegmentInfo;

typedef struct
{
  SceUInt size;   //!< 0x1B8 for Vita 1.x
  SceUInt handle; //!< kernel module handle?
  SceUInt flags;  //!< some bits. could be priority or whatnot
  char module_name[28];
  SceUInt unk28;
  void *module_start;
  SceUInt unk30;
  void *module_stop;
  void *exidxTop;
  void *exidxBtm;
  SceUInt unk40;
  SceUInt unk44;
  void *tlsInit;
  SceSize tlsInitSize;
  SceSize tlsAreaSize;
  char path[256];
  SceKernelSegmentInfo segments[4];
  SceUInt type;   //!< 6 = user-mode PRX?
} SceKernelModuleInfo;

typedef struct {
  SceSize size;
} SceKernelLMOption;

typedef struct {
  SceSize size;
} SceKernelULMOption;

typedef struct
{
  SceSize size;
  char versionString[16];
  SceUInt unk_14;
  SceUInt unk_18;
  SceUInt unk_1C;
  SceUInt version;
  SceUInt unk_24;
} SceKernelFwInfo;

int sceKernelGetModuleList(SceUID pid, int flags1, int flags2, SceUID *modids, size_t *num);
int sceKernelGetModuleInfo(SceUID pid, SceUID modid, SceKernelModuleInfo *info);
int sceKernelGetModuleInternal(SceUID modid, void **module);

int sceKernelGetSystemSwVersion(SceKernelFwInfo *data);

int sceKernelLoadStartModule(const char *path, SceSize args, void *argp, int flags, SceKernelLMOption *option, int *status);
SceUID sceKernelLoadModule(const char *path, int flags, SceKernelLMOption *option);
int sceKernelStartModule(SceUID modid, SceSize args, void *argp, int flags, SceKernelLMOption *option, int *status);
int sceKernelUnloadModule(SceUID modid, int flags, SceKernelULMOption *option);
int sceKernelStopModule(SceUID modid, SceSize args, void *argp, int flags, SceKernelULMOption *option, int *status);
int sceKernelStopUnloadModule(SceUID modid, SceSize args, void *argp, int flags, SceKernelULMOption *option, int *status);

SceUID sceKernelLoadStartSharedModuleForPid(SceUID pid, const char *path, SceSize args, void *argp, int flags, SceKernelLMOption *option, int *status);
SceUID sceKernelLoadStartModuleForPid(SceUID pid, const char *path, SceSize args, void *argp, int flags, SceKernelLMOption *option, int *status);
int sceKernelStartModuleForPid(SceUID pid, SceUID modid, SceSize args, void *argp, int flags, SceKernelLMOption *option, int *status);
SceUID sceKernelLoadModuleForPid(SceUID pid, const char *path, int flags, SceKernelLMOption *option);
SceUID sceKernelUnloadModuleForPid(SceUID pid, SceUID modid, int flags, SceKernelULMOption *option);
int sceKernelStopModuleForPid(SceUID pid, SceUID modid, SceSize args, void *argp, int flags, SceKernelULMOption *option, int *status);
int sceKernelStopUnloadModuleForPid(SceUID pid, SceUID modid, SceSize args, void *argp, int flags, SceKernelULMOption *option, int *status);

int sceKernelMountBootfs(const char *bootImagePath);
int sceKernelUmountBootfs(void);

int sceKernelSearchModuleByName(const char* module_name, const char* path, int pid);

#ifdef __cplusplus
}
#endif

#endif /* _PSP2_KERNEL_MODULEMGR_H_ */

