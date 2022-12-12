FROM ubuntu
LABEL org.opencontainers.image.authors="joao.trindade@isel.pt"

USER root

RUN apt-get -qq -y update
RUN apt-get -qq -y upgrade
RUN apt-get -y autoclean
RUN apt-get -y autoremove
RUN rm -rf /var/lib/apt/lists/*

# Create user "tvs"
RUN useradd -m tvs
RUN cp /root/.bashrc /home/tvs/
RUN mkdir /home/tvs/work
RUN chown -R --from=root tvs /home/tvs

ENV HOME /home/tvs
WORKDIR ${HOME}/work
USER tvs
CMD ["/bin/bash"]
