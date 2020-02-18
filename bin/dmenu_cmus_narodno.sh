#!/bin/bash

song=$(ls ~/Music/Narodnjaci | grep .mp3  | tr '[:upper:]' '[:lower:]' )
run=$(echo -n "$song" | rofi -show -dmenu -width 60  -lines 8)

cmus-remote -C "/$run" && cmus-remote -C win-activate
