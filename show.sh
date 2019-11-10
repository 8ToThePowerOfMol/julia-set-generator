#!/bin/bash

# For animation, best works with juliaset.ppm opened with photo viewer

for i in `seq 10 50`; do
    ./a.out 100 1.2 1.2 0.$i -0.4 1
    sleep 0.5
done;
