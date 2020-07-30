#!/bin/bash
if [ ! -d native-libs/libsigma ]; then
    grep url .gitmodules | sed 's/.*= //' | while read url; do git clone $url native-libs/libsigma; done
fi