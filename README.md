# CrashOS

## Informations
A OS created in C and Assembly with [Crashcrafter](https://github.com/Crashcrafter)

The Repo is private on his Profile


## Usage
1) Build the Floppy:
You need either a [Docker container](https://github.com/Fabbboy/CrashOS/blob/master/DockerEnv/Dockerfile) or run it on a Linux operating system
After run:
```
sh setup.sh
```
2) Connect to Docker container and/or run following commands in Linux terminal:
**(IMPORTANT: You should be in the root of the project /CrashOs/)**
```
sh run.sh
```
This should build the Floppy into /CrashOS/build/
3) Run the Floppy using QEMU:
(If you're using a Docker container you have to run the QEMU command outside of the Container)
(The build dir is located in the root folder: /CrashOS/build/)
```
qemu-system-i386 -fda build/main_floppy.img
```
