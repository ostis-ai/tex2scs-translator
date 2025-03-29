#!/usr/bin/env bash
set -eo pipefail

function usage() {
  cat <<USAGE
Usage: $0 [--dev]

Options:
  --dev:          installs dependencies required to compile tex2scs-translator
USAGE
  exit 1
}

packagelist_runtime=(
    libboost-program-options-dev
    libboost-filesystem-dev
)

packagelist_dev=(
    gcc
    g++
    make
    cmake
    antlr4
    ccache
    default-jre
)

packages=() 
packages+=("${packagelist_runtime[@]}")

while [ "$1" != "" ]; do
  case $1 in
  --dev)
    packages+=("${packagelist_dev[@]}")
    ;;
  -h | --help)
    usage # show help
    ;;
  *)
    usage
    exit 1
    ;;
  esac
  shift 1 # remove the current value for `$1` and use the next
done

if ! command -v apt> /dev/null 2>&1;
then
  RED='\033[22;31m'
  NC='\033[0m' # No Color
  echo -e "${RED}[ERROR] Apt command not found. Debian-based distros are the only officially supported.
Please install the following packages by yourself:
  ${packages[*]}"
  exit 1
fi

sudo apt-get update

sudo apt-get install -y --no-install-recommends "${packages[@]}"
sudo apt autoremove

echo "Java installed at: $JAVA_HOME"
java -version # Verify installation.
