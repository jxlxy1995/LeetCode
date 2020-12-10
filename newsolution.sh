#!/bin/bash

if [ $# -ne 2 ]
then
    echo "must have NO and title, total 2 params!"
    exit 1
fi

dir=$1.$2

if [ -d $dir ]; then
    echo $dir" already exist"
    exit 1
fi

mkdir $dir

cp src.template $dir/$1.cpp
touch $dir/README.md

echo "----------create "$dir" success!----------"

exit 0