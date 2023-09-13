FROM debian:11.4-slim as base

USER root

RUN apt-get update && apt-get install -y --no-install-recommends sudo

ARG UID=1000
ARG GID=1000

RUN groupadd -g "${GID}" user && \
    useradd --create-home --no-log-init -u "${UID}" -g "${GID}" user && \
    usermod -aG sudo user
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

COPY ./scripts/install_deps_ubuntu.sh /tmp/install_deps_ubuntu.sh
RUN /tmp/install_deps_ubuntu.sh

FROM base as buildenv

RUN /tmp/install_deps_ubuntu.sh --dev

COPY . /tex2scs-translator
RUN chown -R "${UID}:${GID}" /tex2scs-translator
WORKDIR /tex2scs-translator/scripts

ENV CCACHE_DIR=/ccache
RUN --mount=type=cache,target=/ccache/ ./make_all.sh

FROM base AS final

USER user

COPY --from=buildenv /tex2scs-translator /tex2scs-translator

ENTRYPOINT ["/bin/bash", "-c", "./tex2scs-translator/bin/scn-tex2scs -s /kb -t /kb-translated"]
