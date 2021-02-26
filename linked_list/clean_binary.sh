#!/bin/bash

ls -l | grep "\-rwxrwxr\-x" | awk '{print $9}' | xargs rm