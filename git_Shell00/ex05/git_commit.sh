#!/bin/bash
git log --pretty=format:"%H" -n 5 | awk '1'
