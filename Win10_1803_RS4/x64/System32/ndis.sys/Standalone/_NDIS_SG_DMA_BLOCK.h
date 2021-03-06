typedef struct _NDIS_OBJECT_HEADER
{
  /* 0x0000 */ unsigned char Type;
  /* 0x0001 */ unsigned char Revision;
  /* 0x0002 */ unsigned short Size;
} NDIS_OBJECT_HEADER, *PNDIS_OBJECT_HEADER; /* size: 0x0004 */

typedef union _LARGE_INTEGER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ long HighPart;
    }; /* size: 0x0008 */
    struct
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ long HighPart;
    } /* size: 0x0008 */ u;
    /* 0x0000 */ __int64 QuadPart;
  }; /* size: 0x0008 */
} LARGE_INTEGER, *PLARGE_INTEGER; /* size: 0x0008 */

typedef struct _NDIS_SG_DMA_BLOCK
{
  /* 0x0000 */ struct _NDIS_OBJECT_HEADER Header;
  /* 0x0008 */ struct _NDIS_MINIPORT_BLOCK* Miniport;
  /* 0x0010 */ void* MiniportAdapterContext;
  /* 0x0018 */ struct _DMA_ADAPTER* DmaAdapterObject;
  /* 0x0020 */ void* ProcessSGListHandler /* function */;
  /* 0x0028 */ void* SharedMemAllocateCompleteHandler /* function */;
  /* 0x0030 */ unsigned long Flags;
  /* 0x0034 */ unsigned long MaximumPhysicalMapping;
  /* 0x0038 */ unsigned long ScatterGatherListSize;
  /* 0x0040 */ void* SGListLookasideList;
  /* 0x0048 */ long DmaAdapterRefCount;
  /* 0x0050 */ struct _KEVENT* DmaResourcesReleasedEvent;
  /* 0x0058 */ void* SharedMemoryPage[2];
  /* 0x0068 */ unsigned long SharedMemoryLeft[2];
  /* 0x0070 */ union _LARGE_INTEGER SharedMemoryAddress[2];
  /* 0x0080 */ struct _DMA_ADAPTER* SavedDmaAdapterObject;
  /* 0x0088 */ struct _MAP_REGISTER_ENTRY* MapRegisters;
  /* 0x0090 */ struct _KEVENT* AllocationEvent;
  /* 0x0098 */ unsigned short CurrentMapRegister;
  /* 0x009a */ unsigned short BaseMapRegistersNeeded;
  /* 0x009c */ unsigned short SGMapRegistersNeeded;
  /* 0x009e */ char __PADDING__[2];
} NDIS_SG_DMA_BLOCK, *PNDIS_SG_DMA_BLOCK; /* size: 0x00a0 */

