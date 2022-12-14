FROM ubuntu-net

ENV TVSAPPDIR /opt/isel/tvsapp
ENV NODE_PORT 2345

RUN mkdir -p $TVSAPPDIR
COPY src/* $TVSAPPDIR/

WORKDIR $TVSAPPDIR
RUN apt -qqq -y install --no-install-recommends npm nodejs && npm install

EXPOSE $NODE_PORT
CMD ["node", "tvsapp.js"]
