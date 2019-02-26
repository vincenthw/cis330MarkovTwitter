FROM ubuntu:latest

COPY . /usr/src/twitbot
WORKDIR /usr/src/twitbot

RUN apt-get update -y
RUN apt-get install -y make


RUN make
# RUN apt-get install -y libjsoncpp-dev

CMD ["./bot.txt"]