#ifndef WM_DATA_H
#define WM_DATA_H

/****************************************************************
 * 
 * Links washing options with time durations in minutes
 * Parameters order:
 *  Programm: ECO (Eco 40-60), COTT (Cotton), SYNT (Syntetic), SOFT (Soft), WOOL (Wool/ Hand washing)
 *  Load: 25 (1,5kg), 50 (3kg), 100 (6kg)
 *  Temperature: 40C (40C deg), 60C (60C deg), 90C (90C deg)
 *  Quick: 0 (no), 1 (yes)
 * 
 * *************************************************************/

enum TIME_TABLE
{
    // Grouped by programm
    ECO_

    COTT_

    SYNT_

    SOFT_

    WOOL_

};

#endif // WM_DATA_H
