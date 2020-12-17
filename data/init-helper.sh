#!/bin/bash

REPOROOT=$(git rev-parse --show-toplevel)

ln -sf "$REPOROOT/data/config" "$REPOROOT/helper/data/config"
