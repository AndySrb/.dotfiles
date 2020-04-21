#!/bin/bash


song=$(cat ~/bin/cmus/temp | tr '[:upper:]' '[:lower:]' )
run=$(echo -n "$song" | rofi -show -dmenu -width 60  -lines 8)

if [$run == '']
then
	break;
else
	cmus-remote -C "/${run}" && cmus-remote -C win-activate
fi




