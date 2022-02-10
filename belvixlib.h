/*

    belvixlib.h - A general-purpose, portable utility library
    https://github.com/kadir014/belvixlib
    MIT © Kadir Aksoy

*/

#pragma once
#ifndef BELVIXLIB_H
#define BELVIXLIB_H

#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>


typedef unsigned short bv_ushort;
typedef unsigned int bv_uint;
typedef unsigned long bv_ulong;
typedef unsigned long long bv_ullong;


#define __BV_STR(x) #x
#define BV_STR(x) __BV_STR(x)


#define BELVIXLIB_VERSION_MAJOR 0
#define BELVIXLIB_VERSION_MINOR 0
#define BELVIXLIB_VERSION_PATCH 1
#define BELVIXLIB_VERSION_STR               \
        BV_STR(BELVIXLIB_VERSION_MAJOR) "." \
        BV_STR(BELVIXLIB_VERSION_MINOR) "." \
        BV_STR(BELVIXLIB_VERSION_PATCH)


/**
 * 
 * Compiler information
 * 
 */

enum {
    BV_COMPILER_GCC,
    BV_COMPILER_CLANG,
    BV_COMPILER_MSVC,
    BV_COMPILER_EMSCRIPTEN
};

#if defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW64__)
#define BV_COMPILER BV_COMPIlER_GCC
#define BV_COMPILER_VERSION_STR    \
        BV_STR(__GNUC__) "."       \
        BV_STR(__GNUC_MINOR__) "." \
        BV_STR(__GNUC_PATCHLEVEL__)

#elif defined(__clang__)
#define BV_COMPILER BV_COMPILER_CLANG
#define BV_COMPILER_VERSION_STR     \
        BV_STR(__clang_major_) "."  \
        BV_STR(__clang_minor__) "." \
        BV_STR(__clang_patchlevel__)

#elif defined(_MSC_VER)
#define BV_COMPILER BV_COMPILER_MSVC
#define BV_COMPILER_VERSION_STR BV_STR(_MSC_VER)

#elif defined(__EMSCRIPTEN__)
#define BV_COMPILER BV_COMPILER_EMSCRIPTEN
#define BV_COMPILER_VERSION_STR          \
        BV_STR(__EMSCRIPTEN_major__) "." \
        BV_STR(__EMSCRIPTEN_minor__) "." \
        BV_STR(__EMSCRIPTEN_tiny__)

#endif


/**
 * 
 * Platform information
 * 
 */

enum {
  BV_OS_UNKNOWN,
  BV_OS_WINDOWS,
  BV_OS_LINUX,
  BV_OS_MACOS,
  BV_OS_IOS,
  BV_OS_FREEBSD,
  BV_OS_NETBSD,
  BV_OS_OPENBSD,
  BV_OS_DRAGONFLYBSD,
  BV_OS_AMIGAOS,
  BV_OS_ANDROID,
  BV_OS_AKAROS,
  BV_OS_FUCHSIA,
  BV_OS_UNIX
};

#if defined(_WIN32) || defined(__WIN32__) || defined(__WINDOWS__)
#define BV_OS BV_OS_WINDOWS
#define BV_OS_STR "Windows"

#elif defined(__linux__) && !defined(__ANDROID__)
#define BV_OS BV_OS_LINUX
#define BV_OS_STR "Linux"

#elif defined(__APPLE__) || defined(__MACH__)
#include <TargetConditionals.h>
#if TARGET_OS_IPHONE
#define BV_OS BV_OS_IOS
#define BV_OS_STR "iOS"
#elif TARGET_OS_MAC
#define BV_OS BV_OS_MACOS
#define BV_OS_STR "MacOS"
#endif

#elif defined(__FreeBSD__)
#define BV_OS BV_OS_FREEBSD
#define BV_OS_STR "FreeBSD"

#elif defined(__NetBSD__)
#define BV_OS BV_OS_NETBSD
#define BV_OS_STR "NetBSD"

#elif defined(__OpenBSD__)
#define BV_OS BV_OS_OPENBSD
#define BV_OS_STR "OpenBSD"

#elif defined(__DragonFly__)
#define BV_OS BV_OS_DRAGONFLYBSD
#define BV_OS_STR "DragonFlyBSD"

#elif defined(__amigaos__)
#define BV_OS BV_OS_AMIGAOS
#define BV_OS_STR "AmigaOS"

#elif defined(__ANDROID__)
#define BV_OS BV_OS_ANDROID
#define BV_OS_STR "Android"

#elif defined(__ros__)
#define BV_OS BV_OS_AKAROS
#define BV_OS_STR "AkarOS"

#elif defined(__Fuchsia__)
#define BV_OS BV_OS_FUCHSIA
#define BV_OS_STR "Fuchsia"

#elif defined(__unix__) || defined(__unix)
#define BV_OS BV_OS_UNIX
#define BV_OS_STR "Unix"

#else
#define BV_OS BV_OS_UNKNOWN
#define BV_OS_STR "Unknown"

#endif


/**
 *
 * Architecture information
 * 
 */

enum {
    BV_ARCH_X86_64,
    BV_ARCH_X86_32
};

#if defined(__x86_64) || \
    defined(__x86_64) || \
    defined(__amd64)  || \
    defined(__amd64__)
#define BV_ARCH BV_ARCH_X86_64
#define BV_ARCH_STR "x86_64"

#elif defined(i386)     || \
      defined(__i386)   || \
      defined(__i386__) || \
      defined(_X86_)    || \
      defined(__I86__)
#define BV_ARCH BV_ARCH_X86_32
#define BV_ARCH_STR "x86_32"

#elif defined(__arm__)     || \
      defined(__arm64)     || \
      defined(__aarch64__)
#define BV_ARCH BV_ARCH_ARM
#define BV_ARCH_STR "ARM"

#endif


/**
 * 
 * Date & time utilities
 * 
 */

/**
 * @brief Date & Time struct
 * 
 * @param year Year
 * @param month Month
 * @param day Day
 * @param hour Hour
 * @param minute Minute
 * @param second Second
 */
typedef struct {
    bv_ushort year;
    bv_ushort month;
    bv_ushort day;
    bv_ushort hour;
    bv_ushort minute;
    bv_ushort second;
} bv_DateTime;

/**
 * @brief bv_DateTime constructor
 * 
 * @param year Year
 * @param month Month
 * @param day Day
 * @param hour Hour
 * @param minute Minute
 * @param second Second
 * 
 * @return bv_DateTime instance
 */
bv_DateTime bv_DateTime_new(
            bv_ushort year,
            bv_ushort month,
            bv_ushort day,
            bv_ushort hour,
            bv_ushort minute,
            bv_ushort second) {

    bv_DateTime datetime = {
        .year = year,
        .month = month,
        .day = day,
        .hour = hour,
        .minute = minute,
        .second = second
    };

    return datetime;
}

/**
 * @brief Construct by_DateTime from Unix timestamp
 * 
 * @param timestamp Unix timestamp
 * @return bv_DateTime instance
 */
bv_DateTime bv_DateTime_from_unix(bv_ulong timestamp) {
    struct tm tm = *gmtime(&timestamp);

    bv_DateTime datetime = {
        .year = tm.tm_year + 1900,
        .month = tm.tm_mon + 1,
        .day = tm.tm_mday,
        .hour = tm.tm_hour,
        .minute = tm.tm_min,
        .second = tm.tm_sec
    };

    return datetime;
}

/**
 * @brief Construct by_DateTime from current system time
 * 
 * @return bv_DateTime instance
 */
bv_DateTime bv_DateTime_now() {
    return bv_DateTime_from_unix(time(NULL));
}

/**
 * @brief Add two bv_DateTime objects
 * 
 * @param dt1 First bv_DateTime object
 * @param dt2 Second bv_DateTime object
 * @return bv_DateTime instance
 */
bv_DateTime bv_DateTime_add(bv_DateTime dt1, bv_DateTime dt2) {
    bv_DateTime result = {
        .year = 0,
        .month = 0,
        .day = 0,
        .hour = 0,
        .minute = 0,
        .second = 0
    };

    bv_ushort second = dt1.second + dt2.second;
    bv_ushort second_r = second % 60;
    
    bv_ushort minute = dt1.minute + dt2.minute;
    if (second >= 60) minute++;
    bv_ushort minute_r = minute % 60;

    bv_ushort hour = dt1.hour + dt2.hour;
    if (minute >= 60) hour++;
    bv_ushort hour_r = hour % 24;

    bv_ushort day = dt1.day + dt2.day;
    if (hour >= 24) day++;
    bv_ushort day_r = day % 30;
    
    bv_ushort month = dt1.month + dt2.month;
    if (day >= 30) month++;
    bv_ushort month_r = month % 12;

    bv_ushort year = dt1.year + dt2.year;
    if (month >= 12) year++;

    result.second = second_r;
    result.minute = minute_r;
    result.hour = hour_r;
    result.day = day_r;
    result.month = month_r;
    result.year = year;

    return result;
}

/**
 * @brief Checks if two bv_DateTime objects are equal
 * 
 * @param dt1 First bv_DateTime object
 * @param dt2 Second bv_DateTime object
 * @return bool
 */
bool bv_DateTime_is_equal(bv_DateTime dt1, bv_DateTime dt2) {
    if (dt1.year == dt2.year     ||
        dt1.month == dt2.month   ||
        dt1.day == dt2.day       ||
        dt1.hour == dt2.hour     ||
        dt1.minute == dt2.minute ||
        dt1.second == dt2.second)
        return true;
    return false;
}

/**
 * @brief Checks if a bv_DateTime object is less than other
 * 
 * @param dt1 Left-hand bv_DateTime object
 * @param dt2 Right-hand bv_DateTime object
 * @return bool
 */
bool bv_DateTime_lt(bv_DateTime dt1, bv_DateTime dt2) {
    if (dt1.year < dt2.year) return true;
    else if (dt1.year > dt2.year) return false;
    else {
        if (dt1.month < dt2.month) return true;
        else if (dt1.month > dt2.month) return false;
        else {
            if (dt1.day < dt2.day) return true;
            else if (dt1.day > dt2.day) return false;
            else {
                if (dt1.hour < dt2.hour) return true;
                else if (dt1.hour > dt2.hour) return false;
                else {
                    if (dt1.minute < dt2.minute) return true;
                    else if (dt1.minute > dt2.minute) return false;
                    else {
                        if (dt1.second < dt2.second) return true;
                        else return false;
                    }
                }
            }
        }
    }
}

/**
 * @brief Checks if a bv_DateTime object is greater than other
 * 
 * @param dt1 Left-hand bv_DateTime object
 * @param dt2 Right-hand bv_DateTime object
 * @return bool
 */
bool bv_DateTime_gt(bv_DateTime dt1, bv_DateTime dt2) {
    if (dt1.year > dt2.year) return true;
    else if (dt1.year < dt2.year) return false;
    else {
        if (dt1.month > dt2.month) return true;
        else if (dt1.month < dt2.month) return false;
        else {
            if (dt1.day > dt2.day) return true;
            else if (dt1.day < dt2.day) return false;
            else {
                if (dt1.hour > dt2.hour) return true;
                else if (dt1.hour < dt2.hour) return false;
                else {
                    if (dt1.minute > dt2.minute) return true;
                    else if (dt1.minute < dt2.minute) return false;
                    else {
                        if (dt1.second > dt2.second) return true;
                        else return false;
                    }
                }
            }
        }
    }
}


/**
 *
 * Extra mathematical utilities
 * 
 */

const double BV_INV_PI     = 0.31830988618379067;
const double BV_INV_SQRTPI = 0.56418958354775628;
const double BV_SQRT3      = 1.73205080756887729;
const double BV_INV_SQRT2  = 0.70710678118654752;
const double BV_INV_SQRT3  = 0.57735026918962576;
const double BV_PHI        = 1.61803398874989485;

/**
 * @brief Convert angle from radians to degrees
 * 
 * @param radians Angle in radians
 * @return Angle in degrees
 */
double bv_deg(double radians) {
    return radians * (180.0 / M_PI);
}

/**
 * @brief Convert angle from degrees to radians
 * 
 * @param degrees Angle in degrees
 * @return Angle in radians 
 */
double bv_rad(double degrees) {
    return degrees * (M_PI / 180.0);
}

/**
 * @brief Convert angle from radians to degrees
 * 
 * @param radians Angle in radians
 * @return Angle in degrees
 */
float bv_degf(float radians) {
    return radians * (180.0 / M_PI);
}

/**
 * @brief Convert angle from degrees to radians
 * 
 * @param degrees Angle in degrees
 * @return Angle in radians 
 */
float bv_radf(float degrees) {
    return degrees * (M_PI / 180.0);
}

/**
 * @brief Convert angle from radians to degrees
 * 
 * @param radians Angle in radians
 * @return Angle in degrees
 */
long double bv_degl(long double radians) {
    return radians * (180.0 / M_PI);
}

/**
 * @brief Convert angle from degrees to radians
 * 
 * @param degrees Angle in degrees
 * @return Angle in radians 
 */
long double bv_radl(long double degrees) {
    return degrees * (M_PI / 180.0);
}

/**
 * @brief Calculate factorial of x
 * 
 * @param x Number to calculate factorial
 * @return Result of factorial
 */
bv_uint bv_fact(bv_uint x) {
    if (x == 0) return 1;
    return x * bv_fact(x - 1);
}

/**
 * @brief Calculate factorial of x
 * 
 * @param x Number to calculate factorial
 * @return Result of factorial
 */
bv_ulong bv_lfact(bv_ulong x) {
    if (x == 0) return 1;
    return x * bv_lfact(x - 1);
}

/**
 * @brief Calculate factorial of x
 * 
 * @param x Number to calculate factorial
 * @return Result of factorial
 */
bv_ullong bv_llfact(bv_ullong x) {
    if (x == 0) return 1;
    return x * bv_llfact(x - 1);
}

/**
 * @brief Calculate C(n, k) which is n! / (k! * (n - k)!)
 * 
 * @param n
 * @param k
 * @return Result of combination
 */
bv_uint bv_comb(bv_uint n, bv_uint k) {
    return bv_fact(n) / (bv_fact(k) * bv_fact(n - k));
}

/**
 * @brief Calculate C(n, k) which is n! / (k! * (n - k)!)
 * 
 * @param n
 * @param k
 * @return Result of combination
 */
bv_ulong bv_lcomb(bv_ulong n, bv_ulong k) {
    return bv_lfact(n) / (bv_lfact(k) * bv_lfact(n - k));
}

/**
 * @brief Calculate C(n, k) which is n! / (k! * (n - k)!)
 * 
 * @param n
 * @param k
 * @return Result of combination
 */
bv_ullong bv_llcomb(bv_ullong n, bv_ullong k) {
    return bv_llfact(n) / (bv_llfact(k) * bv_llfact(n - k));
}

/**
 * @brief Calculate P(n, k) which is n! / (n - k)!
 * 
 * @param n 
 * @param k 
 * @return Result of permutation
 */
bv_uint bv_perm(bv_uint n, bv_uint k) {
    return bv_fact(n) / bv_fact(n - k);
}

/**
 * @brief Calculate P(n, k) which is n! / (n - k)!
 * 
 * @param n 
 * @param k 
 * @return Result of permutation
 */
bv_ulong bv_lperm(bv_ulong n, bv_ulong k) {
    return bv_lfact(n) / bv_lfact(n - k);
}

/**
 * @brief Calculate P(n, k) which is n! / (n - k)!
 * 
 * @param n 
 * @param k 
 * @return Result of permutation
 */
bv_ullong bv_llperm(bv_ullong n, bv_ullong k) {
    return bv_llfact(n) / bv_llfact(n - k);
}


#endif