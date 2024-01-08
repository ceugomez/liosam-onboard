#!/bin/bash
docker run --init -it -d \
  --name liosam-onboard-container-arm\
  -v /home/root/MapOutput:/LOAM/ \
  liosam-onboard-image-arm \
  bash
