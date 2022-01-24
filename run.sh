set -xe

qemu-system-i386 -display gtk,zoom-to-fit=on -enable-kvm -m 512 -cdrom os.iso

