FROM ubuntu:latest

RUN apt-get update -y
RUN apt-get install -y make g++ libcurl4-openssl-dev

COPY . /usr/src/twitbot
WORKDIR /usr/src/twitbot
RUN cp /usr/src/twitbot/bin/libtwitcurl.so /usr/lib/libtwitcurl.so
RUN make

CMD ["/bin/bash"]