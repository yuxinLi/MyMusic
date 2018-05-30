#!/bin/bash
export TMPDIR=E:/lyx/FFmpeg/tmpdir
NDK=E:/lyx/tools_pro/android-ndk-r15c
SYSROOT=$NDK/platforms/android-18/arch-arm
TOOLCHAIN=$NDK/toolchains/arm-linux-androideabi-4.9/prebuilt/windows-x86_64
CPU=arm
PREFIX=E:/lyx/FFmpeg/output/$CPU


ADDI_CFLAGS="-Os -fpic -marm"


function build_one
{
./configure \
--prefix=$PREFIX \
--enable-shared \
--enable-static \
--enable-asm \
--enable-neon \
--disable-doc \
--disable-ffmpeg \
--disable-ffplay \
--disable-ffprobe \
--disable-ffserver \
--disable-doc \
--disable-symver \
--enable-pthreads \
--enable-small \
--enable-jni \
--enable-mediacodec \
--enable-runtime-cpudetect \
--cross-prefix=$TOOLCHAIN/bin/arm-linux-androideabi- \
--target-os=android \
--arch=arm \
--enable-cross-compile \
--sysroot=$SYSROOT \
--extra-cflags="$ADDI_CFLAGS" \
--extra-ldflags="$ADDI_LDFLAGS" \
$ADDITIONAL_CONFIGURE_FLAG
make clean
make
make install
}
build_one


read -p "Press any key to continue."