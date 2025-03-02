# tex2scs-translator

tex2scs-translator is a tool for translating sc.n-represented *.tex files into *.scs files.

## Quick Start

1. Clone the repository:

```sh
git clone https://github.com/ostis-ai/tex2scs-translator.git
cd tex2scs-translator
```

2. Choose an installation method:

   - Native (Debian-based distros only):

     ```sh
     # Install dependencies
     ./scripts/install_deps_ubuntu.sh --dev
     # Build the translator
     ./scripts/make_all.sh
     ```

   - Docker:

     ```sh
     # Build the Docker image
     docker build --build-arg UID="${UID}" --build-arg GID="${GID}" -t tex2scs:latest .
     ```

## Usage

1. Native:

   ```sh
   # Translate files
   ./bin/scn-tex2scs -d -c -s <path to folder with scn-tex sources> -t <target folder for translated sc.s-sources>
   ```

2. Docker:

   **NOTE:** If you don't want to change ownership of translated files, create the output directory (e.g., `./kb-translated`) before running this command.

   ```sh
   # Translate files
   docker run --rm -ti -v ${PWD}/kb/docs/sc-network:/kb -v ${PWD}/kb-translated:/kb-translated tex2scs:latest
   ```

## Feedback

Contributions, bug reports, and feature requests are welcome!

Feel free to check our [issues page](https://github.com/ostis-ai/tex2scs-translator/issues) and file a new issue (or comment on existing ones).

## License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/ostis-ai/tex2scs-translator/blob/main/LICENSE) file for details.
