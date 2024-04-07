#!/bin/bash
echo "Searching in stash: $stash"
git stash show -p stash@{$stash} | grep -q "$filename"
if [ $? -eq 0 ]; then
    echo "File found in stash $stash"
fi
