FROM debian:11.4-slim as base

USER root

RUN apt update && apt install -y --no-install-recommends libboost-program-options-dev


FROM debian:11.4-slim as buildenv

RUN apt update && apt install -y --no-install-recommends gcc g++ make cmake antlr4 libboost-program-options-dev ccache

COPY . /tex2scs-translator

WORKDIR /tex2scs-translator/src/grammar
RUN antlr4 -o ../translator/ SCnTex.g4 -no-listener -no-visitor -encoding UTF8

WORKDIR /tex2scs-translator/scripts

ENV CCACHE_DIR=/ccache
RUN --mount=type=cache,target=/ccache/ ./make_all.sh


FROM base AS final

COPY --from=buildenv /tex2scs-translator /tex2scs-translator

ENTRYPOINT ["/bin/bash", "-c", "/tex2scs-translator/bin/scn-tex2scs -s /kb/source/ -t /kb/kb.bin/"]
