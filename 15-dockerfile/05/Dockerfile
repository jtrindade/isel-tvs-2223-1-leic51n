FROM ubuntu
LABEL org.opencontainers.image.authors="joao.trindade@isel.pt"

USER root

RUN apt-get -qq -y update && \
    apt-get -qq -y upgrade && \
    apt-get -y autoclean && \
    apt-get -y autoremove && \
    rm -rf /var/lib/apt/lists/*

# Create user "tvs"
RUN useradd -m tvs && \
    cp /root/.bashrc /home/tvs/ && \
    mkdir /home/tvs/work && \
    chown -R --from=root tvs /home/tvs

RUN sleep 2
RUN echo 1
RUN sleep 2
RUN echo 2
RUN sleep 2
RUN echo 3
RUN sleep 2
RUN echo 4

ENV HOME /home/tvs
WORKDIR ${HOME}/work
USER tvs
CMD ["/bin/bash"]
