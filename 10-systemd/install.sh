#!/bin/bash

ECHOD_EXE=./echod
ECHOD_SRC=./echod.c

if [ ! -x $ECHOD_EXE ]; then
	if [ ! -f $ECHOD_SRC ]; then
		echo Wrong directory
	else
		echo Run make before install
	fi
	exit
fi

ECHOD_DIR=/opt/isel/tvs/echod/bin
SYSTD_DIR=/etc/systemd/system

mkdir -p $ECHOD_DIR

if [ ! -d $ECHOD_DIR ]; then
	echo Failed to create $ECHOD_DIR
	exit
fi	

cp $ECHOD_EXE $ECHOD_DIR
cp ./echod.socket  $SYSTD_DIR
cp ./echod.service $SYSTD_DIR

if [ -x $ECHOD_DIR/$ECHOD_EXE ] && [ -f $SYSTD_DIR/echod.socket ] && [ -f $SYSTD_DIR/echod.service ]; then
	systemctl enable echod.socket
else
	echo Failed to copy echod files
	exit
fi


