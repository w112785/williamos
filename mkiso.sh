#!/bin/bash

set -xe

. ./setupenv.sh

mkdir -p ./isodir/boot/grub

cp williamos.bin ./isodir/boot/
cp grub.cfg ./isodir/boot/grub/
grub-mkrescue -o os.iso isodir

