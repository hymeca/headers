typedef struct _flags
{
  struct /* bitfield */
  {
    /* 0x0000 */ unsigned char Removable : 1; /* bit position: 0 */
    /* 0x0000 */ unsigned char GroupAssigned : 1; /* bit position: 1 */
    /* 0x0000 */ unsigned char GroupCommitted : 1; /* bit position: 2 */
    /* 0x0000 */ unsigned char GroupAssignmentFixed : 1; /* bit position: 3 */
    /* 0x0000 */ unsigned char Fill : 4; /* bit position: 4 */
  }; /* bitfield */
} flags, *Pflags; /* size: 0x0001 */

typedef struct _GROUP_AFFINITY
{
  /* 0x0000 */ unsigned long Mask;
  /* 0x0004 */ unsigned short Group;
  /* 0x0006 */ unsigned short Reserved[3];
} GROUP_AFFINITY, *PGROUP_AFFINITY; /* size: 0x000c */

typedef struct _KNODE
{
  /* 0x0000 */ unsigned long DeepIdleSet;
  /* 0x0040 */ unsigned long ProximityId;
  /* 0x0044 */ unsigned short NodeNumber;
  /* 0x0046 */ unsigned short PrimaryNodeNumber;
  /* 0x0048 */ unsigned char MaximumProcessors;
  /* 0x0049 */ struct _flags Flags;
  /* 0x004a */ unsigned char Stride;
  /* 0x004b */ unsigned char NodePad0;
  /* 0x004c */ struct _GROUP_AFFINITY Affinity;
  /* 0x0058 */ unsigned long IdleCpuSet;
  /* 0x005c */ unsigned long IdleSmtSet;
  /* 0x0080 */ unsigned long Seed;
  /* 0x0084 */ unsigned long Lowest;
  /* 0x0088 */ unsigned long Highest;
  /* 0x008c */ long ParkLock;
  /* 0x0090 */ unsigned long NonParkedSet;
  /* 0x0094 */ long __PADDING__[11];
} KNODE, *PKNODE; /* size: 0x00c0 */

typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0004 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0008 */

typedef struct _DISPATCHER_HEADER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned char Type;
      union
      {
        /* 0x0001 */ unsigned char TimerControlFlags;
        struct /* bitfield */
        {
          /* 0x0001 */ unsigned char Absolute : 1; /* bit position: 0 */
          /* 0x0001 */ unsigned char Wake : 1; /* bit position: 1 */
          /* 0x0001 */ unsigned char EncodedTolerableDelay : 6; /* bit position: 2 */
        }; /* bitfield */
        /* 0x0001 */ unsigned char Abandoned;
        struct
        {
          /* 0x0001 */ unsigned char Signalling;
          union
          {
            /* 0x0002 */ unsigned char ThreadControlFlags;
            struct /* bitfield */
            {
              /* 0x0002 */ unsigned char CycleProfiling : 1; /* bit position: 0 */
              /* 0x0002 */ unsigned char CounterProfiling : 1; /* bit position: 1 */
              /* 0x0002 */ unsigned char GroupScheduling : 1; /* bit position: 2 */
              /* 0x0002 */ unsigned char AffinitySet : 1; /* bit position: 3 */
              /* 0x0002 */ unsigned char Reserved : 4; /* bit position: 4 */
            }; /* bitfield */
            /* 0x0002 */ unsigned char Hand;
            struct
            {
              /* 0x0002 */ unsigned char Size;
              union
              {
                /* 0x0003 */ unsigned char TimerMiscFlags;
                struct /* bitfield */
                {
                  /* 0x0003 */ unsigned char Index : 1; /* bit position: 0 */
                  /* 0x0003 */ unsigned char Processor : 5; /* bit position: 1 */
                  /* 0x0003 */ unsigned char Inserted : 1; /* bit position: 6 */
                  /* 0x0003 */ volatile unsigned char Expired : 1; /* bit position: 7 */
                }; /* bitfield */
                /* 0x0003 */ unsigned char DebugActive;
                /* 0x0003 */ unsigned char DpcActive;
              }; /* size: 0x0001 */
            }; /* size: 0x0002 */
          }; /* size: 0x0002 */
        }; /* size: 0x0003 */
      }; /* size: 0x0003 */
    }; /* size: 0x0004 */
    /* 0x0000 */ volatile long Lock;
    /* 0x0000 */ long LockNV;
  }; /* size: 0x0004 */
  /* 0x0004 */ long SignalState;
  /* 0x0008 */ struct _LIST_ENTRY WaitListHead;
} DISPATCHER_HEADER, *PDISPATCHER_HEADER; /* size: 0x0010 */

typedef struct _KQUEUE
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
  /* 0x0010 */ struct _LIST_ENTRY EntryListHead;
  /* 0x0018 */ volatile unsigned long CurrentCount;
  /* 0x001c */ unsigned long MaximumCount;
  /* 0x0020 */ struct _LIST_ENTRY ThreadListHead;
} KQUEUE, *PKQUEUE; /* size: 0x0028 */

typedef struct _EX_WORK_QUEUE
{
  /* 0x0000 */ struct _KQUEUE WorkerQueue;
  /* 0x0028 */ volatile unsigned long WorkItemsProcessed;
  /* 0x002c */ unsigned long WorkItemsProcessedLastPass;
  /* 0x0030 */ volatile long ThreadCount;
  /* 0x0034 */ volatile unsigned char TryFailed;
  /* 0x0035 */ char __PADDING__[3];
} EX_WORK_QUEUE, *PEX_WORK_QUEUE; /* size: 0x0038 */

typedef struct _KEVENT
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
} KEVENT, *PKEVENT; /* size: 0x0010 */

typedef struct _ENODE
{
  /* 0x0000 */ struct _KNODE Ncb;
  /* 0x00c0 */ struct _EX_WORK_QUEUE ExWorkerQueues[7];
  /* 0x0248 */ struct _KEVENT ExpThreadSetManagerEvent;
  /* 0x0258 */ struct _ETHREAD* ExpWorkerThreadBalanceManagerPtr;
  /* 0x025c */ unsigned long ExpWorkerSeed;
  union
  {
    struct /* bitfield */
    {
      /* 0x0260 */ volatile unsigned long ExWorkerFullInit : 1; /* bit position: 0 */
      /* 0x0260 */ volatile unsigned long ExWorkerStructInit : 1; /* bit position: 1 */
    }; /* bitfield */
    /* 0x0260 */ volatile unsigned long ExWorkerFlags;
  }; /* size: 0x0004 */
  /* 0x0264 */ long __PADDING__[7];
} ENODE, *PENODE; /* size: 0x0280 */

