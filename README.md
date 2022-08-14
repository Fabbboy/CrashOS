# CrashOS

## Informations
A OS created in C and Assembly with [Crashcrafter](https://github.com/Crashcrafter)

The Repo is private on his Profile


## Usage
<h2>1) Build the Floppy:</h2>

This step is only needed if you're building the project the first time

You need either a [Docker container](https://github.com/Fabbboy/CrashOS/blob/master/DockerEnv/Dockerfile) or run it on a Linux operating system
After run:
```
sh setup.sh
```
<h2>2) Connect to Docker container and/or run following commands in Linux terminal:</h2>

**(IMPORTANT: You should be in the root of the project /CrashOs/)**
```
sh run.sh
```
This should build the Floppy into /CrashOS/build/

<h2>3) Run the Floppy using QEMU:</h2>

This step is only needed if you are using Docker. Otherwise this step is automatically executed in "run.sh".

**!!IMPORTANT: You have to execute this command outside of the Container in your normal terminal!!**

```
qemu-system-i386 -fda build/main_floppy.img
```
