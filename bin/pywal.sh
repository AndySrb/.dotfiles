#!/bin/bash

rm ~/.Xdefaults && wal -i "$@" && cp ~/bin/pywal/.Xdefaults ~/ && cat ~/.cache/wal/colors.Xresources >> ~/.Xdefaults


