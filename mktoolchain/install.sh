#!/bin/bash

# getProcessorArch()
local arch=$(lscpu | head -n 1 | cut -d ' ' -f 2- | xargs)
