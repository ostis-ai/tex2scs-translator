FROM debian:11.4-slim as base

USER root

ARG UID=1000
ARG GID=1000

RUN apt-get update && apt-get install -y --no-install-recommends sudo

RUN groupadd -g "${GID}" user && \
    useradd --create-home --no-log-init -u "${UID}" -g "${GID}" user && \
    usermod -aG sudo user
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

COPY ./scripts/install_deps_ubuntu.sh /tmp/install_deps_ubuntu.sh
RUN /tmp/install_deps_ubuntu.sh --dev

FROM base as buildenv

COPY . /tex2scs-translator
RUN chown -R "${UID}:${GID}" /tex2scs-translator
WORKDIR /tex2scs-translator

ENV CCACHE_DIR=/ccache

# Explicitly set JAVA_HOME and add java to PATH
RUN export JAVA_HOME=$(/usr/lib/jvm/default-java) && export PATH=$PATH:$JAVA_HOME/bin

RUN --mount=type=cache,target=/ccache/ scripts/make_all.sh

FROM base AS final

USER user

COPY --from=buildenv /tex2scs-translator /tex2scs-translator
WORKDIR /tex2scs-translator

ENTRYPOINT ["/bin/bash", "-c", "bin/scn-tex2scs -d -c -s /kb -t /kb-translated"]
