# disked
A NAS software for linux, work in progress.

# How to build
> [!TIP]
> If you don't have exactly 4 disks, use the provided disks.sh to generate 4 disks and set them up on loop.

Dependencies:
- CMake
- A C compiler.
- Bash or bash compatible shell.

Instructions:
Run the automatic build script which uses the CMakePresets.json:
`./build.sh`
The program should build and the output will be available in `out/build/gcc`

> [!CAUTION]
> This program is experimental and uses your disks.
> It is **HIGHLY** reccomended to use a virtual machine unless you know what you are doing.

