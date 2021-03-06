typedef union _PPM_POLICY_SETTINGS_MASK
{
  union
  {
    /* 0x0000 */ unsigned __int64 Value;
    struct
    {
      struct /* bitfield */
      {
        /* 0x0000 */ unsigned long PerfDecreaseTime : 1; /* bit position: 0 */
        /* 0x0000 */ unsigned long PerfIncreaseTime : 1; /* bit position: 1 */
        /* 0x0000 */ unsigned long PerfDecreasePolicy : 1; /* bit position: 2 */
        /* 0x0000 */ unsigned long PerfIncreasePolicy : 1; /* bit position: 3 */
        /* 0x0000 */ unsigned long PerfDecreaseThreshold : 1; /* bit position: 4 */
        /* 0x0000 */ unsigned long PerfIncreaseThreshold : 1; /* bit position: 5 */
        /* 0x0000 */ unsigned long PerfMinPolicy : 1; /* bit position: 6 */
        /* 0x0000 */ unsigned long PerfMaxPolicy : 1; /* bit position: 7 */
        /* 0x0000 */ unsigned long PerfTimeCheck : 1; /* bit position: 8 */
        /* 0x0000 */ unsigned long PerfBoostPolicy : 1; /* bit position: 9 */
        /* 0x0000 */ unsigned long PerfBoostMode : 1; /* bit position: 10 */
        /* 0x0000 */ unsigned long AllowThrottling : 1; /* bit position: 11 */
        /* 0x0000 */ unsigned long PerfHistoryCount : 1; /* bit position: 12 */
        /* 0x0000 */ unsigned long ParkingPerfState : 1; /* bit position: 13 */
        /* 0x0000 */ unsigned long LatencyHintPerf : 1; /* bit position: 14 */
        /* 0x0000 */ unsigned long LatencyHintUnpark : 1; /* bit position: 15 */
        /* 0x0000 */ unsigned long CoreParkingMinCores : 1; /* bit position: 16 */
        /* 0x0000 */ unsigned long CoreParkingMaxCores : 1; /* bit position: 17 */
        /* 0x0000 */ unsigned long CoreParkingDecreasePolicy : 1; /* bit position: 18 */
        /* 0x0000 */ unsigned long CoreParkingIncreasePolicy : 1; /* bit position: 19 */
        /* 0x0000 */ unsigned long CoreParkingDecreaseTime : 1; /* bit position: 20 */
        /* 0x0000 */ unsigned long CoreParkingIncreaseTime : 1; /* bit position: 21 */
        /* 0x0000 */ unsigned long CoreParkingOverUtilizationThreshold : 1; /* bit position: 22 */
        /* 0x0000 */ unsigned long CoreParkingDistributeUtility : 1; /* bit position: 23 */
        /* 0x0000 */ unsigned long CoreParkingConcurrencyThreshold : 1; /* bit position: 24 */
        /* 0x0000 */ unsigned long CoreParkingHeadroomThreshold : 1; /* bit position: 25 */
        /* 0x0000 */ unsigned long CoreParkingDistributionThreshold : 1; /* bit position: 26 */
        /* 0x0000 */ unsigned long IdleAllowScaling : 1; /* bit position: 27 */
        /* 0x0000 */ unsigned long IdleDisable : 1; /* bit position: 28 */
        /* 0x0000 */ unsigned long IdleTimeCheck : 1; /* bit position: 29 */
        /* 0x0000 */ unsigned long IdleDemoteThreshold : 1; /* bit position: 30 */
        /* 0x0000 */ unsigned long IdlePromoteThreshold : 1; /* bit position: 31 */
      }; /* bitfield */
      struct /* bitfield */
      {
        /* 0x0004 */ unsigned long HeteroDecreaseTime : 1; /* bit position: 0 */
        /* 0x0004 */ unsigned long HeteroIncreaseTime : 1; /* bit position: 1 */
        /* 0x0004 */ unsigned long HeteroDecreaseThreshold : 1; /* bit position: 2 */
        /* 0x0004 */ unsigned long HeteroIncreaseThreshold : 1; /* bit position: 3 */
        /* 0x0004 */ unsigned long Class0FloorPerformance : 1; /* bit position: 4 */
        /* 0x0004 */ unsigned long Class1InitialPerformance : 1; /* bit position: 5 */
        /* 0x0004 */ unsigned long EnergyPerfPreference : 1; /* bit position: 6 */
        /* 0x0004 */ unsigned long AutonomousActivityWindow : 1; /* bit position: 7 */
        /* 0x0004 */ unsigned long AutonomousMode : 1; /* bit position: 8 */
        /* 0x0004 */ unsigned long DutyCycling : 1; /* bit position: 9 */
        /* 0x0004 */ unsigned long FrequencyCap : 1; /* bit position: 10 */
        /* 0x0004 */ unsigned long ThreadPolicy : 1; /* bit position: 11 */
        /* 0x0004 */ unsigned long ShortThreadPolicy : 1; /* bit position: 12 */
        /* 0x0004 */ unsigned long IdleStateMax : 1; /* bit position: 13 */
        /* 0x0004 */ unsigned long Spare : 18; /* bit position: 14 */
      }; /* bitfield */
    }; /* size: 0x0008 */
  }; /* size: 0x0008 */
} PPM_POLICY_SETTINGS_MASK, *PPPM_POLICY_SETTINGS_MASK; /* size: 0x0008 */

typedef enum _KHETERO_CPU_POLICY
{
  KHeteroCpuPolicyAll = 0,
  KHeteroCpuPolicyLarge = 1,
  KHeteroCpuPolicyLargeOrIdle = 2,
  KHeteroCpuPolicySmall = 3,
  KHeteroCpuPolicySmallOrIdle = 4,
  KHeteroCpuPolicyDynamic = 5,
  KHeteroCpuPolicyStaticMax = 5,
  KHeteroCpuPolicyBiasedSmall = 6,
  KHeteroCpuPolicyBiasedLarge = 7,
  KHeteroCpuPolicyDefault = 8,
  KHeteroCpuPolicyMax = 9,
} KHETERO_CPU_POLICY, *PKHETERO_CPU_POLICY;

typedef struct _PPM_ENGINE_SETTINGS
{
  /* 0x0000 */ union _PPM_POLICY_SETTINGS_MASK ExplicitSetting[2];
  /* 0x0010 */ unsigned char ThrottlingPolicy;
  /* 0x0014 */ unsigned long PerfTimeCheck;
  /* 0x0018 */ unsigned char PerfHistoryCount[2];
  /* 0x001a */ unsigned char PerfMinPolicy[2];
  /* 0x001c */ unsigned char PerfMaxPolicy[2];
  /* 0x001e */ unsigned char PerfDecreaseTime[2];
  /* 0x0020 */ unsigned char PerfIncreaseTime[2];
  /* 0x0022 */ unsigned char PerfDecreasePolicy[2];
  /* 0x0024 */ unsigned char PerfIncreasePolicy[2];
  /* 0x0026 */ unsigned char PerfDecreaseThreshold[2];
  /* 0x0028 */ unsigned char PerfIncreaseThreshold[2];
  /* 0x002c */ unsigned long PerfFrequencyCap[2];
  /* 0x0034 */ unsigned long PerfBoostPolicy;
  /* 0x0038 */ unsigned long PerfBoostMode;
  /* 0x003c */ unsigned long PerfReductionTolerance;
  /* 0x0040 */ unsigned long EnergyPerfPreference;
  /* 0x0044 */ unsigned long AutonomousActivityWindow;
  /* 0x0048 */ unsigned char AutonomousPreference;
  /* 0x0049 */ unsigned char LatencyHintPerf[2];
  /* 0x004b */ unsigned char LatencyHintUnpark[2];
  /* 0x004d */ unsigned char DutyCycling;
  /* 0x004e */ unsigned char ParkingPerfState[2];
  /* 0x0050 */ unsigned char DistributeUtility;
  /* 0x0051 */ unsigned char CoreParkingOverUtilizationThreshold;
  /* 0x0052 */ unsigned char CoreParkingConcurrencyThreshold;
  /* 0x0053 */ unsigned char CoreParkingHeadroomThreshold;
  /* 0x0054 */ unsigned char CoreParkingDistributionThreshold;
  /* 0x0055 */ unsigned char CoreParkingDecreasePolicy;
  /* 0x0056 */ unsigned char CoreParkingIncreasePolicy;
  /* 0x0058 */ unsigned long CoreParkingDecreaseTime;
  /* 0x005c */ unsigned long CoreParkingIncreaseTime;
  /* 0x0060 */ unsigned char CoreParkingMinCores[2];
  /* 0x0062 */ unsigned char CoreParkingMaxCores[2];
  /* 0x0064 */ unsigned char AllowScaling;
  /* 0x0065 */ unsigned char IdleDisabled;
  /* 0x0068 */ unsigned long IdleTimeCheck;
  /* 0x006c */ unsigned char IdleDemotePercent;
  /* 0x006d */ unsigned char IdlePromotePercent;
  /* 0x006e */ unsigned char IdleStateMax;
  /* 0x006f */ unsigned char HeteroDecreaseTime;
  /* 0x0070 */ unsigned char HeteroIncreaseTime;
  /* 0x0071 */ unsigned char HeteroDecreaseThreshold[32];
  /* 0x0091 */ unsigned char HeteroIncreaseThreshold[32];
  /* 0x00b1 */ unsigned char Class0FloorPerformance;
  /* 0x00b2 */ unsigned char Class1InitialPerformance;
  /* 0x00b4 */ enum _KHETERO_CPU_POLICY ThreadPolicies[2];
  /* 0x00bc */ long __PADDING__[1];
} PPM_ENGINE_SETTINGS, *PPPM_ENGINE_SETTINGS; /* size: 0x00c0 */

