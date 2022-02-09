# Welcome to Belvix Library's Documentation
You can use this API reference as manual, example codes are provided in some places
- [Predefined Macros](#Predefined-Macros)

<br>
<br>
<br>

# Predefined Macros
Predefined macros in belvixlib
- [Macros about compiler information](#Compiler)
- [Macros about platform & OS](#Platform)
- [Macros about system architecture](#Architecture)

<br>

## Compiler

`BV_COMPILER` is the detected compiler \
`BV_COMPILER_VERSION_STR` is the compiler's version in "major.minor.patch" format

| Compiler    | Macro                  |
|-------------|------------------------|
| GCC & MinGW | BV_COMPILER_GCC        |
| Clang       | BV_COMPILER_CLANG      |
| MSVC        | BV_COMPILER_MSVC       |
| Emscripten  | BV_COMPILER_EMSCRIPTEN |

## Platform

`BV_OS` is the detected platform \
`BV_OS_STR` ^ as string

| Platform        | Macro              | Notes                       |
|-----------------|--------------------|-----------------------------|
| Windows         | BV_OS_WINDOWS      | Both 64 and 32-bit Windows  |
| Linux           | BV_OS_LINUX        |                             |
| MacOS           | BV_OS_MACOS        |                             |
| iOS             | BV_OS_IOS          |                             |
| Android         | BV_OS_ANDROID      |                             |
| Unix            | BV_OS_UNIX         |                             |
| FreeBSD         | BV_OS_FREEBSD      |                             |
| NetBSD          | BV_OS_NETBSD       |                             |
| OpenBSD         | BV_OS_OPENBSD      |                             |
| DragonFlyBSD    | BV_OS_DRAGONFLYBSD |                             |
| AmigaOS         | BV_OS_AMIGAOS      | https://www.amigaos.net/    |
| AkarOS          | BV_OS_AKAROS       | http://akaros.org/news.html |
| Fuchsia OS      | BV_OS_FUCHSIA      | https://fuchsia.dev/        |
| Other (unknown) | BV_OS_UNKNOWN      |                             |

Example:
```c
#include "belvixlib.h"

void clear() {
    if (BV_OS == BV_OS_WINDOWS) {
        system("cls");
    }
    else if (BV_OS == BV_OS_LINUX) {
        system("clear);
    }
}

void print_os() {
    printf("This program is running on %s platform.", BV_OS_STR);
}
```

## Architecture

`BV_ARCH` is the detected architecture \
`BV_ARCH_STR` ^ as string

| Architecture   | Macro          |
|----------------|----------------|
| x86_64 (amd64) | BV_ARCH_X86_64 |
| x86            | BV_ARCH_X86_32 |
| ARM            | BV_ARCH_ARM    |