#!/bin/bash

if ! [ $BUILDOS ]
then
	export BUILDOS=1
	export PREFIX="$PWD/.."
	export TARGET=i686-elf
	export PATH="$PREFIX/bin:$PATH"
fi

