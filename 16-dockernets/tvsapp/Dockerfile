FROM ubuntu-net

RUN apt -y install --no-install-recommends npm nodejs

WORKDIR /opt/isel/tvsapp
COPY src/* ./

RUN npm install

ENV NODE_PORT 2345
EXPOSE $NODE_PORT
CMD ["node", "tvsapp.js"]
