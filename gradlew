#!/usr/bin/env bash

# Gradle wrapper script - download Gradle if not present
set -e

GRADLE_VERSION="8.2"
GRADLE_HOME=${GRADLE_HOME:-$HOME/.gradle}
GRADLE_URL="https://services.gradle.org/distributions/gradle-${GRADLE_VERSION}-bin.zip"

if [ ! -d "$GRADLE_HOME/gradle-$GRADLE_VERSION" ]; then
    mkdir -p "$GRADLE_HOME"
    cd "$GRADLE_HOME"
    wget "$GRADLE_URL"
    unzip "gradle-${GRADLE_VERSION}-bin.zip"
fi

exec "$GRADLE_HOME/gradle-$GRADLE_VERSION/bin/gradle" "$@"
