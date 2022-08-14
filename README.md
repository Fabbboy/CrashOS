# <h1>CrashOS</h1>
<tt>Made by Crashcrafter and Fabboy</tt>
<hr></hr>

## Informations
A OS created in C and Assembly with [Crashcrafter](https://github.com/Crashcrafter)

The Repo is private on his Profile

## Setup
<h3>1) Download the project</h3>
This step is self-explanatory
<h3>2) Setup the Machine</h3>

**You need Linux**

**DOCKER**:
 1. Setup the Container:
 (The [Dockerfile](https://github.com/Fabbboy/CrashOS/blob/master/DockerEnv/Dockerfile) is located at: CrashOS/DockerEnv/)
 To Setup the Container run:
 ```
 docker build ./DockerEnv -t os-buildenv
 ```
 2. Connect to machine
 3. Run ````setup.sh```` file

**LINUX**:
Just run the ````setup.sh```` file


## Usage

**DOCKER**:
 1.  Connect to machine. 
 ````
 #I'm using this on Mac this could be diffrent depending on the OS.
 docker run --rm -it -v "${pwd}:/root/env" os-buildenv
 ````
 3.  Run the ````run.sh```` file
 4.  Exit machine
 5.  Run:
 ````
 qemu-system-i386 -fda build/main_floppy.img
 ````
 
 **LINUX**:
 Run the ````run.sh```` file
 
 
