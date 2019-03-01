FROM ubuntu:latest
RUN apt-get update -y
RUN apt-get install -y libcurl4-openssl-dev git make g++
RUN git clone https://github.com/swatkat/twitcurl.git
RUN make ./twitcurl/twitterClient
RUN apt-get install -y libjsoncpp-dev
COPY . /Twitbot
WORKDIR /Twitbot
RUN make
RUN ./twitterTest