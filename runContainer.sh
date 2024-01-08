#!/bin/bash
docker run --init -it -d \
  --name liosam-onboard-container\
  -v /etc/localtime:/etc/localtime:ro \
  -v /etc/timezone:/etc/timezone:ro \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  -v ~/Desktop/MapOutput:/LOAM/ \
  liosam-onboard-image \
  bash
