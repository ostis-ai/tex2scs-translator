# Tex2SCs-translator

Tex2SCs-translator is a tool for translating SCn-represented *.tex files into SCs-represented *.scs files.

## Quick start

## Installation

  There are two available options to use this translator:
  
  1. Native (Debian based distros support only)
  ```sh
  # install dependencies
  ./install_deps_ubuntu.sh [--dev]
  # build translator
  ./scripts/make_all.sh
  ```

  2. Docker
  ```sh
  # build image
  docker build --build-arg UID="${UID}" --build-arg GID="${GID}" -t tex2scs:latest .
  ```
  
## Usage

  1. Native
  ```sh
  # translate files
  ./bin/scn-tex2scs -d -c -s <path to folder with scn-tex sources> -t <target folder for translated scs sources>
  ```
  
  2. Docker
  **NOTE: if you wouldn't like to change ownership of translated files then create output directory (e.g. ./kb-translated) before running this command.**
  ```sh
  # translate files
  docker run --rm -ti -v ${PWD}/kb/docs/sc-network:/kb -v ${PWD}/kb-translated:/kb-translated tex2scs:latest
  ```

## Feedback

Contributions, bug reports and feature requests are welcome!
Feel free to check our [issues page](https://github.com/ostis-ai/tex2scs-translator/issues) and file a new issue (or comment in existing ones).
