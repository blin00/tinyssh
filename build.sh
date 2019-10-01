#!/bin/sh

export PATH=$HOME/android/ndk/toolchains/llvm/prebuilt/linux-x86_64/bin:$PATH
CC=armv7a-linux-androideabi19-clang AR=arm-linux-androideabi-ar ./make-tinyssh.sh
arm-linux-androideabi-strip build/bin/tinyssh*
