#!/bin/bash

set -xe

. ./setupenv.sh

cp williamos.bin ./isodir/boot/
cp grub.cfg ./isodir/boot/grub/
grub-mkrescue -o os.iso isodir

