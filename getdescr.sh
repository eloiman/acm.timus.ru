#/bin/bash
#set -vex
TASK=$1
URL="http://acm.timus.ru/problem.aspx?space=1&num=$TASK"
mkdir $TASK && cd $TASK
wget $URL -q -O descr.html
