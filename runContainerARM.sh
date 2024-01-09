#!/bin/bash
docker run --init -it -d \
  --name liosam-onboard-container\
  -v /home/root/MapOutput:/LOAM/ \
  --network=host \
  liosam-onboard-image \
  bash

