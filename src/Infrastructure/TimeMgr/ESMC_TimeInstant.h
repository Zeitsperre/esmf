// $Id: ESMC_TimeInstant.h,v 1.1 2002/08/18 23:22:49 eschwab Exp $
#ifndef ESMC_TIME_INSTANT_H
#define ESMC_TIME_INSTANT_H

#include <ESMC_Types.h>
#include <ESMC_Time.h>

class ESMC_TimeInterval;
class ESMC_Calendar;

class ESMC_TimeInstant : public ESMC_Time
{
//-------------------------------------------------------------------------
//BOP
//
// !CLASS: ESMC_TimeInstant
//
// !SUPERCLASSES:
//	ESMC_Time
//
// !AGGREGATE CLASSES:
//
// !ASSOCIATE CLASSES:
//	ESMC_Calendar
//
// !FRIEND CLASSES:
	friend class ESMC_Calendar;
//
// !PUBLIC DATA MEMBERS:
//
// !PUBLIC MEMBER FUNCTIONS:

  public:

    ESMC_TimeInstant(void);
	ESMC_TimeInstant(int64 S, int32 Sn, int32 Sd, ESMC_Calendar *Cal,
					 int Timezone);
    ~ESMC_TimeInstant(void);

	int Init(int64 S, int32 Sn, int32 Sd, ESMC_Calendar *Cal, int Timezone);
    int Init(const char *TimeList, ...);

	// for persistence/checkpointing
	int Dump(int64 *S, int32 *Sn, int32 *Sd);

	// for testing/debugging
	int Dump(void);

    // all get/set routines perform signed conversions, where applicable;
    //   direct, one-to-one access to core time elements is provided by the
    //   ESMC_Time base class

    // generic interface -- via variable argument lists
    //   can map to F90 named-optional-arguments interface

    int Get(const char *TimeList, ...);    // e.g. Get("YRMMDD", (int *)YR,
                                           //         (int *)MM, (int *)DD);
    int Set(const char *TimeList, ...);    // e.g. Set("s" , (double) s);

    int Get_O(int *O);
    int Set_O(int  O);

    int GetCalendar(ESMC_Calendar *Calendar);
    int GetDayOfYear(double *DayOfYear);  // frequent need ?? make property

    int GetDayOfWeek(int *DayOfWeek);     // frequent need ?? make property

    // frequent need ?? make property
    int GetMiddleOfMonth(ESMC_TimeInstant *MiddleOfMonth);

    // standalone method, not class method
    //  (see ESMC_Clock::SyncToWallClock() ) ??
    int GetRealTime(ESMC_TimeInstant *RealTime);

    // return in string format
    int GetString(char *Ts);

    // shortcut interfaces
    int Get_YR_MM_DD_S(int32 *YR, int *MM, int *DD, int *S);
    int Set_YR_MM_DD_S(int32  YR, int  MM, int  DD, int  S);

    int Get_YR_MM_DD_H_M_S(int32 *YR, int *MM, int *DD, int *H, int *M, int *S);
    int Set_YR_MM_DD_H_M_S(int32  YR, int  MM, int  DD, int  H, int  M, int  S);

// !DESCRIPTION:
//
// !BUGS:
//
// !SEE ALSO:
//
// !REVISION HISTORY:
//
//  10Jun02   Earl Schwab  Initial code.
//
//EOP
//-------------------------------------------------------------------------
  private:

	// 3 representations; any 1 determines the other 2
	// (S, Sn, Sd) ESMC_Time base class
	// (D)         Julian date (absolute days)
	// (YR, MM, DD, O) Gregorian 

    ESMC_Calendar *Calendar;    // associated calendar
	int Timezone;				// Offset from GMT
};

#endif // ESMC_TIME_INSTANT_H
