FROM randomdude/gcc-cross-x86_64-elf

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y nasm
RUN apt-get install -y xorriso
RUN apt-get install -y grub-pc-bin
RUN apt-get install -y grub-common
RUN apt-get install -y build-essential
RUN apt-get install -y git
RUN apt-get install -y bison
RUN apt-get install -y flex
RUN apt-get install -y libgmp3-dev
RUN apt-get install -y libmpc-dev
RUN apt-get install -y libmpfr-dev
RUN apt-get install -y texinfo
RUN apt-get install -y mtools
RUN apt-get install -y qemu-system-i386
RUN apt-get install -y dosfstools


VOLUME /root/env
WORKDIR /root/env