#!/bin/bash
max=50000
for((i=0;i<$max;i++)); do 
      if(i=0); then
            echo $max
      else
            echo "abaaaaaaaa"
      fi
done | ./run.out
