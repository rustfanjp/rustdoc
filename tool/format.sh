#!/bin/sh

find *\.html -type f | xargs sed -i -e 's/<html lang="en">/<html lang="ja">/g'
