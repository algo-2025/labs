#!/bin/bash

while read prefix repo branch; do
    echo "Добавляем лабораторную $prefix... $prefix из $repo ($branch)"
    git subtree add --prefix="$prefix" "$repo" "$branch" --squash
done < .subtrees

